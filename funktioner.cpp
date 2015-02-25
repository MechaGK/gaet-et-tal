#include <limits>
#include "funktioner.h"

using namespace  std;

//Få et tal input fra brugeren mellem to tal
int LaesTal(int minimum, int maksimum, string ord)
{
    cout << ord;
    int input;
    while(!(cin >> input) || input < minimum || input > maksimum)
    {
        RydCin();
        cout << "Ugyldigt valg, det skal være et tal mellem " << minimum << " og " << maksimum << endl;
        cout << ord;
    }

    return input;
}

void RydCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
