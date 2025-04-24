#include "gui_def.h"
#include "main_frame.h"

class WndEDA : public wxApp
{
public:
    // Constructor
    WndEDA();
    // Destructor
    ~WndEDA();

    virtual bool OnInit() override;

private:
    MainFrame* m_pMainFrame;
};

