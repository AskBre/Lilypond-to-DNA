#pragma once

#define DEBUG

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "UnsignedToDna.h"

using namespace std;

class DnaTranslator {
	public:
		void setFile(ifstream& file);
		string getTime();
		string getKey();
		string getScale();
		string getMelody();

	private:
		vector<string> words;
		string getCommandValue(string& command);

		UnsignedToDna uToDna;

		const vector<string> keys = {"c", "des", "d", "ees", "e", "fes", "f", "ges", "g", "aes", "a", "bes", "b"};

};
