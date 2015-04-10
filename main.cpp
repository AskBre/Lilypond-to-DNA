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
		DnaTranslator dna;

		dna.setFile(file);

		string time = dna.getTime();
		string key = dna.getKey();
		string scale = dna.getScale();

		cout << "Time is: " << time << endl;
		cout << "Key is: " << key << endl;
		cout << "Scale is: " << scale << endl;

		string dnaString = "DNAAAA";

		cout << "The final dna is: " << dnaString << endl;

	} else {
		cout << "The file isn't open" << endl;
	}

	return 0;
}
