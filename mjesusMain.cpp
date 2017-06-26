/***************************************************************
 * Name:      mjesusMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    pepe (garciapepe1010@gmail.com)
 * Created:   2017-06-04
 * Copyright: pepe (none)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "mjesusMain.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>
#include <wx/dirdlg.h>
#include <wx/stdpaths.h>


//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


mjesusFrame::mjesusFrame(wxFrame *frame)
    : GUIFrame(frame)
{
#if wxUSE_STATUSBAR
    statusBar->SetStatusText(_("Hello Code::Blocks user!"), 0);
    statusBar->SetStatusText(wxbuildinfo(short_f), 1);
#endif
}

mjesusFrame::~mjesusFrame()
{
}

void mjesusFrame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void mjesusFrame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void mjesusFrame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void mjesusFrame::openFolder( wxCommandEvent& event )
{
    std::vector<std::string> files = std::vector<std::string>();
    wxDirDialog* OpenDialog = new wxDirDialog( this, _("Choose a directory"),
		                 wxStandardPaths::Get().GetExecutablePath(), 0, wxDefaultPosition );

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		CurrentDocPath = OpenDialog->GetPath();
		getdir(std::string(CurrentDocPath.mb_str()),files);
		for (unsigned int i = 0;i < files.size();i++) {
            //cout << files[i] << endl;
            int image_index = 0;
            std::string tmp = std::string(CurrentDocPath.mb_str()) + kPathSeparator + files[i];
            wxString wxTmp(tmp.c_str(), wxConvUTF8);
            long list_index = m_listCtrl2->InsertItem(0, wxTmp, image_index);
        }

	}

	// Clean up after ourselves
	OpenDialog->Destroy();
}

void mjesusFrame::openFile( wxCommandEvent& event )
{
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString,wxT("BMP and GIF files (*.bmp;*.gif)|*.bmp;*.gif|PNG files (*.png)|*.png|JPG files (*.jpg)|*.jpg"), wxFD_OPEN, wxDefaultPosition);

	// Creates a "open file" dialog with 4 file types
	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "Cancel"
	{
		CurrentDocPath = OpenDialog->GetPath();
		int image_index = 0;
        long list_index = m_listCtrl2->InsertItem(0, CurrentDocPath , image_index);

	}

	// Clean up after ourselves
	OpenDialog->Destroy();
}

int mjesusFrame::getdir (std::string dir, std::vector<std::string> &files){
DIR *dp;
std::string compareString;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        std::cout << "Error(" << errno << ") opening " << dir << std::endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        compareString = dirp->d_name;
        if( strcmp(compareString.c_str(), ".") && strcmp(compareString.c_str(), "..") ){
            files.push_back(std::string(dirp->d_name));
        }

    }
    closedir(dp);
    return 0;
}
