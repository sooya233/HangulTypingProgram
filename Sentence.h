#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Sentence{
private:
    vector<string> sentences;
public:
    Sentence();
    void show_sentences();
    void addSentence(string sentence);
    void deleteSentence(string sentence);
    void saveSentence();
};