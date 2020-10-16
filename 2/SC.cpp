#include "string.h"

StringClass::StringClass(string str, char chr, int cnt)
{
    s = str;
    h = chr;
    c = cnt;
}

void StringClass::SetData()
{
	cout << "Enter string: ";
	cin >> s;
	cout << endl;
}

string StringClass::ReplChar()
{
	h = s[s.length() - 1];
	for(unsigned int i = 0; i < s.length(); i++)
		if(s[i] == 'a') {s[i] = h, c++;}
	return s;
}

void StringClass::GetData()
{
    cout << "\n" << "Char 'a' replaced to char '" << h << "' " << c << " times." << endl;
}
