#include <iostream>
#include <string>
using namespace std;

class WordGame{
private:
    string *words;
public:
    WordGame(int count, string data_path);
    ~WordGame();
    string getWord(int index);
    void printWords();
};