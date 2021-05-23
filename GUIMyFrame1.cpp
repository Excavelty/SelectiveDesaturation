#include "GUIMyFrame1.h"
#include <cctype>
#include "CImg.h"
#include <thread>


GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{

}

bool check_if_no_digit(const std::string& str)
{
	auto iter = std::find_if(str.begin(), str.end(), [](char el) { return !std::isdigit(el); });
	return iter != str.end();
}

void GUIMyFrame1::Frame_OnCLose(wxCloseEvent& event)
{
	const wxString message = "Are you sure you want to exit?\nAll changes will be lost.";
	if (wxMessageDialog(NULL, message, "Warning!", wxOK | wxCANCEL).ShowModal() == wxID_OK)
		Destroy();
}

void GUIMyFrame1::OriginalImage_OnUpdateUI(wxUpdateUIEvent& event)
{
	// TODO: Implement OriginalImage_OnUpdateUI
	wxClientDC dcOrg(OriginalImage);
	if(should_refresh)
		firstRefresh(dcOrg);
}

void GUIMyFrame1::ValueText_OnTextEnter(wxCommandEvent& event)
{
	value_check();
}

//Funkcja obs³uguj¹ca guzik
void GUIMyFrame1::ApplyChanges_OnButtonClick(wxCommandEvent& event)
{
	wxClientDC applyDc(ResultImage); 
	//Poni¿ej przypisujemy do zmiennych w klasie parametry z wszystkich pozosta³ych narzêdzi
	selectedOption = Choice->GetSelection();
	blurParameter = SetBlur->GetValue();
	tresholdParameter = wxAtoi(Value_Text->GetValue());
	saturationParameter = SetSaturation->GetValue();
	//Wywo³anie funkcji modyfikuj¹cej obraz
	modifyImage();
	//Odœwie¿amy panel przeznaczony dla kopii obrazu 
	secondRefresh(applyDc);
}

//Ta funkcja s³uzy do odœwie¿ania panelu z kopi¹ obrazu po jakimkolwiek evencie
void GUIMyFrame1::ResultImage_OnUpdateUI(wxUpdateUIEvent& event)
{
	// TODO: Implement ResultImage_OnUpdateUI
	value_check();
	wxClientDC dcResult(ResultImage);
	if (should_refresh)
		secondRefresh(dcResult);
}

void GUIMyFrame1::LoadFile(wxCommandEvent& event)
{
	wxClientDC dc(OriginalImage); // Tworzymy obiekt DC
	//Poni¿ej dodanie handlerów dla kopii i orgina³u
	originalPhoto.AddHandler(new wxJPEGHandler); 
	copyPhoto.AddHandler(new wxJPEGHandler);
	//Wywo³anie okna dialogowego
	std::shared_ptr<wxFileDialog> window(new wxFileDialog(this, _("Choose a file"), _(""), _(""), "JPEG files (*.jpg)|*.jpg", wxFD_OPEN));
	//Warunek czy okienko siê poprawnie wyœwietli³o
	if (window->ShowModal() == wxID_OK) {
		//Je¿eli wyst¹pi³y problemy z wywo³aniem zdjêcia wyœwietlamy error
		if (!originalPhoto.LoadFile(window->GetPath(), wxBITMAP_TYPE_JPEG)) {
			wxLogError(_("Can't open a file!")); //w pliku GUI.h jest specjalny include
		}
		else {
			OriginalImage->Enable(true); //zabezpieczenie przed zapisaniem pustego zdjêcia
			copyPhoto = originalPhoto; //Kopiujemy orgina³
			should_refresh = true; //zmienna pomocnicza, okreœlaj¹ca czy powinniœmy rozpocz¹æ odœwie¿anie (umo¿liwiaj¹ce zmianê wielkoœci zdjêcia przy rozci¹ganiu 
			//okienka)
		}
	}
	firstRefresh(dc); //Odœwie¿amy panel z orgina³em
}

//Zapisanie pliku
void GUIMyFrame1::SaveFile(wxCommandEvent& event)
{
	//Poni¿ej sprawdzamy warunek, czy cokolwiek znajduje siê w panelu zdjêcia wynikowego. Panel jest odblokowany je¿eli coœ tam jest
	if (ResultImage->IsEnabled()) {
		//Ponownie tworzymy odpowiednie okno dialogowe
		std::shared_ptr<wxFileDialog> window(new wxFileDialog(this, _("Save file"), _(""), _(""), "JPEG files (*.jpg)|*.jpg", wxFD_SAVE));
		if (window->ShowModal() == wxID_OK) {
			//Jak siê nie uda zapisaæ wyskakuje error
			if (!copyPhoto.SaveFile(window->GetPath(), wxBITMAP_TYPE_JPEG)) {
				wxLogError(_("Can't save an image!"));
			}
		}
	}
	//Wypisujemy error, ¿e panel jest pusty
	else {
		wxLogError(_("Can't save an empty image!"));
	}
}

