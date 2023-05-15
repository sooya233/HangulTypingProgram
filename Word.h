#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Word{
private:
    vector<string> words;
public:
    Word();
    void show_words();
    void addWord(string word);
    void deleteWord(string word);
    void saveWord();
};