#include "DnaTranslator.h"

void DnaTranslator::setFile(ifstream& file) {
	string line;
	string word;

	while(getline (file,line)) {
		string _line = line += '\n';
		//Make line into a vector of strings
		for(auto c : _line) {
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
}

string DnaTranslator::getTime() {
	string dnaTime;
	string command = "\\time";
	string scoreTime = getCommandValue(command);

	cout << endl;
	cout << "Getting time" << endl;

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

	cout << "   scoreTime is " << scoreTime << endl;
	cout << "   dnaTime is " << dnaTime << endl;
	cout << endl;

	return dnaTime;
}

string DnaTranslator::getKey() {
	string dnaKey;
	string command = "\\key";
	string scoreKey = getCommandValue(command);

	cout << endl;
	cout << "Getting key" << endl;

	unsigned uKey = find(keys.begin(), keys.end(), scoreKey) - keys.begin();

	dnaKey = uToDna.convert(uKey);

	cout << "   scoreKey is " << scoreKey << endl;
	cout << "   dnaKey is " << dnaKey << endl;
	cout << endl;

	return dnaKey;
}

string DnaTranslator::getScale() {
	string dnaScale;
	unsigned uScale;
	 
	cout << endl;
	cout << "Getting scale" << endl;

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
	
	cout << "   uScale is " << uScale << endl;
	cout << "   dnaScale is " << dnaScale << endl;
	cout << endl;

	return dnaScale;
}

string DnaTranslator::getMelody() {
	string dnaMel;
	unsigned time = 0;

	for(int i=0; i<words.size(); i++) {
		string note;
		unsigned offset = 0;
		unsigned eraseAmt = 0;

		string w = words.at(i);

		cout << "The word is " << w << endl;

		//Check whether the word is a command
		if(w.at(0) == '\\') {
			continue;
		}

		// Is the previous word a command
		if(i>0 && words.at(i-1) != "\\minor" && words.at(i-1) != "\\major"){
			if(words.at(i-1).at(0) == '\\') {
				continue;
			}
		}


		for(int j=0; j<w.size(); j++) {
			char c = w.at(j);

			// Get the time
			if(isdigit(c)) {
				time = c - '0';
				eraseAmt++;;
			}

			// Check for offset
			switch(c) {
				case '\'':
					offset += 12;
					eraseAmt++;;
					break;
				case ',':
					offset -= 12;
					eraseAmt++;;
					break;
				default:
					break;
			}
		}

		for(int i = 0; i < eraseAmt; i++) {
			w.pop_back();
		}

		// Check if it exists in the keys-vector
		bool isNote = find(keys.begin(), keys.end(), w) != keys.end();

		if(!isNote) {
			cout << w << " doesn't seem to be a note!" << endl;
			cout << endl;
			continue;
		}

		unsigned uDna = find(keys.begin(), keys.end(), w) - keys.begin();
		cout << "uDna is " << uDna << endl;
		uDna += offset;
		cout << "offset + uDna is " << uDna << endl;

		string dnaNote = uToDna.convert(uDna);
		string dnaTime;

		if(time>0) {
			dnaTime = uToDna.convert(time);
		} else {
			cout << "Haven't received any time-value, exiting" << endl;
			exit(EXIT_FAILURE);
		}

		cout << "dnaNote is " << dnaNote << endl;
		cout << "Time is " << time << endl;
		cout << "dnaTime is " << dnaTime << endl;

		dnaMel += dnaNote;
		dnaMel += dnaTime;

		cout << endl;
	}

	return dnaMel;
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
