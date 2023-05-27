#include <iostream>
#include <string>
#include <ctime>
#include "Word.h"
#include "Sentence.h"
#include "Wordgame.h"
#include "Sentencegame.h"
#include "utils.h"
#include "PaperGame.h"
using namespace std;


const string script_main = "�ȳ��ϼ���. �ѱ� Ÿ�ڿ����� ���α׷��Դϴ�.\n"\
"�ܾ� ����, ª�� ���� ����, �� �� ������ �����մϴ�.\n"\
"1. �ܾ� ����\n"\
"2. ���� ����\n"\
"3. �ܾ� ����\n"\
"4. ���� ����\n"\
"5. �� �� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_word_modify = "�ܾ� ������ �����ϼ̽��ϴ�.\n"\
"�ܾ� ����, �ܾ� �߰�, �ܾ� ������ �����մϴ�.\n"\
"1. �ܾ� ����\n"\
"2. �ܾ� �߰�\n"\
"3. �ܾ� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_sentence_modify = "���� ������ �����ϼ̽��ϴ�.\n"\
"���� ����, ���� �߰�, ���� ������ �����մϴ�.\n"\
"1. ���� ����\n"\
"2. ���� �߰�\n"\
"3. ���� ����\n"\
"------------------------------------------------\n"\
"���Ͻô� �ɼ��� �����ϼ���.";

const string script_word_game = "�ܾ� ������ �����ϼ̽��ϴ�.\n"\
"�ܾ� ������ ���۵˴ϴ�.\n"\
"------------------------------------------------\n";

const string script_sentence_game = "���� ������ �����ϼ̽��ϴ�.\n"\
"���� ������ ���۵˴ϴ�.\n"\
"------------------------------------------------\n";

int main() {
    while(true) {
        int input;
        cout << script_main;
        cin >> input;
        cin.ignore();
        cout << endl;
        
        switch (input)
        {

        // �ܾ� �߰�/���� ��� ���� �� ����
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
                    cout << "�߰��� �ܾ �Է��� �ּ���." << endl;
                    string word;
                    getline(cin, word);

                    w.addWord(word);
                    break;
                }
                case 3:
                {
                    cout << "������ �ܾ �Է��� �ּ���." << endl;
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
        
        // ���� �߰�/���� ��� ���� �� ����
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
                    cout << "�߰��� ������ �Է��� �ּ���." << endl;
                    string sentence;
                    getline(cin, sentence);

                    s.addSentence(sentence);
                    break;
                }
                case 3:
                {
                    cout << "������ ������ �Է��� �ּ���." << endl;
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

        // �ܾ����
        case 3:
        {   
            cin.clear();
            cout << script_word_game;
            int count = 10; // �⺻ 10��
            WordGame *wg = new WordGame(count);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            for(int i=0; i<count; i++) {
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
                total_time += end-start;

                cout << "���൵ : [" << i+1 << "/" << count << "] ��Ÿ �� : " << incorrect << " ��Ȯ�� : " << correct << "% �ҿ�ð� : " << (end-start)/1000.0 << "(��)" << endl << endl; 
            }

            cout << "�ܾ� ������ �Ϸ�Ǿ����ϴ�." << endl;
            cout << "��Ÿ �� : " << total_incorrect << " ��Ȯ�� : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% �ҿ�ð� : " << total_time/1000.0 << "(��)" << endl << endl;
            delete wg;

            break;
        }

        // �������
        case 4:
        {   
            cout << script_sentence_game;
            int count = 10; // �⺻ 10��
            SentenceGame *sg = new SentenceGame(count);
            int total_incorrect = 0;
            int total_length = 0;
            double total_time = 0;

            for(int i=0; i<count; i++) {
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
                total_time += end-start;

                cout << "���൵ : [" << i+1 << "/" << count << "] ��Ÿ �� : " << incorrect << " ��Ȯ�� : " << correct << "% �ҿ�ð� : " << (end-start)/1000.0 << "(��)" << endl << endl; 
            }

            cout << "���� ������ �Ϸ�Ǿ����ϴ�." << endl;
            cout << "��Ÿ �� : " << total_incorrect << " ��Ȯ�� : " << ((double)total_length - (double)total_incorrect) / (double)total_length * 100 << "% �ҿ�ð� : " << total_time/1000.0 << "(��)" << endl << endl;
            delete sg;

            break;
        }

        // �� �� ����
        case 5:
        {
            PaperGame pg;
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

    return 0;
}