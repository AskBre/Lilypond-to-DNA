#pragma once
#define DEBUG

#include <iostream>
#include <fstream>
#include <vector>

#include "UnsignedToDna.h"

using namespace std;

class DnaTranslator {
	public:
		string getTime(ifstream& file);
		string getKey(ifstream& file);
		string getScale(ifstream& file);
		string getMelody(ifstream& file);

	private:

};
