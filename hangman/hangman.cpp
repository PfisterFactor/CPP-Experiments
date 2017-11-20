#include <iostream>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
//Second rework of my Hangman game, changes are mostly just code organization

using namespace std;
//For the update loop, if game is playing it is true
bool gameIsPlaying;
//Used to initialize game and select difficulty
bool gameJustStarted;
//Difficulty level (5 letters, 6 letters, or 7 letters)
short Difficulty;
//What letter the user guessed
char LetterInput;
//# of wrongly guessed letters user made, if higher than 5 they ded
short Mistakes = 0;
//Array of previously guessed letters
string GuessedLetters[26];

string Word;

vector<char>cWord(7);

vector<string> Words;

int GuessedLettersCounter=0;

int winCounter = 0;

vector<string> getWordsFromFile(short Difficulty) {
    ifstream Wordlist("Words.txt");
    if (!Wordlist.good()) {
        system("cls");
        cout << "\nNo Words.txt file detected! This file is essential!\n\n";
        exit(0);
    }
    string throwout;
    stringstream ss;
    bool WordAdd = false;
    short VectorCounter = 0;
    vector<string> WordListReturn(500);
    string test;
    bool isValid = false;
    ss << Difficulty << "|";
    test = ss.str();
    if (Wordlist.is_open()) {
        while (getline(Wordlist,throwout)) {
            if (WordAdd) {
                if (throwout.find("\\") != string::npos) {
                    WordAdd = false;
                } else {
                    if (throwout.length()==Difficulty) {
                        WordListReturn.at(VectorCounter) = throwout;
                        VectorCounter++;
                    } else {
                        cout << "\nWordHasIncorrectLengthForCategory! (" << throwout << ")";
                    }
                }
            }
            if (throwout.find(test) != string::npos) {
                WordAdd = true;
                isValid = true;
            }
        }
    } else {
        cout << "something's wrong";
    }
    if (!isValid) {
        system("cls");
        cout << "\nWords.txt must be correctly formatted!\n\n";
        exit(0);
    }
    Wordlist.close();
    for (short i = 0; i <=WordListReturn.size()-1; i++) {
        if (WordListReturn.at(i)=="") {
            if (i < 1) {
                system("cls");
                cout << "\nThere are no words in the selected category.\nAdd some words in your Words.txt file under the " << Difficulty << " category\n\n";
                exit(0);
            }
            else {
                WordListReturn.resize(i);
            }
        }
    }
    return WordListReturn;
}
void Initilization() {
    cout << "Developed by Eric Pfister (MrPf1ster)\n___________________________________\n\nHello and welcome to Hangman!";
    cout << "\n\nChoose your difficulty";
    cout << "\n\nType 5,6,or 7 for word length\n\n";
    while (true) {
        //Messy as fuck below, conversion from a string to a short for use in the switch statement
        string conversion;
        getline(cin,conversion);
        stringstream convert(conversion);
        convert >> Difficulty;

        if (false) {
loopbreak:
            break;
        }
        switch (Difficulty) {
        case (short)5:
            cout << "\n\nYou have selected 5 letter words!";
            goto loopbreak;
            break;
        case (short)6:
            cout <<"\n\nYou have selected 6 letter words!";
            goto loopbreak;
            break;
        case (short)7:
            cout <<"\n\nYou have selected 7 letter words!";
            goto loopbreak;
            break;
        default:
            cout <<"\n\nInput correct difficulty option!\n\n";
            break;

        }
    }
    gameJustStarted = false;
    cout << "\n\n\nPress [Enter] to start the game!\n\n";
    //Below just generates a random word from the file (Words.txt)
    srand(time(NULL));
    Words = getWordsFromFile(Difficulty);
    int randNum = (rand()%((Words.size()-1)-0 + 1) + 0);
    Word = Words.at(randNum);
    std::transform(Word.begin(), Word.end(), Word.begin(), ::tolower);
    cWord.resize(Word.length());
    fill(cWord.begin(),cWord.end(),'_');
    string pointless;
    getline(cin,pointless);


}
void DisplayLimbs(int Limb_Number) {
    //Draws the gallows and hanging guy
    //Thar she blows!
    switch(Limb_Number) {

    case 0:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q\n QQ\n Q\n Q\n Q\n Q\n Q\n Q\n Q\n\n\n\n\n\n\n";
        break;
    case 1:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q\n Q\n Q\n Q\n Q\n Q\n\n\n\n\n\n\n";
        break;
    case 2:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q              #\n Q              #\n Q              #\n Q              #\n Q\n Q\n\n\n\n\n\n\n";
        break;
    case 3:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q              #\n Q              ####\n Q              #\n Q              #\n Q\n Q\n\n\n\n\n\n\n";
        break;
    case 4:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q              #\n Q           #######\n Q              #\n Q              #\n Q\n Q\n\n\n\n\n\n\n";
        break;
    case 5:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q              #\n Q           #######\n Q              #\n Q              #\n Q               #\n Q                #\n                   #\n\n\n\n\n\n";
        break;
    case 6:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q           ###\n QQ           #####\n Q             ###\n Q              #\n Q           #######\n Q              #\n Q              #\n Q             # #\n Q            #   #\n             #     #\n\n\n\n\n\n";
        break;
    default:
        cout << " QQQQQQQQQQQQQQQQ\n Q   Q          Q\n Q  Q           Q\n Q Q\n QQ\n Q\n Q\n Q\n Q\n Q\n Q\n Q\n\n\n\n\n\n\n";
        break;
    }
}
bool CheckForWin(bool autowin) {
//Win condition is that the "correct letter" dialog was displayed 5,6, or 7 times (depending on difficulty)
    if (autowin) {
        for (int i=1; i <= 30; i++) {
            cout << endl;
        }
        DisplayLimbs(Mistakes);
        cout << "You win the game! Congrats!\n\n";
        cout << "The word was: "<<Word << "\n\n";
        cout << "Restart the program to play again!";
        return true;
    }
    if (winCounter == Difficulty) {
        cout << "You win the game! Congrats!\n\n";
        cout << "The word was: "<<Word << "\n\n";
        cout << "Restart the program to play again!";
        getchar();
        return true;
    } else {
        return false;
    }
}
bool Update() {
    while (true) {
        //Clears Screen
        for (int i=1; i <= 30; i++) {
            cout << endl;
        }
        DisplayLimbs(Mistakes);
        if (CheckForWin(false)) {
            return true;
        }
        if (Mistakes <= 5) {
            switch(Difficulty) {
            case (short)5:
                cout << cWord[0] << "   "<<cWord[1] << "    " <<cWord[2] << "    " << cWord[3] << "    " <<cWord[4] << "\n\n";
                break;
            case (short)6:
                cout << cWord[0] << "   "<<cWord[1] << "    " <<cWord[2] << "    " << cWord[3] << "    " <<cWord[4] << "     " <<cWord[5] << "\n\n";
                break;
            case (short)7:
                cout << cWord[0] << "   "<<cWord[1] << "    " <<cWord[2] << "    " << cWord[3] << "    " <<cWord[4] << "     " <<cWord[5] << "     " << cWord[6] << "\n\n";
            }
            cout << "Guessed letters: ";
            for (short i = 0; i <= 25; i++) {
                if (GuessedLetters[i] != "") {
                    string UppercaseLetter = GuessedLetters[i];
                    UppercaseLetter = toupper(UppercaseLetter[0]);
                    cout << UppercaseLetter << "-";
                }
            }
            cout << "\n\n";
            cout << "Guess a letter!\n\n";
            string GuessedLetter;
            bool isGuessed = true;
            while (isGuessed) {
                getline(cin,GuessedLetter);
                for(short i =0; i <= 25; i++) {
                    transform(GuessedLetter.begin(), GuessedLetter.end(), GuessedLetter.begin(), ::tolower);
                    if (GuessedLetter == Word) {
                        CheckForWin(true);
                        getchar();
                        return true;
                    }
                    if (GuessedLetter.length() != 1 || isdigit(GuessedLetter[0])) {
                        cout << "\n\nYou can't guess that!\n\n\n";
                        break;
                    }
                    if (GuessedLetter == GuessedLetters[i]) {
                        cout << "\n\nGuess a letter you haven't already guessed!\n\n\n";
                        isGuessed = true;
                        break;
                    }
                    if (i == 25) {
                        isGuessed = false;
                    }
                }
            }
            if (Word.find(GuessedLetter) != string::npos) {
                cout << "Your guess of letter "<< GuessedLetter << " was correct!";
                GuessedLetters[GuessedLettersCounter] = GuessedLetter;
                GuessedLettersCounter++;
                for (short i = 0; i <= cWord.size()-1; i++) {
                    if (Word[i] == GuessedLetter[0]) {
                        if (i == 0) {
                            cWord[i] = toupper(GuessedLetter[0]);
                            winCounter++;
                        } else {
                            cWord[i] = GuessedLetter[0];
                            winCounter++;
                        }
                    }
                }
            } else {
                cout << "\n\nYour guess of letter "<<GuessedLetter <<" was wrong, the man has another body part!";
                GuessedLetters[GuessedLettersCounter] = GuessedLetter;
                GuessedLettersCounter++;
                Mistakes++;
            }
        } else {
            cout << "You lose! :( \n \nThe word was: " << Word << "\n\nRestart the program to try again!";
            getchar();
            return true;
        }
        string pointless;
        getline(cin,pointless);
    }
}

int main() {
    gameIsPlaying = true;
    gameJustStarted = true;
    Initilization();
    if (Update()) {
        return 0;
    }
}
