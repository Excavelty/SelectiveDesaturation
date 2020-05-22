#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__

/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/

#include "GUI.h"
#include <wx/wxprec.h>

//// end generated include

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
	protected:
		// Handlers for MyFrame1 events.

		//opens dialog window warning about losing all changes
		void Frame_OnCLose( wxCloseEvent& event );

		void SetSaturation_OnScrollThumbTrack( wxScrollEvent& event );
		void Choice_OnChoice( wxCommandEvent& event );
		void Value_Slider_OnScrollThumbTrack( wxScrollEvent& event );
		void Value_Text_Changed( wxCommandEvent& event );

		//loads file (via dialog window)
		void LoadFile( wxCommandEvent& event );

		//saves ready file (via dialog window)
		void SaveFile( wxCommandEvent& event );

		//opens dialog window showing project info
		void AboutProject( wxCommandEvent& event );

	public:
		/** Constructor */
		GUIMyFrame1( wxWindow* parent );
	//// end generated class members

};

#endif // __GUIMyFrame1__
