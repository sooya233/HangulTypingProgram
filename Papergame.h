#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

 class PaperGame{
 private:
     vector<string> paths;
     vector<string> titles;
     string path;
     fstream paper;
     vector<string> sentences;
 public:
     PaperGame(string data_path);
     void showPapers();
     void selectPaper(int index);
     int getLines();
     string getSentence(int index);
};