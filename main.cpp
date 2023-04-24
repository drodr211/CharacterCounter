#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getPlace(char a);
int main() {
    int arr[53];
    for(int i = 0; i < 53; i++) {
        arr[i] = 0;
    }
    ifstream myfile("Text.txt");
    string str;
    if(myfile.is_open()) {
        while(myfile.good()){
            getline(myfile, str, ' ');
            for(int i = 0; i < str.size(); i++) {
                arr[getPlace(str[i])]++;
            }
        }
    }
    myfile.close();

    for(int i = 0; i < 53; i++) {
        if(i >= 0 && i <= 25) {cout << char(i+65) << ": ";}    
        else if (i >= 26 && i <= 51) {cout << char(i+71) << ": ";}
        else{cout << "invalid chars: ";}
        cout << arr[i] << endl;
    }
    return 0;
}

int getPlace(char a){
    if(int(a)>= 65 && int(a) <= 90) return (int(a) - 65);
    else if (int(a) >= 97 && int(a) <= 122) return (int(a) - 71);
    else return 52;
}