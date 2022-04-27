// main.cpp
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum class Occlusivity { occlusive, continuant, vibrant };
enum class Sonorance { obstruent, sonorant };
enum class Egressivity { egressive, ingressive };
enum class AirstreamMechanism { pulmonic, glottalic, lingual };
enum class BroadPlaceOfArticulation { labial, coronal, dorsal, radical, glottal };
enum class NarrowPlaceOfArticulation { bilabial, labiodental, dental, alveolar, postalveolar, palatoalveolar, retroflex, palatal, velar, uvular, pharyngeal, glottal };
enum class SecondaryArticulation { plain, labialization, palatalization, labiopalatalization, velarization, pharyngealization, glottalization };

struct Phoneme
{
	string ipa;
	float distinctiveness;
	float stability;

	bool voiced;
	bool aspirated;
	bool tensed;
	bool delayedRelease;

	Occlusivity occlusivity;
	Sonorance sonorance;
	Egressivity egressivity;
	AirstreamMechanism airstreamMechanism;
	BroadPlaceOfArticulation broadPlace;
	NarrowPlaceOfArticulation narrowPlace;
	SecondaryArticulation secondaryArticulation;

	Phoneme(string ipa, Occlusivity occlusivity, Sonorance sonorance, Egressivity egressivity, AirstreamMechanism airstreamMechanism, BroadPlaceOfArticulation broadPlace, NarrowPlaceOfArticulation narrowPlace, SecondaryArticulation secondaryArticulation,
			bool voiced, bool aspirated, bool tensed, bool delayedRelease)
	{
		this->ipa = ipa;

		this->voiced = voiced;
		this->aspirated = aspirated;
		this->tensed = tensed;
		this->delayedRelease = delayedRelease;

		this->occlusivity = occlusivity;
		this->sonorance = sonorance;
		this->egressivity = egressivity;
		this->airstreamMechanism = airstreamMechanism;
		this->broadPlace = broadPlace;
		this->narrowPlace = narrowPlace;
		this->secondaryArticulation = secondaryArticulation;
	}
};

int main(void)
{
	std::cout << "Hello World!";

	string txt;
	vector<string> lines;
	ifstream source("source.txt");

	if (source.is_open())
	{
		while (getline(source, txt))
		{
			lines.push_back(txt);
		}
		source.close();
	}
	else
	{
		std::cout << "The source file either doesn't exist or isn't accessible.";
	}

	vector<Phoneme*> phonemes;

	for (int i = 0; i < lines.size(); i++)
	{
		string c = lines[i];

		if (c == "p")
		{
			phonemes.push_back(
				new Phoneme(
					c,
					Occlusivity::occlusive,
					Sonorance::obstruent,
					Egressivity::egressive,
					AirstreamMechanism::pulmonic,
					BroadPlaceOfArticulation::labial,
					NarrowPlaceOfArticulation::bilabial,
					SecondaryArticulation::plain,
					false,
					false,
					false,
					false)
			);
		}
	}

	ofstream myfile;
	
	myfile.open("calculations.txt");

	myfile << "Writing this to a file.\n";
	
	myfile.close();
	
	return 0;
}
