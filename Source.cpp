#include <iostream>
#include <string>
#include "Hashtable.h"

using namespace std;

int main() {
    int size;

    cout << "Unesi velicinu tabele:\n";
    cin >> size;
    BLAdresiranje parametar(2);
    Hashtable table(&parametar,size);
    int choice;

    while (true) {
        cout << "[1]Unesi kljuceve i stringove\n[2]Ispisi tabelu\n[3]Pronadji odredjeni kljuc\n[4]Obrisi kljuc\n[5]Prosecan broj uspenih pristupa\n[6]Prosecan broj neuspesnih pristupa\n[7]Resetuj statistike\n[8]Ocisti tabelu\n[9]Broj kljuceva u tabeli\n[10]Velicina tabele\n[11]Stepen popunjenosti\n[0]Izlaz\n";
        cin >> choice;
        switch (choice) {
        case 1:{
                cout << "Unesi kljuc:";
                long key;
                cin >> key;
                cout << "Unesi string:";
                string s;
                cin >> s;
                table.insertKey(key, s);

                break;  
            }
        case 2: 
            cout << table;
            break;
        case 3:
        {
            int key;
            cout << "Unesi kljuc za pretragu:\n";
            cin >> key;
            string answer = table.findKey(key) != "/" ? "Kljuc pronadjen!\n" : "Nema kljuca!\n";
            cout << answer;
            break;
        }
        case 4:
        {
            int key;
            cout << "Unesi kljuc za brisanje:\n";
            cin >> key;
            string answer = table.deleteKey(key) ? "Kljuc je obrisan!\n" : "Nema kljuca!\n";
            cout << answer << endl << table << endl;
            break;
        }
        case 5:
            cout << table.avgAccessSuccess() << endl;
            break;
        case 6:
            cout << table.avgAccessUnsuccess() << endl;
            break;
        case 7:
            table.resetStatistics();
            break;
        case 8:
            table.clear();
            break;
        case 9:
            cout << table.keyCount() << endl;
            break;
        case 10:
            cout << table.tableSize() << endl;
            break;
        case 11:
            cout << table.fillRatio() << "%" << endl;
            break;
        case 0: exit(1);
            break;
        }
    }

	return 0;
}