#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;
using std::ios;

#include <vector>

//#include <sstream>

#include <string>
using std::string;

void print(const string &str){
    int row = 1;
    int collum = 1;
    std::string holder;
    int hrow;
    int hcol;
    for (auto letter : str){
        if(letter == '\n'){row++; collum = 0;} // column = 0 since the loop increments it immediately
        else if(letter != ' '){
            if(holder == ""){
                hrow = row;
                hcol = collum;
            }
            holder += letter;
            if(letter == str.back() ){
                cout << "Line " << hrow << ", Collum " << hcol << ": " << '"' << holder << '"' << endl;
            }
        }
        else{
            cout << "Line " << hrow << ", Collum " << hcol << ": " << '"' << holder << '"' << endl;
            holder = "";
        }
        ++collum;
    }
}
/*
int main(int argc, const char * argv[]) {

    ifstream fin;
    fin.open("Alice in Wonderland.txt",std::ios::binary);

    int row =1;
    int column=1;
    string holder;
    fin.read(reinterpret_cast<char*>(&holder), sizeof(string));
    print(holder);


    string words = "n 1 6 berry\n\n vc 255 0 0";
    std::ostringstream oss;
    oss << words;


    cout << "meow" << holder << endl;
    return 0;
}
*/