///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetSize(1400, 680);
	this->SetTitle(_("Selective Image Desaturation"));

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer(wxHORIZONTAL);

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer(wxVERTICAL);

	OriginalImage = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	OriginalImage->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	OriginalImage->Enable(false);

	bSizer2->Add(OriginalImage, 1, wxEXPAND | wxALL, 5);


	bSizer1->Add(bSizer2, 1, wxEXPAND, 5);

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer(wxVERTICAL);

	Saturation_Text = new wxStaticText(this, wxID_ANY, wxT("Set Saturation"), wxDefaultPosition, wxDefaultSize, 0);
	Saturation_Text->Wrap(-1);
	bSizer3->Add(Saturation_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	SetSaturation = new wxSlider(this, wxID_ANY, 100, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
	bSizer3->Add(SetSaturation, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer3->Add(m_staticline1, 0, wxEXPAND | wxALL, 5);

	Choose_Text = new wxStaticText(this, wxID_ANY, wxT("Choose parameter"), wxDefaultPosition, wxDefaultSize, 0);
	Choose_Text->Wrap(-1);
	bSizer3->Add(Choose_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	wxString ChoiceChoices[] = { wxT("Lightness"), wxT("Hue"), wxT("Red"), wxT("Green"), wxT("Blue"), wxT("Cyan"), wxT("Magenta"), wxT("Yellow") };
	int ChoiceNChoices = sizeof(ChoiceChoices) / sizeof(wxString);
	Choice = new wxChoice(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, ChoiceNChoices, ChoiceChoices, 0);
	Choice->SetSelection(0);
	bSizer3->Add(Choice, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticline2 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer3->Add(m_staticline2, 0, wxEXPAND | wxALL, 5);

	SetValue_Text = new wxStaticText(this, wxID_ANY, wxT("Set Value"), wxDefaultPosition, wxDefaultSize, 0);
	SetValue_Text->Wrap(-1);
	bSizer3->Add(SetValue_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	Value_Text = new wxTextCtrl(this, wxID_ANY, wxT("127"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer3->Add(Value_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	Validation_Text = new wxStaticText(this, wxID_ANY, wxT("Your input is correct!"), wxDefaultPosition, wxDefaultSize, 0);
	Validation_Text->Wrap(-1);
	bSizer3->Add(Validation_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	m_staticline3 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
	bSizer3->Add(m_staticline3, 0, wxEXPAND | wxALL, 5);

	SetBlur_Text = new wxStaticText(this, wxID_ANY, wxT("Set Blur"), wxDefaultPosition, wxDefaultSize, 0);
	SetBlur_Text->Wrap(-1);
	bSizer3->Add(SetBlur_Text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	SetBlur = new wxSlider(this, wxID_ANY, 0, 0, 30, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL | wxSL_VALUE_LABEL);
	bSizer3->Add(SetBlur, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	ApplyChanges = new wxButton(this, wxID_ANY, wxT("Apply Changes"), wxDefaultPosition, wxDefaultSize, 0);
	bSizer3->Add(ApplyChanges, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	bSizer1->Add(bSizer3, 0, wxEXPAND, 5);

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer(wxVERTICAL);

	ResultImage = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	ResultImage->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_INFOBK));
	ResultImage->Enable(false);

	bSizer4->Add(ResultImage, 1, wxEXPAND | wxALL, 5);


	bSizer1->Add(bSizer4, 1, wxEXPAND, 5);


	this->SetSizer(bSizer1);
	this->Layout();
	m_menubar1 = new wxMenuBar(0);
	File = new wxMenu();
	wxMenuItem* Load_File;
	Load_File = new wxMenuItem(File, wxID_ANY, wxString(_("&Load")), wxEmptyString, wxITEM_NORMAL);
	File->Append(Load_File);

	File->AppendSeparator();

	wxMenuItem* Save_File;
	Save_File = new wxMenuItem(File, wxID_ANY, wxString(_("&Save")), wxEmptyString, wxITEM_NORMAL);
	File->Append(Save_File);

	m_menubar1->Append(File, _("&File"));

	Details = new wxMenu();
	wxMenuItem* About;
	About = new wxMenuItem(Details, wxID_ANY, wxString(_("&About")), wxEmptyString, wxITEM_NORMAL);
	Details->Append(About);

	m_menubar1->Append(Details, _("&Details"));

	this->SetMenuBar(m_menubar1);


	this->Centre(wxBOTH);

	// Connect Events
	this->Connect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame1::Frame_OnCLose));
	//OriginalImage->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::OriginalImage_OnUpdateUI), NULL, this);
	Value_Text->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(MyFrame1::ValueText_OnTextEnter), NULL, this);
	ApplyChanges->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::ApplyChanges_OnButtonClick), NULL, this);
	OriginalImage->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::OriginalImage_OnUpdateUI), NULL, this);
	ResultImage->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::ResultImage_OnUpdateUI), NULL, this);
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::LoadFile), this, Load_File->GetId());
	File->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::SaveFile), this, Save_File->GetId());
	Details->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler(MyFrame1::AboutProject), this, About->GetId());
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect(wxEVT_CLOSE_WINDOW, wxCloseEventHandler(MyFrame1::Frame_OnCLose));
	//OriginalImage->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::OriginalImage_OnUpdateUI), NULL, this);
	Value_Text->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(MyFrame1::ValueText_OnTextEnter), NULL, this);
	ApplyChanges->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(MyFrame1::ApplyChanges_OnButtonClick), NULL, this);
	ResultImage->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(MyFrame1::ResultImage_OnUpdateUI), NULL, this);

}