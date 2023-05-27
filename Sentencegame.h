#include <iostream>
#include <string>
using namespace std;

class SentenceGame{
private:
    string *sentences;
public:
    SentenceGame(int count, string data_path);
    ~SentenceGame();
    string getSentence(int index);
};