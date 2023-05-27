#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include "Wordgame.h"
using namespace std;

WordGame::WordGame(int count) {
    srand((unsigned int)time(NULL));
    
    fstream word_file;
    word_file.open("./Default/word.txt");

    
    // word.txt로부터 단어를 불러와 file_words에 저장.
    string word;
    vector<string> file_words;
    while(getline(word_file, word)) {
        file_words.push_back(word);
    }
    word_file.close();


    words = new string[count];
    for(int i=0; i<count; i++) {
        int index = rand() % file_words.size();
        words[i] = file_words[index];
    }
}

WordGame::~WordGame() {
    delete[] words;
}

string WordGame::getWord(int index) {
    return words[index];
}

void WordGame::printWords() {
    for(int i=0; i<words->length(); i++) {
        cout << words[i] << endl;
    }
}