#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Sentence.h"
using namespace std;


Sentence::Sentence() {
    fstream sentence_file;
    sentence_file.open("./Default/sentence.txt");

    string sentence;
    while(getline(sentence_file, sentence)) {
        sentences.push_back(sentence);
    }

    sentence_file.close();
}

// vector안의 문장들을 출력하는 함수.
void Sentence::show_sentences() {
    cout << "index \t" << "sentence" << endl;
    for(int i=0 ;i<sentences.size(); i++) {
        cout << i+1 << "\t" << sentences[i] << endl;
    }
    cout << endl;
}

// 문장을 추가하는 함수.
void Sentence::addSentence(string sentence) {
    // 추가하려는 문장이 이미 존재하는지 확인.
    auto it = find(sentences.begin(), sentences.end(), sentence);

    if(it == sentences.end()) { // 추가하려는 문장이 없는 경우.
        sentences.push_back(sentence);
        cout << "문장이 성공적으로 추가되었습니다!\n\n";
        saveSentence();
    } else {
        cout << "이미 존재하는 문장입니다!\n\n";
    }
}


// 문장을 삭제하는 함수.
void Sentence::deleteSentence(string sentence) {
    // 삭제하려는 문장이 존재하는지 확인.
    auto it = find(sentences.begin(), sentences.end(), sentence);

    if(it == sentences.end()) {
        cout << "해당 문장은 파일에 존재하지 않습니다!\n\n";
    } else {
        int loc = it-sentences.begin(); // 해당 문장이 위치하는 인덱스 저장.
        sentences.erase(sentences.begin() + loc);
        cout << "성공적으로 삭제되었습니다!\n\n";
        saveSentence();
    }
}

// 문장을 저장하는 함수.
void Sentence::saveSentence() {
    fstream sentence_file;
    sentence_file.open("./Default/sentence.txt", ios::out);

    for(int i=0; i<sentences.size(); i++) {
        sentence_file << sentences[i] << "\n";
    }

    sentence_file.close();
}