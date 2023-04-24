#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int getIndex(char a) { return (int(a)-32);}

int main() {
    int arr[95] = {0};
    ifstream text("text.txt");
    stringstream buffer;
    buffer << text.rdbuf();
    string str = buffer.str();
    text.close();
    
    for(int i = 0; i < str.size(); i++) {
        arr[getIndex(str[i])]++;
    }
    cout << "SPACE";
    for(int i = 0; i < 95; i++) {
        cout << char(i+32) << ": " << arr[i] << endl;
    }
    return 0;
}