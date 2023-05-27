#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Sentencegame.h"
using namespace std;

SentenceGame::SentenceGame(int count, string data_path) {
    srand((unsigned int)time(NULL));
    
    string file_path = data_path + "/sentence.txt";
    fstream sentence_file;
    sentence_file.open(file_path);

    
    // word.txt로부터 단어를 불러와 file_words에 저장.
    string sentence;
    vector<string> file_sentences;
    while(getline(sentence_file, sentence)) {
        file_sentences.push_back(sentence);
    }
    sentence_file.close();


    sentences = new string[count];
    for(int i=0; i<count; i++) {
        int index = rand() % file_sentences.size();
        sentences[i] = file_sentences[index];
    }
}

SentenceGame::~SentenceGame() {
    delete[] sentences;
}

string SentenceGame::getSentence(int index) {
    return sentences[index];
}
