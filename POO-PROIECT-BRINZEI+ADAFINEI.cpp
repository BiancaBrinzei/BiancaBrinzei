//Sa se implementeze clasa STUDENT in care sa se foloseasca urmatoarele:
//O functie prin care sa se citeasca numele,prenumele si notele obtinute la o sesiune de 5 examene de catre un student
//O functie pentru afisare
//O functie pentru calcului mediei de promovare

#include <iostream>
#include <string>

using namespace std;

class Student {
  private:
    string nume;
    string prenume;
    int note[5];

  public:
    Student(string n, string p) {
      nume = n;
      prenume = p;
    }

    void citesteNote() {
      for(int i=0; i<5; i++) {
        cout << "Introdu nota " << i+1 << ": ";
        cin >> note[i];
      }
    }

    void afiseaza() {
      cout << "Nume: " << nume << " " << prenume << endl;
      cout << "Note: ";
      for(int i=0; i<5; i++) {
        cout << note[i] << " ";
      }
      cout << endl;
    }

    float calculeazaMedia() {
      float sum = 0;
      for(int i=0; i<5; i++) {
        sum += note[i];
      }
      return sum / 5;
    }

    ~Student() {
      cout << "Stergere student " << nume << " " << prenume << endl;
    }
};

int main() {
  Student s1("Maria", "Prodan");
  s1.citesteNote();
  s1.afiseaza();
  cout << "Media: " << s1.calculeazaMedia() << endl;

  Student s2("Ionut", "Pop");
  s2.citesteNote();
  s2.afiseaza();
  cout << "Media: " << s2.calculeazaMedia() << endl;

  Student s3("Mircea", "Lungu");
  s3.citesteNote();
  s3.afiseaza();
  cout << "Media: " << s3.calculeazaMedia() << endl;

  return 0;
}
