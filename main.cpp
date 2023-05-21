#include <iostream>
#include <string>
#include <ctime>
#include "Word.h"
#include "Sentence.h"
#include "Wordgame.h"
#include "Sentencegame.h"
#include "utils.h"
using namespace std;


const string script_main = "안녕하세요. 한글 타자연습기 프로그램입니다.\n"\
"단어 연습, 짧은 문장 연습, 긴 글 연습이 가능합니다.\n"\
"1. 단어 수정\n"\
"2. 문장 수정\n"\
"3. 단어 게임\n"\
"4. 문장 게임\n"\
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

const string script_word_game = "단어 게임을 선택하셨습니다.\n"\
"단어 게임이 시작됩니다.\n"\
"------------------------------------------------";

const string script_sentence_game = "문장 게임을 선택하셨습니다.\n"\
"문장 게임이 시작됩니다.\n"\
"------------------------------------------------";

int main() {
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
            Word w;
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
                    cin.ignore();

                    w.addWord(word);
                    break;
                }
                case 3:
                {
                    cout << "삭제할 단어를 입력해 주세요." << endl;
                    string word;
                    getline(cin, word);
                    cin.ignore();

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
            Sentence s;
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
                    cin.ignore();

                    s.addSentence(sentence);
                    break;
                }
                case 3:
                {
                    cout << "삭제할 문장을 입력해 주세요." << endl;
                    string sentence;
                    getline(cin, sentence);
                    cin.ignore();

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

        // 단어게임
        case 3:
        {   
            cout << script_word_game << endl;
            int count = 10; // 기본 10개
            WordGame *wg = new WordGame(count);

            for(int i=0; i<count; i++) {
                string word = wg->getWord(i);
                cout << word << endl;
                
                string ans;
                getline(cin, ans);

                // cout << word << ans << endl;
                cout << ans;
                
                // int incorrect;
                // double correct;
                // incorrect = get<0>(checkCorrect(ans, word));
                // correct = get<1>(checkCorrect(ans, word));

                // cout << "오타 수 : " << incorrect << " 정확도 : " << correct << endl << endl; 
            }

            delete wg;

            break;
        }

        // 문장게임
        case 4:
        {   
            cout << script_sentence_game;
            int count = 10; // 기본 10개
            SentenceGame *sg = new SentenceGame(count);

            for(int i=0; i<count; i++) {
                string sentence = sg->getSentence(i);
                cout << sentence << endl;

                string ans;
                getline(cin, ans);

                int incorrect;
                double correct;
                incorrect = get<0>(checkCorrect(ans, sentence));
                correct = get<1>(checkCorrect(ans, sentence));

                cout << "오타 수 : " << incorrect << " 정확도 : " << correct << endl << endl; 
            }

            delete sg;

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