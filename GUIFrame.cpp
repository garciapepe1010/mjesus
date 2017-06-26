///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Feb 16 2016)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif //WX_PRECOMP

#include "GUIFrame.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	mbar = new wxMenuBar( 0 );
	fileMenu = new wxMenu();
	wxMenuItem* menuFileQuit;
	menuFileQuit = new wxMenuItem( fileMenu, idMenuQuit, wxString( wxT("&Quit") ) + wxT('\t') + wxT("Alt+F4"), wxT("Quit the application"), wxITEM_NORMAL );
	fileMenu->Append( menuFileQuit );

	mbar->Append( fileMenu, wxT("&File") );

	helpMenu = new wxMenu();
	wxMenuItem* menuHelpAbout;
	menuHelpAbout = new wxMenuItem( helpMenu, idMenuAbout, wxString( wxT("&About") ) + wxT('\t') + wxT("F1"), wxT("Show info about this application"), wxITEM_NORMAL );
	helpMenu->Append( menuHelpAbout );

	mbar->Append( helpMenu, wxT("&Help") );

	this->SetMenuBar( mbar );

	statusBar = this->CreateStatusBar( 2, wxST_SIZEGRIP, wxID_ANY );
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );

	wxPNGHandler *handler = new wxPNGHandler;
    wxImage::AddHandler(handler);

	m_toolBar1 = new wxToolBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL );
	m_tool1 = m_toolBar1->AddTool( wxID_ANY, wxT("Open files"), wxBitmap( wxT("icons/folder30.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Open files"), wxT("Add folder"), NULL );

	m_tool2 = m_toolBar1->AddTool( wxID_ANY, wxT("Add image"), wxBitmap( wxT("icons/file30.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Add image"), wxT("Add image"), NULL );

	m_toolBar1->AddSeparator();

	m_tool3 = m_toolBar1->AddTool( wxID_ANY, wxT("Proccess"), wxBitmap( wxT("icons/proccess30.png"), wxBITMAP_TYPE_ANY ), wxNullBitmap, wxITEM_NORMAL, wxT("Proccess"), wxT("Proccess"), NULL );

	m_toolBar1->Realize();

	bSizer1->Add( m_toolBar1, 0, wxEXPAND, 5 );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter1->SetSashSize( 2 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( GUIFrame::m_splitter1OnIdle ), NULL, this );

	m_panel1 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( m_panel1, wxID_ANY, wxT("Images"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL, 5 );

	m_listCtrl2 = new wxListCtrl( m_panel1, wxID_ANY, wxDefaultPosition, wxSize(1000,1280 ), wxLC_ICON|wxHSCROLL|wxVSCROLL );

	int column_width =1000;
    m_listCtrl2->InsertColumn(0, L"ColumnText", wxLIST_FORMAT_LEFT, column_width);

	bSizer3->Add( m_listCtrl2, 0, wxALL, 5 );


	m_panel1->SetSizer( bSizer3 );
	m_panel1->Layout();
	bSizer3->Fit( m_panel1 );
	m_panel2 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_panelForGL = new wxPanel( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panelForGL->SetBackgroundColour( wxColour( 255, 255, 255 ) );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );


	m_panelForGL->SetSizer( bSizer5 );
	m_panelForGL->Layout();
	bSizer5->Fit( m_panelForGL );
	bSizer2->Add( m_panelForGL, 1, wxEXPAND | wxALL, 5 );


	m_panel2->SetSizer( bSizer2 );
	m_panel2->Layout();
	bSizer2->Fit( m_panel2 );
	m_splitter1->SplitVertically( m_panel1, m_panel2, 150 );
	bSizer1->Add( m_splitter1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Connect( menuFileQuit->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Connect( menuHelpAbout->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Connect( m_tool1->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::openFolder ) );
	this->Connect( m_tool2->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::openFile ) );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( GUIFrame::OnClose ) );
	this->Disconnect( idMenuQuit, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnQuit ) );
	this->Disconnect( idMenuAbout, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( GUIFrame::OnAbout ) );
	this->Disconnect( m_tool1->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::openFolder ) );
	this->Disconnect( m_tool2->GetId(), wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler( GUIFrame::openFile ) );

}
