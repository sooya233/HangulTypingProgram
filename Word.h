#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Word{
private:
    vector<string> words;
    string file_path;
public:
    Word(string data_path);
    void show_words();
    void addWord(string word);
    void deleteWord(string word);
    void saveWord();
};