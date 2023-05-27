#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include "Word.h"
#include "Sentence.h"
#include "Wordgame.h"
#include "Sentencegame.h"
#include "PaperGame.h"
#include "utils.h"
#include "User.h"
using namespace std;

const string script_login_main = "안녕하세요. 한글 타자연습기 프로그램입니다.\n"\
"유저 프로필\n"\
"------------------------------------------------\n";

const string script_login_selectuser = "로그인 하려는 유저의 이름을 입력하세요.\n"\
"추가로, 유저 생성, 삭제가 가능합니다.\n"\
"1. 유저 생성\n"\
"2. 유저 삭제\n"\
"3. 게스트로 로그인\n"\
"이름 : 유저 로그인\n"\
"0. 프로그램 종료\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_main = "안녕하세요. 한글 타자연습기 프로그램입니다.\n"\
"단어 연습, 짧은 문장 연습, 긴 글 연습이 가능합니다.\n"\
"게스트의 경우, 단어 게임, 문장 게임, 긴 글 게임만 가능합니다.\n"\
"1. 단어 수정\n"\
"2. 문장 수정\n"\
"3. 단어 게임\n"\
"4. 문장 게임\n"\
"5. 긴 글 게임\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_word_modify = "단어 수정을 선택하셨습니다.\n"\
"단어 보기, 단어 추가, 단어 삭제가 가능합니다.\n"\
"0. 이전 화면으로\n"\
"1. 단어 보기\n"\
"2. 단어 추가\n"\
"3. 단어 수정\n"\
"4. 단어 삭제\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_sentence_modify = "문장 수정을 선택하셨습니다.\n"\
"문장 보기, 문장 추가, 문장 삭제가 가능합니다.\n"\
"0. 이전 화면으로\n"\
"1. 문장 보기\n"\
"2. 문장 추가\n"\
"3. 문장 수정\n"\
"4. 문장 삭제\n"\
"------------------------------------------------\n"\
"원하시는 옵션을 선택하세요.";

const string script_word_game = "단어 게임을 선택하셨습니다.\n"\
"단어 게임이 시작됩니다.\n"\
"------------------------------------------------\n";

const string script_sentence_game = "문장 게임을 선택하셨습니다.\n"\
"문장 게임이 시작됩니다.\n"\
"------------------------------------------------\n";

