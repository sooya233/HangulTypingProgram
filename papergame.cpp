#include <string>
#include <filesystem>
#include <iostream>
#include <fstream>
#include "Papergame.h"
using namespace std;

PaperGame::PaperGame() {
	string paper_path = "./Default/Papers";
	for (auto &it : filesystem::directory_iterator(paper_path)) {
		string temp_path = it.path().string();
		paths.push_back(temp_path);

		string temp_title = temp_path.substr(paper_path.length() + 1);
		titles.push_back(temp_title);
	}
}

void PaperGame::showPapers() {
	cout << "index\t" << "title\t" << endl;

	for (int i = 0; i < titles.size(); i++) {
		cout << i+1 << "\t" << titles[i] << endl;
	}
}

void PaperGame::selectPaper(int index) {
	path = paths[index - 1];

	paper.open(path);
	string sentence;
	while (getline(paper, sentence)) {
		sentences.push_back(sentence);
	}
	paper.close();
}

int PaperGame::getLines() {
	return sentences.size();
}

string PaperGame::getSentence(int index) {
	return sentences[index];
}