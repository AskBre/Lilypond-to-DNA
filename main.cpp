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

	if(file.is_open()) {
		DnaTranslator dnaMaker;

		dnaMaker.setFile(file);

		string dna = "ATG";
		dna += dnaMaker.getTime();
		dna += dnaMaker.getKey();
		dna += dnaMaker.getScale();
		dna += dnaMaker.getMelody();
		dna += "TAA";

		cout << "The final dna is " << dna << endl;

	} else {
		cout << "The file isn't open" << endl;
	}

	return 0;
}
