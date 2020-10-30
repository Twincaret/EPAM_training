#include <iostream>
#include <algorithm>

int main()
{
	std::string _str, str = "Remember: curiosity killed the cat";
	std::cout << str << "\n\nPlease, enter _substring to found: ";
	std::getline(std::cin, _str);
	auto it = [& str, _str](std::string _s){ std::size_t pos = str.find(_s); // lambda: [ captures ] ( params ) { body }
				if(pos != std::string::npos) std::cout << "Found at position: " << pos << '\n';
				else std::cout << "Not found!\n";};   
	it(_str);

	return 0;
}
