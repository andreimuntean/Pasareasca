#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

string propozitie, errorprevention;
short optiune;

void Citire(string &text)
{
    getline(cin, text);
}

bool isNumber(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void TraducereInPasareasca()
{
    cout << "\n\"" << propozitie << "\"\n=\n\"";
    for (unsigned int i = 0;  i < propozitie.length();  i++)
    {
        cout << propozitie.at(i);
        if (propozitie.at(i) == 'a' || propozitie.at(i) == 'e'
            || propozitie.at(i) == 'i' || propozitie.at(i) == 'o'
            || propozitie.at(i) == 'u')
            cout << 'p' << propozitie.at(i);
        else if (propozitie.at(i) == 'A') cout << "pa";
        else if (propozitie.at(i) == 'E') cout << "pe";
        else if (propozitie.at(i) == 'I') cout << "pi";
        else if (propozitie.at(i) == 'O') cout << "po";
        else if (propozitie.at(i) == 'U') cout << "pu";
    }
    cout << "\"\n";
}

void TraducereDinPasareasca()
{
    cout << "\n\"" << propozitie << "\"\n=\n\"";
    for (unsigned int i = 0;  i < propozitie.length();  i++)
    {
        cout << propozitie.at(i);
        if (propozitie.at(i) == 'a' || propozitie.at(i) == 'e'
            || propozitie.at(i) == 'i' || propozitie.at(i) == 'o'
            || propozitie.at(i) == 'u')
            i += 2;
        else if (propozitie.at(i) == 'A' || propozitie.at(i) == 'E'
            || propozitie.at(i) == 'I' || propozitie.at(i) == 'O'
            || propozitie.at(i) == 'U')
            i += 2;
    }
    cout << "\"\n";
}

int main()
{
    cout << "TRADUCATOR A LIMBII PASARESTI\nProgramat de Andrei Muntean\n\n";
    while (true)
    {
        cout << "Introduceti o propozitie.\n > ";
        Citire(propozitie);
        optiune = 0;
        while (optiune != 3)
        {
            cout << "\n\nSelectati o optiune.\n";
            cout << " 1. Introduceti '1' pentru a traduce propozitia in pasareste.\n";
            cout << " 2. Introduceti '2' pentru a traduce propozitia din pasareste.\n";
            cout << " 3. Introduceti '3' pentru a introduce o noua propozitie.\n > ";
            cin >> errorprevention;
            if (isNumber(errorprevention))
                optiune = atoi(errorprevention.c_str());
            else { cout << "\nEROARE: Doar numere pot fi introduse.\n"; optiune = 0; }

            switch (optiune)
            {
                case 1: TraducereInPasareasca(); break;
                case 2: TraducereDinPasareasca(); break;
            }
            while (getchar() != '\n' && getchar() != ' ');
        }
        cout << "\n\n";
    }
}
