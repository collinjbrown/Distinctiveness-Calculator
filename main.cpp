// main.cpp
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <io.h>
#include <fcntl.h>
#include <codecvt>
using namespace std;

enum class Occlusivity { occlusive, continuant, vibrant };
enum class Sonorance { obstruent, sonorant };
enum class Egressivity { egressive, ingressive };
enum class Centrality { central, lateral };
enum class Nasality { oral, nasal };
enum class AirstreamMechanism { pulmonic, glottalic, lingual };
enum class BroadPlaceOfArticulation { labial, coronal, dorsal, radical, glottal };
enum class NarrowPlaceOfArticulation { bilabial, labiodental, dental, alveolar, postalveolar, alveopalatal, retroflex, palatal, velar, uvular, pharyngeal, glottal };
enum class SecondaryArticulation { plain, labialization, palatalization, labiopalatalization, velarization, pharyngealization, glottalization };

struct Phoneme
{
	wstring ipa;
	float distinctiveness;
	float stability;

	bool voiced;
	bool aspirated;
	bool tensed;
	bool delayedRelease;

	Occlusivity occlusivity;
	Sonorance sonorance;
	Egressivity egressivity;
	Centrality centrality;
	Nasality nasality;
	AirstreamMechanism airstreamMechanism;
	BroadPlaceOfArticulation broadPlace;
	NarrowPlaceOfArticulation narrowPlace;
	SecondaryArticulation secondaryArticulation;

	Phoneme() {};

	Phoneme(wstring ipa, Occlusivity occlusivity, Sonorance sonorance, Egressivity egressivity, Centrality centrality, Nasality nasality, AirstreamMechanism airstreamMechanism,
			BroadPlaceOfArticulation broadPlace, NarrowPlaceOfArticulation narrowPlace, SecondaryArticulation secondaryArticulation, bool voiced, bool aspirated, bool tensed, bool delayedRelease)
	{
		this->ipa = ipa;

		this->voiced = voiced;
		this->aspirated = aspirated;
		this->tensed = tensed;
		this->delayedRelease = delayedRelease;

		this->occlusivity = occlusivity;
		this->sonorance = sonorance;
		this->egressivity = egressivity;
		this->centrality = centrality;
		this->nasality = nasality;
		this->airstreamMechanism = airstreamMechanism;
		this->broadPlace = broadPlace;
		this->narrowPlace = narrowPlace;
		this->secondaryArticulation = secondaryArticulation;
	}
};

vector<wstring> splitString(const wstring& str, const wstring& delimiter)
{
	vector<wstring> strings;

	wstring::size_type pos = 0;
	wstring::size_type prev = 0;

	while ((pos = str.find(delimiter, prev)) != wstring::npos)
	{
		strings.push_back(str.substr(prev, pos - prev));
		prev = pos + 1;
	}

	strings.push_back(str.substr(prev));

	return strings;
}

std::wstring readFile(const char* filename)
{
	std::wifstream wif(filename);
	wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
	std::wstringstream wss;
	wss << wif.rdbuf();
	return wss.str();
}

