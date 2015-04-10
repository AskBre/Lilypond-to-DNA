#include "DnaTranslator.h"

string DnaTranslator::getTime(ifstream& file) {
	string dTime;
	string word;
	string line;

	while(getline (file,line)) {
		int wordPos = line.find("\\time", 0);

		if(wordPos != -1) {
			vector <int> iTime;

			for(auto c : line) {
				if(iTime.size()<3) {
					if(isdigit(c)) {
						iTime.push_back(c - '0');
					}
				} else {
					cout << "Wrong formatting in:" << endl;
					cout << "   " << line << endl;
				}
			}
			UnsignedToDna uToDna;

			dTime += uToDna.convert(iTime[0]);
			dTime += uToDna.convert(iTime[1]);
		}
	}

	return dTime;
}