void GUIMyFrame1::AboutProject(wxCommandEvent& event)
{
	wxString about = "Selective Image Desaturation\n";
	about += "Computer Graphics Project\nMade by:\n";
	about += "Mateusz Barnacki\nWojciech Gomu\u0142ka\nBartosz Rogowski\n";
	about += "----------------------\n";
	about += "WFiIS IS AGH\n2020";
	about += "\n\nAll rights reserved.";
	wxMessageDialog(NULL, about, "About", wxOK).ShowModal();
}

//Poni¿ej dwie funkcje do odœwie¿ania paneli, u¿ycie bufferDC gwarantuje brak jakichkolwiek "przyciêæ" na zdjêciach w 
//trakcie ruszania myszk¹ lub innych czynnoœci

void GUIMyFrame1::firstRefresh(wxClientDC &dc)
{
	wxBufferedDC buffer(&dc);
	wxImage *temp;
	temp = new wxImage(originalPhoto);
	if (temp->IsOk()) {
		temp->Rescale(dc.GetSize().x, dc.GetSize().y);
		wxBitmap bitmap(*temp);
		buffer.DrawBitmap(bitmap, 0, 0);
	}
	delete temp;
}

void GUIMyFrame1::secondRefresh(wxClientDC &dc)
{
	wxBufferedDC buffer(&dc);
	wxImage *temp;
	temp = new wxImage(copyPhoto);
	if (temp->IsOk()) {
		temp->Rescale(dc.GetSize().x, dc.GetSize().y);
		wxBitmap bitmap(*temp);
		buffer.DrawBitmap(bitmap, 0, 0);
	}
	delete temp;
}


void GUIMyFrame1::value_check()
{
	if (Value_Text->GetValue().empty())
	{
		Validation_Text->SetLabel("Error! This field \ncannot be empty");
		ApplyChanges->Enable(false);
		return;
	}
	std::string val = Value_Text->GetValue().ToStdString();

	if (!check_if_no_digit(val))
	{
		try
		{
			int value = std::stoi(val);
			std::string choice_value = Choice->GetString(Choice->GetSelection()).ToStdString();
			if (choice_value != "Hue" && (value < 0 || value>255)) // Z mojej strony drobna uwaga, parametr Hue jest z przedzia³u [0, 360)
			{
				Validation_Text->SetLabel("Your input should be\nbetween 0 and 255!");
				ApplyChanges->Enable(false);
			}
			else if (choice_value == "Hue" && (value < 0 || value >= 360))
			{
				Validation_Text->SetLabel("Hue should be \nin range of [0, 360)!");
				ApplyChanges->Enable(false);
			}
			else
			{
				Validation_Text->SetLabel("Your input is correct!");
				ApplyChanges->Enable();
			}
		}
		catch (const std::invalid_argument&)
		{
			Validation_Text->SetLabel("Error! Invalid input.");
			ApplyChanges->Enable(false);
		}
		catch (const std::out_of_range&)
		{
			Validation_Text->SetLabel("Error! Value\nout of range.");
			ApplyChanges->Enable(false);
		}
		catch (const std::exception&)
		{
			Validation_Text->SetLabel("Error! Unhandled\nexeption occured.");
			ApplyChanges->Enable(false);
		}
	}

	else
	{
		Validation_Text->SetLabel("Error! Input contains\nno-digit symbols!");
		ApplyChanges->Enable(false);
	}
}

