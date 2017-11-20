#include <iostream>
#include <typeinfo>
#include <cstdio>
#include <cctype>
using namespace std;
string getInput() {
    cout << "Type something to see if it's a palindrome!\n\n";
    string Word;
    cin >> Word;
    while (!cin) {
        cin >> Word;
        cout << typeid(Word).name();
    }
    for (int i = Word.length()-1;i>=0;i--) {
        Word[i] = tolower(Word[i]);
    }
    return Word;
}
bool isPalindrome(string Word) {
    string Reverse = "";

    for (int i=Word.length()-1;i>=0;i--) {
        Reverse+=Word[i];
    }
    cout << endl << Reverse << endl;
    if (Reverse == Word) {
        cout << "\n" << Word << " is a palindrome!\n";
    }
    else {
        cout << "\n" << Word << " is not a palindrome!\n";
    }
}


int main()
{
    isPalindrome(getInput());
    getchar(); //Pauses program for readability

}
