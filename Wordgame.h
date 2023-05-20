#include <iostream>
#include <string>
using namespace std;

class WordGame{
private:
    string *words;
public:
    WordGame(int count);
    ~WordGame();
    string getWord(int index);
    void printWords();
};