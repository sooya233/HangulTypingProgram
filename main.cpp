#include <iostream>
#include <string>
#include <ctime>
#include "Word.h"
#include "Sentence.h"
#include "utils.h"
using namespace std;

const string short_sentence[5] = {
    "안녕하세요. 심화프로그래밍 프로젝트입니다.",
    "해당 문장은 체크를 위한 문장입니다.",
    "속도, 정확도, 시간을 측정합니다.",
    "프로젝트 성공하고 싶습니다.",
    "제발 잘 됐으면 좋겠습니다."
};

const string script_main = "안녕하세요. 한글 타자연습기 프로그램입니다.\n"\
"단어 연습, 짧은 문장 연습, 긴 글 연습이 가능합니다.\n"\
"1. 단어 수정\n"\
"2. 문장 수정\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_word_modify = "단어 수정을 선택하셨습니다.\n"\
"단어 보기, 단어 추가, 단어 삭제가 가능합니다.\n"\
"1. 단어 보기\n"\
"2. 단어 추가\n"\
"3. 단어 삭제\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_sentence_modify = "문장 수정을 선택하셨습니다.\n"\
"문장 보기, 문장 추가, 문장 삭제가 가능합니다.\n"\
"1. 문장 보기\n"\
"2. 문장 추가\n"\
"3. 문장 삭제\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

int main() {
    Word w;
    Sentence s;
    while(true) {
        int input;
        cout << script_main;
        cin >> input;
        cin.ignore();
        cout << endl;

        
        switch (input)
        {

        // 단어 추가/삭제 모듈 선언 및 실행
        case 1:
        {
            while(true) {
                int flag = 1;

                cout << script_word_modify;
                int input2;
                cin >> input2;
                cin.ignore();
                cout << endl;

                switch (input2)
                {
                case 1:
                    w.show_words();
                    break;
                case 2:
                {
                    cout << "추가할 단어를 입력해 주세요." << endl;
                    string word;
                    getline(cin, word);

                    w.addWord(word);
                    break;
                }
                case 3:
                {
                    cout << "삭제할 단어를 입력해 주세요." << endl;
                    string word;
                    getline(cin, word);

                    w.deleteWord(word);
                    break;
                }
                default:
                    flag = 0;
                    break;
                }
                if (flag == 0) {
                    break;
                }
            }
            break;
        }
        
        // 문장 추가/삭제 모듈 선언 및 실행
        case 2:
        {
            while(true) {
                int flag = 1;

                cout << script_sentence_modify;
                int input2;
                cin >> input2;
                cin.ignore();
                cout << endl;

                switch (input2)
                {
                case 1:
                    s.show_sentences();
                    break;
                case 2:
                {
                    cout << "추가할 문장을 입력해 주세요." << endl;
                    string sentence;
                    getline(cin, sentence);

                    s.addSentence(sentence);
                    break;
                }
                case 3:
                {
                    cout << "삭제할 문장을 입력해 주세요." << endl;
                    string sentence;
                    getline(cin, sentence);

                    s.deleteSentence(sentence);
                    break;
                }
                default:
                    flag = 0;
                    break;
                }
                if (flag == 0) {
                    break;
                }
            }
            break;
        }
        default:
            return 0;
        }
    }
    

    //TODO: 원하는 옵션을 통하여 단어/문장/긴글 연습 모듈 선언 및 실행

    // clock_t start, end;
    // for(int i=0; i<5; i++) {
    //     cout << "진행도 [" << i << "/5]" << endl;
    //     if(cin.fail()) { // 버퍼 비우기
    //         cin.clear();
    //     }

    //     cout << short_sentence[i] << endl;

    //     // 시간 측정
    //     start = clock();
    //     string input;
    //     getline(cin, input);
    //     end = clock();

    //     double correct = checkCorrect(input, short_sentence[i]);

    //     cout << "소요시간 : " << (double)(end-start)/(double)1000 << "(초)" << endl;
    //     cout << "정확도 : " << correct << "%" << endl;
    //     cout << endl;
    // }

    return 0;
}