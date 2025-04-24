#include <iostream>
#include "wndeda.h"

// using std::cout,std::endl;

WndEDA::WndEDA()
{
}

WndEDA::~WndEDA()
{
}

bool WndEDA::OnInit()
{
    if ( !wxApp::OnInit() )
        return false;

    SetVendorName("WndEDA");

    m_pMainFrame = new MainFrame(" wndEDA demo");
    m_pMainFrame->Show(true);
    // If we returned false here, the application would exit immediately.
    return true;
}

wxIMPLEMENT_APP(WndEDA);