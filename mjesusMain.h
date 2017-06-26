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
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>

class mjesusFrame: public GUIFrame
{
    public:
        mjesusFrame(wxFrame *frame);
        ~mjesusFrame();
        wxString CurrentDocPath;
        const char kPathSeparator =
        #ifdef _WIN32
                                    '\\';
        #else
                                    '/';
        #endif
    private:
        virtual void OnClose(wxCloseEvent& event);
        virtual void OnQuit(wxCommandEvent& event);
        virtual void OnAbout(wxCommandEvent& event);
        virtual void openFolder( wxCommandEvent& event);
		virtual void openFile( wxCommandEvent& event );
		int getdir (std::string dir, std::vector<std::string> &files);
};

#endif // MJESUSMAIN_H
