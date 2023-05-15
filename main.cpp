#include <iostream>
#include <string>
#include <ctime>
#include "Word.h"
#include "Sentence.h"
#include "utils.h"
using namespace std;

const string short_sentence[5] = {
    "�ȳ��ϼ���. ��ȭ���α׷��� ������Ʈ�Դϴ�.",
    "�ش� ������ üũ�� ���� �����Դϴ�.",
    "�ӵ�, ��Ȯ��, �ð��� �����մϴ�.",
    "������Ʈ �����ϰ� �ͽ��ϴ�.",
    "���� �� ������ ���ڽ��ϴ�."
};

const string script_main = "�ȳ��ϼ���. �ѱ� Ÿ�ڿ����� ���α׷��Դϴ�.\n"\
"�ܾ� ����, ª�� ���� ����, �� �� ������ �����մϴ�.\n"\
"1. �ܾ� ����\n"\
"2. ���� ����\n"\
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

        // �ܾ� �߰�/���� ��� ���� �� ����
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
        default:
            return 0;
        }
    }
    

    //TODO: ���ϴ� �ɼ��� ���Ͽ� �ܾ�/����/��� ���� ��� ���� �� ����

    // clock_t start, end;
    // for(int i=0; i<5; i++) {
    //     cout << "���൵ [" << i << "/5]" << endl;
    //     if(cin.fail()) { // ���� ����
    //         cin.clear();
    //     }

    //     cout << short_sentence[i] << endl;

    //     // �ð� ����
    //     start = clock();
    //     string input;
    //     getline(cin, input);
    //     end = clock();

    //     double correct = checkCorrect(input, short_sentence[i]);

    //     cout << "�ҿ�ð� : " << (double)(end-start)/(double)1000 << "(��)" << endl;
    //     cout << "��Ȯ�� : " << correct << "%" << endl;
    //     cout << endl;
    // }

    return 0;
}