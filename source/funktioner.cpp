#include <limits>
#include <string>
#include "functions.h"

using namespace  std;

//Få et tal input fra brugeren mellem to tal
int GetNumber(int minimum, int maximum, string word)
{
    cout << word;
    int input;
	while (!(cin >> input) || input < minimum || input > maximum)
    {
		ClearCin();
		cout << "Ugyldigt valg, det skal være et tal mellem " << minimum << " og " << maximum << endl;
		cout << word;
    }

    return input;
}

void ClearCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