//Drugi Gauss z wiêkszym filtrem
void GUIMyFrame1::useGaussian2(int width_start, int width_end, int width, int height, unsigned char* org, unsigned char* copy) {
	int x, y, tempR, tempG, tempB, temp;
	//Poni¿ej filtr 5x5. Zastosowa³em wersjê œrodkow¹, wg mnie mocniejszy za bardzo rozmacuje obraz, mo¿na ew zmieniæ wartoœci na s³abszy
	std::array<unsigned char, 25> mask{ 0, 1, 2, 1, 0,
									    1, 4, 8, 4, 1,
									   2, 8, 16, 8, 2,
									    1, 4, 8, 4, 1,
									    0, 1, 2, 1, 0 };
	int allWeights = std::accumulate(mask.begin(), mask.end(), 0);
	for (x = width_start; x < width_end; ++x) {
		for (y = 2; y < height - 2; ++y) {
			for (unsigned char c = 0; c < 3; ++c) {
				temp = (mask.at(0) * copy[(y - 2)*width * 3 + (x - 2) * 3 + c]) + (mask.at(1) * copy[(y - 2)*width * 3 + (x - 1) * 3 + c]) + (mask.at(2) * copy[(y - 2)*width * 3 + x * 3 + c]) + (mask.at(3) * copy[(y - 2)*width * 3 + (x + 1) * 3 + c]) + (mask.at(4) * copy[(y - 2)*width * 3 + (x + 2) * 3 + c])
					+ (mask.at(5) * copy[(y - 1)*width * 3 + (x - 2) * 3 + c]) + (mask.at(6) * copy[(y - 1)*width * 3 + (x - 1) * 3 + c]) + (mask.at(7) * copy[(y - 1)*width * 3 + x * 3 + c]) + (mask.at(8) * copy[(y - 1)*width * 3 + (x + 1) * 3 + c]) + (mask.at(9) * copy[(y - 1)*width * 3 + (x + 2) * 3 + c])
					+ (mask.at(10) * copy[y*width * 3 + (x - 2) * 3 + c]) + (mask.at(11) * copy[y*width * 3 + (x - 1) * 3 + c]) + (mask.at(12) * copy[y*width * 3 + x * 3 + c]) + (mask.at(13) * copy[y*width * 3 + (x + 1) * 3 + c]) + (mask.at(14) * copy[y*width * 3 + (x + 2) * 3 + c])
					+ (mask.at(15) * copy[(y + 1)*width * 3 + (x - 2) * 3 + c]) + (mask.at(16) * copy[(y + 1)*width * 3 + (x - 1) * 3 + c]) + (mask.at(17) * copy[(y + 1)*width * 3 + x * 3 + c]) + (mask.at(18) * copy[(y + 1)*width * 3 + (x + 1) * 3 + c]) + (mask.at(19) * copy[(y + 1)*width * 3 + (x + 2) * 3 + c])
					+ (mask.at(20) * copy[(y + 2)*width * 3 + (x - 2) * 3 + c]) + (mask.at(21) * copy[(y + 2)*width * 3 + (x - 1) * 3 + c]) + (mask.at(22) * copy[(y + 2)*width * 3 + x * 3 + c]) + (mask.at(23) * copy[(y + 2)*width * 3 + (x + 1) * 3 + c]) + (mask.at(24) * copy[(y + 2)*width * 3 + (x + 2) * 3 + c]);
				temp = temp / allWeights;
				if (c == 0) {
					tempR = temp;
				}
				else if (c == 1) {
					tempG = temp;
				}
				else {
					tempB = temp;
				}
			}
			org[(y*width + x) * 3] = tempR;
			org[(y*width + x) * 3 + 1] = tempG;
			org[(y*width + x) * 3 + 2] = tempB;
		}
	}
}

void GUIMyFrame1::useGaussian2WithThreads(wxImage& object, int width, int height, int howManyThreads)
{

	wxImage* image;
	image = new wxImage(object.Copy());
	unsigned char* org = object.GetData();
	unsigned char* copy = image->GetData();

	std::vector<std::thread> threads;
	int thread_offset = (width - 4) / 4;
	int startArr = 2;
	int endArr = startArr + thread_offset;
	for (int i = 0; i < howManyThreads; ++i)
	{
		//https://stackoverflow.com/a/50654520
		threads.push_back(std::thread{ &GUIMyFrame1::useGaussian2, this, startArr, endArr, width, height, org, copy });
		startArr += thread_offset;
		endArr += thread_offset;
	}

	for (auto& thread : threads)
		thread.join();


	object = *image;
	org = nullptr;
	copy = nullptr;
	delete copy;
	delete org;
	delete image;
}

