///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIFRAME_H__
#define __GUIFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
#include <wx/stattext.h>
#include <wx/listctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/splitter.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

#define idMenuQuit 1000
#define idMenuAbout 1001

///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame 
{
	private:
	
	protected:
		wxMenuBar* mbar;
		wxMenu* fileMenu;
		wxMenu* helpMenu;
		wxStatusBar* statusBar;
		wxToolBar* m_toolBar1;
		wxToolBarToolBase* m_tool1; 
		wxToolBarToolBase* m_tool2; 
		wxToolBarToolBase* m_tool3; 
		wxSplitterWindow* m_splitter1;
		wxPanel* m_panel1;
		wxStaticText* m_staticText1;
		wxListCtrl* m_listCtrl2;
		wxPanel* m_panel2;
		wxPanel* m_panelForGL;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnQuit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAbout( wxCommandEvent& event ) { event.Skip(); }
		virtual void openFolder( wxCommandEvent& event ) { event.Skip(); }
		virtual void openFile( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("mjesus"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 758,521 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUIFrame();
		
		void m_splitter1OnIdle( wxIdleEvent& )
		{
			m_splitter1->SetSashPosition( 150 );
			m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( GUIFrame::m_splitter1OnIdle ), NULL, this );
		}
	
};

#endif //__GUIFRAME_H__
