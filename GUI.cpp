///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetSize(1700, 800);
	this->SetTitle(_("Selective Image Desaturation"));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	OrgPicture = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	OrgPicture->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer2->Add( OrgPicture, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("Set Saturation"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer3->Add( m_staticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	SetSaturation = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	bSizer3->Add( SetSaturation, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Choose parameter"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxString ChoiceChoices[] = { wxT("Brightness"), wxT("Hue"), wxT("Red"), wxT("Green"), wxT("Blue"), wxT("Cyan"), wxT("Magenta"), wxT("Yellow") };
	int ChoiceNChoices = sizeof( ChoiceChoices ) / sizeof( wxString );
	Choice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ChoiceNChoices, ChoiceChoices, 0 );
	Choice->SetSelection( 0 );
	bSizer3->Add( Choice, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer3->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Set Value"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Value_Slider = new wxSlider( this, wxID_ANY, 127, 0, 255, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_VALUE_LABEL );
	bSizer3->Add( Value_Slider, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	Value_Text = new wxTextCtrl( this, wxID_ANY, wxT("127"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( Value_Text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer4->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	File = new wxMenu();
	wxMenuItem* Load_File;
	Load_File = new wxMenuItem( File, wxID_ANY, wxString( _("&Load") ) , wxEmptyString, wxITEM_NORMAL );
	File->Append( Load_File );

	File->AppendSeparator();

	wxMenuItem* Save_File;
	Save_File = new wxMenuItem( File, wxID_ANY, wxString( _("&Save") ) , wxEmptyString, wxITEM_NORMAL );
	File->Append( Save_File );

	m_menubar1->Append( File, _("&File") );

	Details = new wxMenu();
	wxMenuItem* About;
	About = new wxMenuItem( Details, wxID_ANY, wxString( _("&About") ) , wxEmptyString, wxITEM_NORMAL );
	Details->Append( About );

	m_menubar1->Append( Details, _("&Details") );

	this->SetMenuBar( m_menubar1 );


	this->Centre( wxBOTH );

	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::Frame_OnCLose ) );
	SetSaturation->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::SetSaturation_OnScrollThumbTrack ), NULL, this );
	Choice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::Choice_OnChoice ), NULL, this );
	Value_Slider->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Value_Slider_OnScrollThumbTrack ), NULL, this );
	Value_Text->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Value_Text_Changed ), NULL, this );
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::LoadFile ), this, Load_File->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::SaveFile ), this, Save_File->GetId());
	Details->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MyFrame1::AboutProject ), this, About->GetId());
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::Frame_OnCLose ) );
	SetSaturation->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::SetSaturation_OnScrollThumbTrack ), NULL, this );
	Choice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::Choice_OnChoice ), NULL, this );
	Value_Slider->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Value_Slider_OnScrollThumbTrack ), NULL, this );
	Value_Text->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::Value_Text_Changed ), NULL, this );

}
