#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef struct{
    string name;
    string lname;
    int number;
} Contact_t;

void regContact(vector<Contact_t>& dir){
    Contact_t c;
    
    cout << "\nType in the next info:\n";
    cout << "Name: " ; cin >> c.name;
    cout << "Last name: "; cin >> c.lname;
    cout << "Number: "; cin >> c.number;
    
    dir.push_back(c);
}

void regDirectory(const Contact_t& c){
    ofstream conDir;
    conDir.open("contacts.txt", iostream::app);
    conDir << "\n===========================\n";
    conDir << "Name: " << c.name << endl;
    conDir << "Last name: " << c.lname << endl;
    conDir << "Number: " << c.number << endl;
    conDir << "===========================\n";
    conDir.close();
}

void showDirectory(vector<Contact_t>& dir){
    for(vector<Contact_t>::iterator it = dir.begin(); it != dir.end(); it++)
    {
    cout << "\n===========================\n";
    cout << "Name: " << (*it).name << endl;
    cout << "Last name: " << (*it).lname << endl;
    cout << "Number: " << (*it).number;
    cout << "\n===========================\n";
    }
}

void showMenu(){
    cout << "Select one of the options:\n\n";
    cout << "1. Create contact\n2. Add another contact\n";
    cout << "3. Show contacts\n";
    cout << "Press another key to exit.\n\n> ";
}

int main(){

    vector<Contact_t> dir;
    do{
        showMenu();
        char opt;
        cin >> opt;
        switch(opt){
            case '1':
            case '2':
                regContact(dir);
                break;
            case '3':
                showDirectory(dir);
                break;
            default:
                opt = 's';
                cout << "Directory app terminated.\n\n";
        }
    while(opt != 's');

    for(vector<Contact_t>::iterator it = dir.begin(); it != dir.end(); it++)
        regDirectory(*it);

    dir.clear();
    return 0;
}
