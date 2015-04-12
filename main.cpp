#include <fstream>
#include <iostream>
#include "DnaTranslator.h"

using namespace std;

int main(int argc, char *argv[]) {
	if(argc > 2 || argc == 1) {
		cout << "Usage:" << endl;
		cout << "   main [myLilypondScore.txt]" << endl;


		return 0;
	}

	ifstream file(argv[1]);

	string dna;

	if(file.is_open()) {
		DnaTranslator dnaMaker;

		dnaMaker.setFile(file);

		dna = "ATG";
		dna += dnaMaker.getTime();
		dna += dnaMaker.getKey();
		dna += dnaMaker.getScale();
		dna += dnaMaker.getMelody();
		dna += "TAA";

		cout << "The final dna is " << dna << endl;

	} else {
		cout << "The file isn't open" << endl;
	}

	ofstream dnaFile("dna.txt");
	time_t t = time(nullptr);

	dnaFile << "This DNA is created from score " << argv[1];
	dnaFile << " at " << asctime(localtime(&t)) << endl;
	dnaFile << dna << endl;

	return 0;
}
