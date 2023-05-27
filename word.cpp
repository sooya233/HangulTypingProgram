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

// vector���� �ܾ���� ����ϴ� �Լ�.
void Word::show_words() {
    cout << "index \t" << "word" << endl;
    for(int i=0 ;i<words.size(); i++) {
        cout << i+1 << "\t" << words[i] << endl;
    }
    cout << endl;
}

// �ܾ �߰��ϴ� �Լ�.
void Word::addWord(string word) {
    // �߰��Ϸ��� �ܾ �̹� �����ϴ��� Ȯ��.
    auto it = find(words.begin(), words.end(), word);

    if(it == words.end()) { // �߰��Ϸ��� �ܾ ���� ���.
        words.push_back(word);
        cout << "�ܾ ���������� �߰��Ǿ����ϴ�!\n\n";
        saveWord();
    } else {
        cout << "�̹� �����ϴ� �ܾ��Դϴ�!\n\n";
    }
}

// �ܾ �����ϴ� �Լ�.
void Word::modifyWord(int index, string word) {
    // �����Ϸ��� �ܾ �̹� �����ϴ��� Ȯ��.
    auto it = find(words.begin(), words.end(), word);

    if (it == words.end()) { // �����Ϸ��� �ܾ ���� ���.
        words[index-1] = word;
        cout << "�ܾ ���������� �����Ͽ����ϴ�!\n\n";
        saveWord();
    }
    else {
        cout << "�̹� �����ϴ� �ܾ��Դϴ�!\n\n";
    }
}

// �ܾ �����ϴ� �Լ�.
void Word::deleteWord(string word) {
    // �����Ϸ��� �ܾ �����ϴ��� Ȯ��.
    auto it = find(words.begin(), words.end(), word);

    if(it == words.end()) {
        cout << "�ش� �ܾ�� ���Ͽ� �������� �ʽ��ϴ�!\n\n";
    } else {
        int loc = it-words.begin(); // �ش� �ܾ ��ġ�ϴ� �ε��� ����.
        words.erase(words.begin() + loc);
        cout << "���������� �����Ǿ����ϴ�!\n\n";
        saveWord();
    }
}

// �ܾ �����ϴ� �Լ�.
void Word::saveWord() {
    fstream word_file;
    word_file.open(file_path, ios::out);

    for(int i=0; i<words.size(); i++) {
        word_file << words[i] << "\n";
    }

    word_file.close();
}