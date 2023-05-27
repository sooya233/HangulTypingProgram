#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Word.h"
using namespace std;


Word::Word(string data_path) {
    file_path = data_path + "/word.txt";
    fstream word_file;
    word_file.open(file_path);

    string word;
    while(getline(word_file, word)) {
        words.push_back(word);
    }

    word_file.close();
}

// vector안의 단어들을 출력하는 함수.
void Word::show_words() {
    cout << "index \t" << "word" << endl;
    for(int i=0 ;i<words.size(); i++) {
        cout << i+1 << "\t" << words[i] << endl;
    }
    cout << endl;
}

// 단어를 추가하는 함수.
void Word::addWord(string word) {
    // 추가하려는 단어가 이미 존재하는지 확인.
    auto it = find(words.begin(), words.end(), word);

    if(it == words.end()) { // 추가하려는 단어가 없는 경우.
        words.push_back(word);
        cout << "단어가 성공적으로 추가되었습니다!\n\n";
        saveWord();
    } else {
        cout << "이미 존재하는 단어입니다!\n\n";
    }
}

// 단어를 수정하는 함수.
void Word::modifyWord(int index, string word) {
    // 수정하려는 단어가 이미 존재하는지 확인.
    auto it = find(words.begin(), words.end(), word);

    if (it == words.end()) { // 수정하려는 단어가 없는 경우.
        words[index-1] = word;
        cout << "단어를 성공적으로 수정하였습니다!\n\n";
        saveWord();
    }
    else {
        cout << "이미 존재하는 단어입니다!\n\n";
    }
}

// 단어를 삭제하는 함수.
void Word::deleteWord(string word) {
    // 삭제하려는 단어가 존재하는지 확인.
    auto it = find(words.begin(), words.end(), word);

    if(it == words.end()) {
        cout << "해당 단어는 파일에 존재하지 않습니다!\n\n";
    } else {
        int loc = it-words.begin(); // 해당 단어가 위치하는 인덱스 저장.
        words.erase(words.begin() + loc);
        cout << "성공적으로 삭제되었습니다!\n\n";
        saveWord();
    }
}

// 단어를 저장하는 함수.
void Word::saveWord() {
    fstream word_file;
    word_file.open(file_path, ios::out);

    for(int i=0; i<words.size(); i++) {
        word_file << words[i] << "\n";
    }

    word_file.close();
}