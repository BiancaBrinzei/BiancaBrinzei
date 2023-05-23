#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Floare {
    string nume;
    string culoare;
    int pret;
    int cantitate;
    float* vector;

    Floare() : nume(""), culoare(""), pret(0), cantitate(0), vector(nullptr) {}

    ~Floare() {
        delete[] vector;
    }
};

vector<Floare> stoc;

void adaugaFloare() {
    Floare f;
    cout << "Introdu numele florii: ";
    cin >> f.nume;
    cout << "Introdu culoarea: ";
    cin >> f.culoare;
    cout << "Introdu pretul: ";
    cin >> f.pret;
    cout << "Introdu cantitatea disponibila: ";
    cin >> f.cantitate;
    stoc.push_back(f);
    cout << "Floarea a fost adaugata in stoc." << endl;
}

void cautaFloare() {
    string nume, culoare;
    int pret, cantitate;
    bool gasit = false;
    cout << "Introdu numele florii: ";
    cin >> nume;
    cout << "Introdu culoarea: ";
    cin >> culoare;
    cout << "Introdu pretul: ";
    cin >> pret;
    cout << "Introdu cantitatea dorita: ";
    cin >> cantitate;
    for (auto f : stoc) {
        if (f.nume == nume && f.culoare == culoare && f.pret == pret && f.cantitate >= cantitate) {
            cout << "Am gasit " << cantitate << " bucati din floarea " << nume << " (" << culoare << ") cu pretul de " << pret << " lei/bucata." << endl;
            gasit = true;
        }
    }
    if (!gasit) {
        if (cantitate > 1000) {
            throw runtime_error("Eroare.Introdu din nou!");
        } else {
            cout << "Nu avem pe stoc." << endl;
        }
    }
}

void afiseazaStoc() {
    cout << "Stocul actual:" << endl;
    for (auto f : stoc) {
        cout << f.nume << " (" << f.culoare << "), pret: " << f.pret << " lei/bucata, disponibile: " << f.cantitate << " bucati." << endl;
    }
}

int main() {
    int optiune;
    do {
        cout << "Buna ziua!" << endl;
        cout << "Meniu:" << endl;
        cout << "1. Adauga floare" << endl;
        cout << "2. Cauta floare" << endl;
        cout << "3. Afiseaza stoc" << endl;
        cout << "0. Iesire" << endl;
        cout << "Alege o optiune: ";
        cin >> optiune;
        switch (optiune) {
            case 1:
                adaugaFloare();
                break;
            case 2:
                try {
                    cautaFloare();
                } catch (exception& e) {
                    cerr << "Eroare: " << e.what() << endl;
                }
                break;
            case 3:
                afiseazaStoc();
                break;
            case 0:
                cout << "La revedere!";
                break;
            default:
                cout << "Optiune invalida." << endl;
        }
    } while (optiune != 0);

    return 0;
}
