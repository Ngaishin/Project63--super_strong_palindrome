#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

bool palindrome(const string& s);

int main()
{


	cout << "Enter words: ";
	string words;

	while (getline(cin, words) && words != "q")
	{
		switch (palindrome(words))
		{
		case 0:cout << "=> Not Palindrom <=\n";
			break;
		default:cout << "=> Palindrome <=\n";
			break;
		}
		cout << "\nEnter words: ";
	}

	return 0;
}

bool palindrome(const string& s)
{
	int size = s.size();
	auto bsi = s.begin();
	auto rbs = s.rbegin();
	int _pair = 0, _count = 0;

	string pal;

	if (size > 1)
		size /= 2;
	else
		return false;
	while (size)
	{
		//determine if the left side is non-alpha.
		if (!isalpha(*bsi))
		{
			++bsi;
			if (++_count > 1)
			{
				--size;
				_count = 0;
			}
			continue;
		}

		//determine the right side is non-alpha.
		if (!isalpha(*rbs))
		{
			++rbs;
			if (++_count > 1)
			{
				--size;
				_count = 0;
			}
			continue;
		}

		//determine whether two variables ate equal.
		if ((tolower(*bsi) != tolower(*rbs))
			|| ((&(*bsi) == &(*rbs)) && (_pair == 0)))
			return false;

		//show palindrome left part
		cout << *bsi;
		pal = *rbs + pal;

		--size, ++bsi, ++rbs, ++_pair;
	}
	//if digit
	if (_pair < 1)return false;

	//show the right side of palindrome
	if ((&(*bsi) == &(*rbs)) && isalpha(*bsi))
		cout << *bsi << pal << endl;
	else
		cout << pal << endl;

	//definitely a palindrome.
	return true;
}
