#include "DnaTranslator.h"

void DnaTranslator::setFile(ifstream& file) {
	string line;

	string word;

	while(getline (file,line)) {
		//Make line into a vector of strings
		for(auto c : line) {
			if(c == ' ' || c == '\t' || c == '\n') {
				if(!word.empty()) {
					words.push_back(word);
					word.clear();
				}
			} else {
				word.push_back(c);
			}
		}
	}

	cout << endl;
}

string DnaTranslator::getTime() {
	string dnaTime;
	string command = "\\time";
	string scoreTime = getCommandValue(command);

	vector <int> iTime;

	for(auto c : scoreTime) {
		if(iTime.size()<3) {
			if(isdigit(c)) {
				iTime.push_back(c - '0');
			}

		} else {
			cout << "Wrong time formatting in:" << endl;
			cout << "   " << scoreTime << endl;
		}
	}

	if(iTime.size()==2) {
		dnaTime += uToDna.convert(iTime[0]);
		dnaTime += uToDna.convert(iTime[1]);
	} else {
		cout << "Wrong number of times!" << endl;
	}

	return dnaTime;
}

string DnaTranslator::getKey() {
	string dnaKeu;
	string command = "\\key";
	string scoreKey = getCommandValue(command);

	unsigned uKey = find(keys.begin(), keys.end(), scoreKey) - keys.begin();

	dnaKeu = uToDna.convert(uKey);

	return dnaKeu;
}

string DnaTranslator::getScale() {
	string dnaScale;
	unsigned uScale;

	string major = "\\major";
	string minor = "\\minor";

	string rMajor = getCommandValue(major);
	string rMinor = getCommandValue(minor);

	if(!rMajor.empty()) {
		uScale = 0;
	} else if (!rMinor.empty()) {
		uScale = 1;
	} else {
		cout << "Can't find any scale info!" << endl;
	}

	dnaScale = uToDna.convert(uScale);

	return dnaScale;
}

string DnaTranslator::getCommandValue(string& command) {
	string value;
	string word;

	bool commandExists = find(words.begin(), words.end(), command) != words.end();

	if(commandExists) {
		int commandPos = find(words.begin(), words.end(), command) - words.begin();

		value = words.at(commandPos+1);

		return value;
	}

	if(command != "\\minor" && command != "\\major") {
		cout << "Couldn't find the command " << command << endl;
	}

	return "";
}
