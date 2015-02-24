//Få et tal input fra brugeren mellem to tal
int LaesTal(int minimum, int maksimum)
{
    cout << "Valg: ";
    int input;
    while(!(cin >> input) || valg < minimum || valg > maximum){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ugyldigt valg, det skal være et tal mellem " << minimum << " og " << maksimum << endl;
        cout << "Valg: ";
    }

    return input;
}