int menu(string username="Default") {
    while (true) {
        string data_path;
        if (username != "Default") {
            cout << username << "유저님 환영합니다!" << endl << endl;
            data_path = "./Users/" + username;
        }
        else {
            cout << "게스트님 환영합니다!" << endl << endl;
            data_path = "./" + username;
        }

        cout << script_main;
        int input;
        cin >> input;
        cin.ignore();
        cout << endl;

        switch (input)
        {

         // 단어 추가/삭제 모듈 선언 및 실행
        case 1:
        {
            // 게스트 권한 제어
            if (username == "Default") {
                cout << "게스트는 해당 기능을 사용할 수 없습니다!" << endl << endl;
                break;
            }
            Word w(data_path);
            while (true) {
                int flag = 1;

                cout << script_word_modify;
                int input2;
                cin >> input2;
                cin.ignore();
                cout << endl;

                switch (input2)
                {
                case 0:
                    flag = 0;
                    break;
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
                    int index;
                    cout << "수정할 단어의 인덱스를 입력해 주세요.";
                    cin >> index;
                    cin.ignore();

                    string word;
                    cout << "수정할 단어를 입력해 주세요." << endl;
                    getline(cin, word);

                    w.modifyWord(index, word);
                    break;
                }
                case 4:
                {
                    cout << "삭제할 단어를 입력해 주세요." << endl;
                    string word;
                    getline(cin, word);

                    w.deleteWord(word);
                    break;
                }
                default:
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
            // 게스트 권한 제어
            if (username == "Default") {
                cout << "게스트는 해당 기능을 사용할 수 없습니다!" << endl << endl;
                break;
            }
            Sentence s(data_path);
            while (true) {
                int flag = 1;

                cout << script_sentence_modify;
                int input2;
                cin >> input2;
                cin.ignore();
                cout << endl;

                switch (input2)
                {
                case 0:
                    flag = 0;
                    break;
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
                    int index;
                    cout << "수정할 문장의 인덱스를 입력해 주세요.";
                    cin >> index;
                    cin.ignore();

                    string sentence;
                    cout << "수정할 문장을 입력해 주세요." << endl;
                    getline(cin, sentence);

                    s.modifySentence(index, sentence);
                    break;
                }
                case 4:
                {
                    cout << "삭제할 문장을 입력해 주세요." << endl;
                    string sentence;
                    getline(cin, sentence);

                    s.deleteSentence(sentence);
                    break;
                }
                default:
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
            cin.clear();
            cout << script_word_game;
            int count = 10; // 기본 10개
            WordGame* wg = new WordGame(count, data_path);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            for (int i = 0; i < count; i++) {
                string word = wg->getWord(i);
                cout << word << endl;

                string ans;
                clock_t start, end;

                start = clock();
                getline(cin, ans);
                end = clock();

                int incorrect;
                double correct;
                incorrect = get<0>(checkCorrect(ans, word));
                correct = get<1>(checkCorrect(ans, word));

                total_incorrect += incorrect;
                total_length += word.length();
                total_time += end - start;

                cout << "진행도 : [" << i + 1 << "/" << count << "] 오타 수 : " << incorrect << " 정확도 : " << correct << "% 소요시간 : " << (end - start) / 1000.0 << "(초)" << endl << endl;
            }

            cout << "단어 게임이 완료되었습니다." << endl;
            cout << "오타 수 : " << total_incorrect << " 정확도 : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% 소요시간 : " << total_time / 1000.0 << "(초)" << endl << endl;
            delete wg;

            break;
        }

        // 문장게임
        case 4:
        {
            cout << script_sentence_game;
            int count = 10; // 기본 10개
            SentenceGame* sg = new SentenceGame(count, data_path);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            for (int i = 0; i < count; i++) {
                string sentence = sg->getSentence(i);
                cout << sentence << endl;

                string ans;
                clock_t start, end;

                start = clock();
                getline(cin, ans);
                end = clock();

                int incorrect;
                double correct;
                incorrect = get<0>(checkCorrect(ans, sentence));
                correct = get<1>(checkCorrect(ans, sentence));

                total_incorrect += incorrect;
                total_length += sentence.length();
                total_time += end - start;

                cout << "진행도 : [" << i + 1 << "/" << count << "] 오타 수 : " << incorrect << " 정확도 : " << correct << "% 소요시간 : " << (end - start) / 1000.0 << "(초)" << endl << endl;
            }

            cout << "문장 게임이 완료되었습니다." << endl;
            cout << "오타 수 : " << total_incorrect << " 정확도 : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% 소요시간 : " << total_time / 1000.0 << "(초)" << endl << endl;
            delete sg;

            break;
        }

        // 긴 글 게임
        case 5:
        {
            PaperGame pg(data_path);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            pg.showPapers();
            cout << "연습할 글을 선택하세요(index)" << endl;
            int index;
            cin >> index;
            cin.ignore();

            pg.selectPaper(index);
            cout << "문장 게임이 시작됩니다.\n"\
                "------------------------------------------------\n";

            int line_count = pg.getLines();
            for (int i = 0; i < line_count; i++) {
                string sentence = pg.getSentence(i);
                cout << sentence << endl;

                string ans;
                clock_t start, end;

                start = clock();
                getline(cin, ans);
                end = clock();

                int incorrect;
                double correct;
                incorrect = get<0>(checkCorrect(ans, sentence));
                correct = get<1>(checkCorrect(ans, sentence));

                total_incorrect += incorrect;
                total_length += sentence.length();
                total_time += end - start;

                cout << "진행도 : [" << i + 1 << "/" << line_count << "] 오타 수 : " << incorrect << " 정확도 : " << correct << "% 소요시간 : " << (end - start) / 1000.0 << "(초)" << endl << endl;
            }

            cout << "문장 게임이 완료되었습니다." << endl;
            cout << "오타 수 : " << total_incorrect << " 정확도 : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% 소요시간 : " << total_time / 1000.0 << "(초)" << endl << endl;
            break;
        }

        default:
            return 0;
        }
    }
}

int main() {
    while(true) {
        cout << script_login_main;
        User user;
        user.showUsers();

        string login_input;
        cout << script_login_selectuser;
        cin >> login_input;
        cin.ignore();

        if (login_input == "1") {
            cout << "생성할 유저의 이름을 입력하세요 : ";
            string name;
            getline(cin, name);

            user.createUser(name);
        }
        else if (login_input == "2") {
            cout << "삭제할 유저의 이름을 입력하세요 : ";
            string name;
            getline(cin, name);

            user.deleteUser(name);
        }
        else if (login_input == "3") {
            menu();
        }
        else if (login_input == "0") {
            break;
        }
        else {
            if (user.selectUser(login_input)) {
                string username = user.getUser();
                menu(username);
            }
        }
    }
    return 0;
}