int wmain(void)
{
	_setmode(_fileno(stdout), _O_U8TEXT);
	std::wcout << L"Testing unicode -- English -- Ελληνικά -- Español." << std::endl;

	wstring txt = readFile("assets/source.txt");
	vector<wstring> lines = splitString(txt, L"\n");

	vector<Phoneme*> phonemes;

	for (int i = 0; i < lines.size(); i++)
	{
		wstring c = lines[i];

		bool valid = false;
		Phoneme* p;

		if (c.find(L"t͡s̪") != std::string::npos ||
			c.find(L"t̻͡s̪") != std::string::npos ||
			c.find(L"ts̪") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::dental,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"d͡z̪") != std::string::npos ||
				 c.find(L"d̻͡z̪") != std::string::npos ||
				 c.find(L"d̻z̪") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::dental,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"t͡s") != std::string::npos ||
				 c.find(L"ts") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::alveolar,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"d͡z") != std::string::npos ||
				 c.find(L"dz") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::alveolar,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"t͡ʃ") != std::string::npos ||
				 c.find(L"t̠ʃ") != std::string::npos ||
				 c.find(L"tʃ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::postalveolar,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"d͡ʒ") != std::string::npos ||
				 c.find(L"d̠ʒ") != std::string::npos ||
				 c.find(L"dʒ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::postalveolar,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ʈ͡ʂ") != std::string::npos ||
				 c.find(L"ʈʂ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::retroflex,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ɖ͡ʐ") != std::string::npos ||
				 c.find(L"ɖʐ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::retroflex,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"t͡ɕ") != std::string::npos ||
				 c.find(L"tɕ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::alveopalatal,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"d͡ʑ") != std::string::npos ||
				 c.find(L"dʑ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::alveopalatal,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"p͡f") != std::string::npos ||
				 c.find(L"p̪͡f") != std::string::npos ||
				 c.find(L"pf") != std::string::npos ||
				 c.find(L"p̪f") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::labiodental,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"b͡v") != std::string::npos ||
				 c.find(L"b̪͡v") != std::string::npos ||
				 c.find(L"bv") != std::string::npos ||
				 c.find(L"b̪v") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::labiodental,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"c͡ç") != std::string::npos ||
				 c.find(L"cç") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::palatal,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ɟ͡ʝ") != std::string::npos ||
				 c.find(L"ɟʝ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::palatal,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"k͡x") != std::string::npos ||
				 c.find(L"kx") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::velar,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ɡ͡ɣ") != std::string::npos ||
				 c.find(L"ɡɣ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::velar,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"q͡χ") != std::string::npos ||
				 c.find(L"qχ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::uvular,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ɢ͡ʁ") != std::string::npos ||
				 c.find(L"ɢʁ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::dorsal,
				NarrowPlaceOfArticulation::uvular,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ʔ͡h") != std::string::npos ||
				 c.find(L"ʔh") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::glottal,
				NarrowPlaceOfArticulation::glottal,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"ʡ͡ʢ") != std::string::npos ||
				 c.find(L"ʡʢ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::central,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::radical,
				NarrowPlaceOfArticulation::pharyngeal,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"t͡ɬ") != std::string::npos ||
				 c.find(L"tɬ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::lateral,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::alveolar,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				true
			);
		}
		else if (c.find(L"d͡ɮ") != std::string::npos ||
				 c.find(L"dɮ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::obstruent,
				Egressivity::egressive,
				Centrality::lateral,
				Nasality::oral,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::alveolar,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				true
			);
		}
		else if (c.find(L"m") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::bilabial,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				false
			);
		}
		else if (c.find(L"m̥") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::bilabial,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				false
			);
		}
		else if (c.find(L"ɱ") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::labiodental,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				false
			);
		}
		else if (c.find(L"ɱ̊") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::labial,
				NarrowPlaceOfArticulation::labiodental,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				false
			);
		}
		else if (c.find(L"n̪") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::dental,
				SecondaryArticulation::plain,
				true,
				false,
				false,
				false
			);
		}
		else if (c.find(L"n̪̊") != std::string::npos)
		{
			valid = true;
			p = new Phoneme(
				c,
				Occlusivity::occlusive,
				Sonorance::sonorant,
				Egressivity::egressive,
				Centrality::central,
				Nasality::nasal,
				AirstreamMechanism::pulmonic,
				BroadPlaceOfArticulation::coronal,
				NarrowPlaceOfArticulation::dental,
				SecondaryArticulation::plain,
				false,
				false,
				false,
				false
			);
		}

		if (valid)
		{
			phonemes.push_back(p);
		}
	}

	wofstream myfile;

	myfile.open("assets/calculations.txt");
	std::locale utf8_locale(std::locale(), new codecvt_utf8<unsigned char>);
	myfile.imbue(utf8_locale);

	myfile << L"Phonemes Found: " + std::to_wstring(phonemes.size()) + L"\n";
	myfile << L"Output\n------\n";

	for (int i = 0; i < phonemes.size(); i++)
	{
		wstring w = phonemes[i]->ipa + L"\n";
		wcout << w;
		myfile << w;
	}
	
	myfile.close();
	
	return 0;
}
