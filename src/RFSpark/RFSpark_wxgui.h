/**
@file RFSpark_wxgui.h
@author Lime Microsystems
*/
#ifndef RF_SPARK_WXGUI_H
#define RF_SPARK_WXGUI_H

#include <wx/frame.h>
#include "lime/LimeSuite.h"
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
class wxStaticBoxSizer;
class wxComboBox;
class wxCheckBox;

#include <vector>

class RFSpark_wxgui: public wxFrame
{
	public:		
		struct ADCdata
		{
			unsigned char channel;
                        std::string units;
                        double value;
			/*unsigned char units;
			char powerOf10coefficient;
			short value;*/
		};

		struct ADCdataGUI
		{
			wxStaticText* title;
			wxStaticText* units;
			wxStaticText* powerOf10;
			wxStaticText* value;
		};

		RFSpark_wxgui(wxWindow* parent,wxWindowID id=wxID_ANY, const wxString& title=wxEmptyString, const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, long style = 0);
        virtual void Initialize(lms_device_t* pSerPort);
		virtual ~RFSpark_wxgui();

		wxButton* btnReadADC;
		wxButton* btnReadAllADC;
		wxComboBox* cmbADCselect;

	protected:
		static const int mADCcount = 32;
		static const long ID_BTNREADADC;
		static const long ID_BTNREADALLADC;
		static const long ID_BTNWRITEGPIO;
		static const long ID_BTNREADGPIO;
		static const long ID_CMBSELECTADC;
		std::vector<ADCdata> mADCdata;
		std::vector<ADCdataGUI> mADCgui;
		std::vector<wxCheckBox*> mGPIOboxes;

	private:
		void UpdateADClabels();
		void OnbtnRefreshAllADC(wxCommandEvent& event);
		void OnbtnRefreshADC(wxCommandEvent& event);
		void OnbtnWriteGPIO(wxCommandEvent& event);
		void OnbtnReadGPIO(wxCommandEvent& event);

	protected:
        lms_device_t* lmsControl;
		DECLARE_EVENT_TABLE()
};

#endif
