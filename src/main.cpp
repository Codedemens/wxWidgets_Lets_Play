
#include <wx/wxprec.h>

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

////////////////////////////////////////////////////////////
class MyApp : public wxApp
{
public:
    
    virtual bool OnInit() wxOVERRIDE;
};
////////////////////////////////////////////////////////////
class MyFrame : public wxFrame 
{
public:
    MyFrame(const wxString& title);

    void OnQuit(wxCommandEvent& event);
private:

    wxDECLARE_EVENT_TABLE();
};
////////////////////////////////////////////////////////////
enum {
    Minimal_Quit = wxID_EXIT
};
////////////////////////////////////////////////////////////
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(Minimal_Quit, MyFrame::OnQuit)
wxEND_EVENT_TABLE()
////////////////////////////////////////////////////////////
wxIMPLEMENT_APP(MyApp);
////////////////////////////////////////////////////////////
bool MyApp::OnInit() {
    if (!wxApp::OnInit()) return false;

    MyFrame* frame = new MyFrame("App");

    frame->Show(true);

    return true;

}
////////////////////////////////////////////////////////////
MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title) {

}
////////////////////////////////////////////////////////////
void MyFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
    Close(true);
}
