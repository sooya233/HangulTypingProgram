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

const string script_login_main = "�ȳ��ϼ���. �ѱ� Ÿ�ڿ����� ���α׷��Դϴ�.\n"\
"���� ������\n"\
"------------------------------------------------\n";

const string script_login_selectuser = "�α��� �Ϸ��� ������ �̸��� �Է��ϼ���.\n"\
"�߰���, ���� ����, ������ �����մϴ�.\n"\
"1. ���� ����\n"\
"2. ���� ����\n"\
"3. �Խ�Ʈ�� �α���\n"\
"�̸� : ���� �α���\n"\
"0. ���α׷� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_main = "�ȳ��ϼ���. �ѱ� Ÿ�ڿ����� ���α׷��Դϴ�.\n"\
"�ܾ� ����, ª�� ���� ����, �� �� ������ �����մϴ�.\n"\
"�Խ�Ʈ�� ���, �ܾ� ����, ���� ����, �� �� ���Ӹ� �����մϴ�.\n"\
"1. �ܾ� ����\n"\
"2. ���� ����\n"\
"3. �ܾ� ����\n"\
"4. ���� ����\n"\
"5. �� �� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_word_modify = "�ܾ� ������ �����ϼ̽��ϴ�.\n"\
"�ܾ� ����, �ܾ� �߰�, �ܾ� ������ �����մϴ�.\n"\
"0. ���� ȭ������\n"\
"1. �ܾ� ����\n"\
"2. �ܾ� �߰�\n"\
"3. �ܾ� ����\n"\
"4. �ܾ� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_sentence_modify = "���� ������ �����ϼ̽��ϴ�.\n"\
"���� ����, ���� �߰�, ���� ������ �����մϴ�.\n"\
"0. ���� ȭ������\n"\
"1. ���� ����\n"\
"2. ���� �߰�\n"\
"3. ���� ����\n"\
"4. ���� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_word_game = "�ܾ� ������ �����ϼ̽��ϴ�.\n"\
"�ܾ� ������ ���۵˴ϴ�.\n"\
"------------------------------------------------\n";

const string script_sentence_game = "���� ������ �����ϼ̽��ϴ�.\n"\
"���� ������ ���۵˴ϴ�.\n"\
"------------------------------------------------\n";

int menu(string username="Default") {
    while (true) {
        string data_path;
        if (username != "Default") {
            cout << username << "������ ȯ���մϴ�!" << endl << endl;
            data_path = "./Users/" + username;
        }
        else {
            cout << "�Խ�Ʈ�� ȯ���մϴ�!" << endl << endl;
            data_path = "./" + username;
        }

        cout << script_main;
        int input;
        cin >> input;
        cin.ignore();
        cout << endl;

        switch (input)
        {

         // �ܾ� �߰�/���� ��� ���� �� ����
        case 1:
        {
            // �Խ�Ʈ ���� ����
            if (username == "Default") {
                cout << "�Խ�Ʈ�� �ش� ����� ����� �� �����ϴ�!" << endl << endl;
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
                    cout << "�߰��� �ܾ �Է��� �ּ���." << endl;
                    string word;
                    getline(cin, word);

                    w.addWord(word);
                    break;
                }
                case 3:
                {
                    int index;
                    cout << "������ �ܾ��� �ε����� �Է��� �ּ���.";
                    cin >> index;
                    cin.ignore();

                    string word;
                    cout << "������ �ܾ �Է��� �ּ���." << endl;
                    getline(cin, word);

                    w.modifyWord(index, word);
                    break;
                }
                case 4:
                {
                    cout << "������ �ܾ �Է��� �ּ���." << endl;
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

        // ���� �߰�/���� ��� ���� �� ����
        case 2:
        {
            // �Խ�Ʈ ���� ����
            if (username == "Default") {
                cout << "�Խ�Ʈ�� �ش� ����� ����� �� �����ϴ�!" << endl << endl;
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
                    cout << "�߰��� ������ �Է��� �ּ���." << endl;
                    string sentence;
                    getline(cin, sentence);

                    s.addSentence(sentence);
                    break;
                }
                case 3:
                {
                    int index;
                    cout << "������ ������ �ε����� �Է��� �ּ���.";
                    cin >> index;
                    cin.ignore();

                    string sentence;
                    cout << "������ ������ �Է��� �ּ���." << endl;
                    getline(cin, sentence);

                    s.modifySentence(index, sentence);
                    break;
                }
                case 4:
                {
                    cout << "������ ������ �Է��� �ּ���." << endl;
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

        // �ܾ����
        case 3:
        {
            cin.clear();
            cout << script_word_game;
            int count = 10; // �⺻ 10��
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

                cout << "���൵ : [" << i + 1 << "/" << count << "] ��Ÿ �� : " << incorrect << " ��Ȯ�� : " << correct << "% �ҿ�ð� : " << (end - start) / 1000.0 << "(��)" << endl << endl;
            }

            cout << "�ܾ� ������ �Ϸ�Ǿ����ϴ�." << endl;
            cout << "��Ÿ �� : " << total_incorrect << " ��Ȯ�� : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% �ҿ�ð� : " << total_time / 1000.0 << "(��)" << endl << endl;
            delete wg;

            break;
        }

        // �������
        case 4:
        {
            cout << script_sentence_game;
            int count = 10; // �⺻ 10��
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

                cout << "���൵ : [" << i + 1 << "/" << count << "] ��Ÿ �� : " << incorrect << " ��Ȯ�� : " << correct << "% �ҿ�ð� : " << (end - start) / 1000.0 << "(��)" << endl << endl;
            }

            cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
            cout << "��Ÿ �� : " << total_incorrect << " ��Ȯ�� : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% �ҿ�ð� : " << total_time / 1000.0 << "(��)" << endl << endl;
            delete sg;

            break;
        }

        // �� �� ����
        case 5:
        {
            PaperGame pg(data_path);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            pg.showPapers();
            cout << "������ ���� �����ϼ���(index)" << endl;
            int index;
            cin >> index;
            cin.ignore();

            pg.selectPaper(index);
            cout << "���� ������ ���۵˴ϴ�.\n"\
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

                cout << "���൵ : [" << i + 1 << "/" << line_count << "] ��Ÿ �� : " << incorrect << " ��Ȯ�� : " << correct << "% �ҿ�ð� : " << (end - start) / 1000.0 << "(��)" << endl << endl;
            }

            cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
            cout << "��Ÿ �� : " << total_incorrect << " ��Ȯ�� : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% �ҿ�ð� : " << total_time / 1000.0 << "(��)" << endl << endl;
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
            cout << "������ ������ �̸��� �Է��ϼ��� : ";
            string name;
            getline(cin, name);

            user.createUser(name);
        }
        else if (login_input == "2") {
            cout << "������ ������ �̸��� �Է��ϼ��� : ";
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