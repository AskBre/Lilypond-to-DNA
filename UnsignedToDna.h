#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class UnsignedToDna {
	public:
		string convert(unsigned decNum);

	private:
		void toTernary(unsigned decNum, vector<unsigned>& terNum);

		unsigned offset = 0;
};
