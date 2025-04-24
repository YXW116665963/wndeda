#include "main_frame.h"

MainFrame::MainFrame(const wxString& title)
          : wxFrame(nullptr, wxID_ANY, title)
{
    #if wxUSE_MENUBAR
    // create a menu bar
    wxMenu *fileMenu = new wxMenu;

    // the "About" item should be in the help menu
    wxMenu *helpMenu = new wxMenu;
    helpMenu->Append(WNDEDA_About, "&About\tF1", "Show about dialog");

    fileMenu->Append(WNDEDA_Quit, "E&xit\tAlt-X", "Quit this program");

    // now append the freshly created menu to the menu bar...
    wxMenuBar *menuBar = new wxMenuBar();
    menuBar->Append(fileMenu, "&File");
    menuBar->Append(helpMenu, "&Help");

    // ... and attach this menu bar to the frame
    SetMenuBar(menuBar);
#else // !wxUSE_MENUBAR
    // If menus are not available add a button to access the about box
    wxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    wxButton* aboutBtn = new wxButton(this, wxID_ANY, "About...");
    aboutBtn->Bind(wxEVT_BUTTON, &MyFrame::OnAbout, this);
    sizer->Add(aboutBtn, wxSizerFlags().Center());
    SetSizer(sizer);
#endif // wxUSE_MENUBAR/!wxUSE_MENUBAR

#if wxUSE_STATUSBAR
    // create a status bar just for fun (by default with 1 pane only)
    CreateStatusBar(2);
    SetStatusText("Welcome to wxWidgets!");
#endif // wxUSE_STATUSBAR


}

MainFrame::~MainFrame()
{
}

void MainFrame::OnQuit(wxCommandEvent &event)
{
    Close(true);
}

void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(wxString::Format
        (
           "Welcome to %s!\n"
           "\n"
           "This is the minimal wxWidgets sample\n"
           "running under %s.",
           wxVERSION_STRING,
           wxGetOsDescription()
        ),
        "About wxWidgets minimal sample",
        wxOK | wxICON_INFORMATION,
        this);
}

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
    EVT_MENU(WNDEDA_Quit,  MainFrame::OnQuit)
    EVT_MENU(WNDEDA_About, MainFrame::OnAbout)
wxEND_EVENT_TABLE()