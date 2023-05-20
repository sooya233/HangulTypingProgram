#include <iostream>
#include <string>
using namespace std;

class SentenceGame{
private:
    string *sentences;
public:
    SentenceGame(int count);
    ~SentenceGame();
    string getSentence(int index);
};