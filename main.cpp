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

		string time = dna.getTime(file);

		cout << "Time is: " << time << endl;

		string dnaString = "DNAAAA";

		cout << "The final dna is: " << dnaString << endl;

	} else {
		cout << "The file isn't open" << endl;
	}

	return 0;
}
