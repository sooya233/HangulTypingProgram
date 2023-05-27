#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Sentence{
private:
    vector<string> sentences;
    string file_path;
public:
    Sentence(string data_path);
    void show_sentences();
    void addSentence(string sentence);
    void modifySentence(int index, string sentence);
    void deleteSentence(string sentence);
    void saveSentence();
};