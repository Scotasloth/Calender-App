#include <wx/wx.h>
#include <wx/calctrl.h>

// Define the application class
class MyApp : public wxApp {  // Corrected 'puclic' to 'public'
public:
    virtual bool OnInit();  // Method to initialize the application
};

// Define the main frame class
class MyFrame : public wxFrame {  // Corrected 'myFrame' to 'MyFrame' for consistency
public:
    MyFrame(const wxString& title);  // Constructor declaration

private:
    void OnClose(wxCloseEvent& event);  // Event handler for closing the window
    wxCalendarCtrl* m_calendar;  // Pointer to the calendar control
};

// Implement the application
wxIMPLEMENT_APP(MyApp);

// Application initialization method
bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Calendar");  // Create a new frame instance
    frame->Show(true);  // Show the frame (corrected 'True' to 'true')
    return true;  // Return true to indicate successful initialization
}

// Frame constructor
MyFrame::MyFrame(const wxString& title) 
    : wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(400, 300)) {

    // Create a calendar control and add it to the frame
    m_calendar = new wxCalendarCtrl(this, wxID_ANY, wxDefaultDateTime, wxPoint(20, 20), wxSize(250, 200));

    // Bind the close event to the OnClose method
    Bind(wxEVT_CLOSE_WINDOW, &MyFrame::OnClose, this); 
}

// Close event handler
void MyFrame::OnClose(wxCloseEvent& event) {
    Destroy();  // Destroy the frame when the close event is triggered
}