//Funkcja modyfikuj¹ca obraz
void GUIMyFrame1::modifyImage() {
	//Uaktywniamy panel kopii, poniewa¿ ju¿ jesteœmy pewni ¿e coœ tam bêdzie
	if (ResultImage->IsEnabled() == false) {
		ResultImage->Enable(true);
	}
	int height = originalPhoto.GetHeight();
	int width = originalPhoto.GetWidth();
	int temp = 0;
	int min = 0;
	int max = 0;
	int tempR = 0;
	int tempG = 0;
	int tempB = 0;
	int delta = 0;
	wxImage *tempImage;
	tempImage = new wxImage(originalPhoto.Copy());
	unsigned char *image = originalPhoto.GetData();
	unsigned char *copy = tempImage->GetData();
	int x, y;
	//Poni¿ej dla opcji bez konwersji na CMY
	if ((selectedOption >= 0) && (selectedOption < 5)) {
		for (int iter = 0; iter < width * height * 3; iter += 3) 
		{
				//Przypisujemy wyznaczon¹ wartoœæ dla odpowiedniej opcji
				if (selectedOption == 0)
					temp = calculateLighteness(image[iter], image[iter + 1], image[iter + 2]);
				else if (selectedOption == 1)
					temp = calculateHue(image[iter], image[iter + 1], image[iter + 2]);
				else if (selectedOption == 2)
					temp = static_cast<int>(image[iter]);
				else if (selectedOption == 3)
					temp = static_cast<int>(image[iter + 1]);
				else if (selectedOption == 4)
					temp = static_cast<int>(image[iter + 2]);
				//Sprawdzamy czy wartoœæ jest mniejsza ni¿ obszar 'przejœcia'
				if (temp < (tresholdParameter - blurParameter)) {
					//Wyznaczamy max z RGB
					max = findMax(image[iter], image[iter + 1], image[iter + 2]);
					if (max < 0) {
						max = 0;
					}
					//Dokonujemy czêœciowej desaturacji zale¿nie od parametru saturationParameter
					partlyDesaturation(copy[iter], copy[iter + 1], copy[iter + 2], max, saturationParameter);
				}
				//Je¿eli piksel znajduje siê w obszarze przejœciowym
				else if ((temp > tresholdParameter - blurParameter) && (temp < tresholdParameter)) {
					delta = tresholdParameter - temp; // Obliczamy o ile ró¿ni siê od progu
					max = findMax(image[iter], image[iter + 1], image[iter + 2]);
					//Funkcja która ma imitowaæ rozmycie
					blurDesaturation(copy[iter], copy[iter + 1], copy[iter + 2], max, saturationParameter, blurParameter, delta);
				}
		}
	}
	//Opcje wymagaj¹ce konwersji na CMY za pomoc¹ CImg
	else {
		//Utworzenie zwyczajnych zmiennych (analogiczne do wxImage)
		//cimg_library::CImg<unsigned char> object(width, height, 1, 3);
		cimg_library::CImg<unsigned char> result(width, height, 1, 3);
		//W poni¿szej pêtli przypisujemy odpowiednie wartoœci do poszczególnych pikseli odpowiednio (x,y,0) = R itd...
		for (x = 0; x < width; ++x) {
			for (y = 0; y < height; ++y) {
				result(x, y, 0) = image[(y*width + x) * 3];
				result(x, y, 1) = image[(y*width + x) * 3 + 1];
				result(x, y, 2) = image[(y*width + x) * 3 + 2];
			}
		}
		//W zmiennej result przechowujemy obraz po dokonaniu konwersji na CMY
		result.RGBtoCMY();
		for (x = 0; x < width; ++x) {
			for (y = 0; y < height; ++y) {
				//Sprawdzamy która opcja z CMY zosta³a wybrana
				if (selectedOption == 5) {
					temp = result(x, y, 0);
				}
				else if (selectedOption == 6) {
					temp = result(x, y, 1);
				}
				else if (selectedOption == 7) {
					temp = result(x, y, 2);
				}
				//Analogicznie jak dla RGB sprawdzamy poni¿ej, czy coœ jest w pe³ni desaturowane czy jest w obszarze przejœciowym
				if (temp < (tresholdParameter - blurParameter)) {
					max = findMax(result(x, y, 0), result(x, y, 1), result(x, y, 2));
					if (max < 0) {
						max = 0;
					}
					partlyDesaturation(result(x, y, 0), result(x, y, 1), result(x, y, 2), max, saturationParameter);
				}
				else if ((temp > tresholdParameter - blurParameter) && (temp < tresholdParameter)) {
					delta = tresholdParameter - temp;
					delta = saturationParameter + delta;
					if (delta > 100) {
						delta = 100;
					}
					max = findMax(result(x, y, 0), result(x, y, 1), result(x, y, 2));
					//partlyDesaturation(result(x, y, 0), result(x, y, 1), result(x, y, 2), max, delta);
					blurDesaturation(result(x, y, 0), result(x, y, 1), result(x, y, 2), max, saturationParameter, blurParameter, delta);
				}
			}
		}
		result.CMYtoRGB();
		//Zapisanie wyników w obiekcie wxImage
		for (x = 0; x < width; ++x) {
			for (y = 0; y < height; ++y) {
				copy[(y*width + x) * 3] = result(x, y, 0);
				copy[(y*width + x) * 3 + 1] = result(x, y, 1);
				copy[(y*width + x) * 3 + 2] = result(x, y, 2);
			}
		}
	}
	copyPhoto = *tempImage;
	image = nullptr;
	copy = nullptr;
	delete image;
	delete copy;
	delete tempImage;

	useGaussian2WithThreads(copyPhoto, width, height, 1);
}

