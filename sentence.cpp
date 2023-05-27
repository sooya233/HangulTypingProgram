#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Sentence.h"
using namespace std;


Sentence::Sentence(string data_path) {
    file_path = data_path + "/sentence.txt";
    fstream sentence_file;
    sentence_file.open(file_path);

    string sentence;
    while(getline(sentence_file, sentence)) {
        sentences.push_back(sentence);
    }

    sentence_file.close();
}

// vector���� ������� ����ϴ� �Լ�.
void Sentence::show_sentences() {
    cout << "index \t" << "sentence" << endl;
    for(int i=0 ;i<sentences.size(); i++) {
        cout << i+1 << "\t" << sentences[i] << endl;
    }
    cout << endl;
}

// ������ �߰��ϴ� �Լ�.
void Sentence::addSentence(string sentence) {
    // �߰��Ϸ��� ������ �̹� �����ϴ��� Ȯ��.
    auto it = find(sentences.begin(), sentences.end(), sentence);

    if(it == sentences.end()) { // �߰��Ϸ��� ������ ���� ���.
        sentences.push_back(sentence);
        cout << "������ ���������� �߰��Ǿ����ϴ�!\n\n";
        saveSentence();
    } else {
        cout << "�̹� �����ϴ� �����Դϴ�!\n\n";
    }
}


// ������ �����ϴ� �Լ�.
void Sentence::deleteSentence(string sentence) {
    // �����Ϸ��� ������ �����ϴ��� Ȯ��.
    auto it = find(sentences.begin(), sentences.end(), sentence);

    if(it == sentences.end()) {
        cout << "�ش� ������ ���Ͽ� �������� �ʽ��ϴ�!\n\n";
    } else {
        int loc = it-sentences.begin(); // �ش� ������ ��ġ�ϴ� �ε��� ����.
        sentences.erase(sentences.begin() + loc);
        cout << "���������� �����Ǿ����ϴ�!\n\n";
        saveSentence();
    }
}

// ������ �����ϴ� �Լ�.
void Sentence::saveSentence() {
    fstream sentence_file;
    sentence_file.open(file_path, ios::out);

    for(int i=0; i<sentences.size(); i++) {
        sentence_file << sentences[i] << "\n";
    }

    sentence_file.close();
}