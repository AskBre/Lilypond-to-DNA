#include "UnsignedToDna.h"

void UnsignedToDna::toTernary(unsigned decNum, vector<unsigned>& terNum) {
	if(decNum>0) {
		unsigned m = decNum % 4;

		decNum /= 4;

		toTernary(decNum, terNum);

		terNum.insert(terNum.begin(),m);
	}
}

string UnsignedToDna::convert(unsigned decNum) {

	if(decNum>63) {
		cout << "The number " << decNum << " is more than the DNA-system can handle!" << endl;
		exit(EXIT_FAILURE);
	}

	unsigned _decNum = decNum + offset;

	vector<unsigned> terNum;

	toTernary(decNum, terNum);

	const char bases[] = {'A', 'T', 'G', 'C'};

	stringstream ss;
	string dna;

	for(int i=2; i>=0; i--) {
		if(terNum.size() > i) {
			ss << bases[terNum.at(i)];
		} else {
			ss << bases[0];
		}
	}

	ss >> dna;

	if(dna.compare("TAA") == 0 || dna.compare("TAG") == 0){
		offset++;
		dna = convert(_decNum);
	}

	return dna;
}
