/***************************************************************
 * Name:      mjesusMain.h
 * Purpose:   Defines Application Frame
 * Author:    pepe (garciapepe1010@gmail.com)
 * Created:   2017-06-04
 * Copyright: pepe (none)
 * License:
 **************************************************************/

#ifndef MJESUSMAIN_H
#define MJESUSMAIN_H



#include "mjesusApp.h"


#include "GUIFrame.h"

class mjesusFrame: public GUIFrame
{
    public:
        mjesusFrame(wxFrame *frame);
        ~mjesusFrame();
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
};

#endif // MJESUSMAIN_H
