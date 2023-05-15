#include <iostream>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

const string short_sentence[5] = {
    "�ȳ��ϼ���. ��ȭ���α׷��� ������Ʈ�Դϴ�.",
    "�ش� ������ üũ�� ���� �����Դϴ�.",
    "�ӵ�, ��Ȯ��, �ð��� �����մϴ�.",
    "������Ʈ �����ϰ� �ͽ��ϴ�.",
    "���� �� ������ ���ڽ��ϴ�."
};

const string script = "�ȳ��ϼ���. �ѱ� Ÿ�ڿ����� ���α׷��Դϴ�."\
"�ܾ� ����, ª�� ���� ����, �� �� ������ �����մϴ�."\
"1. �ܾ� ����"\
"2. ª�� ���� ����"\
"3. �� �� ����"\
"------------------------------------------------"\
"���Ͻô� �ɼ��� �����ϼ���.";

int main() {
    int input;
    cout << script;
    cin >> input;

    //TODO: ���ϴ� �ɼ��� ���Ͽ� �ܾ�/����/��� ���� ��� ���� �� ����
    
    clock_t start, end;
    for(int i=0; i<5; i++) {
        cout << "���൵ [" << i << "/5]" << endl;
        if(cin.fail()) { // ���� ����
            cin.clear();
        }

        cout << short_sentence[i] << endl;

        // �ð� ����
        start = clock();
        string input;
        getline(cin, input);
        end = clock();

        double correct = checkCorrect(input, short_sentence[i]);

        cout << "�ҿ�ð� : " << (double)(end-start)/(double)1000 << "(��)" << endl;
        cout << "��Ȯ�� : " << correct << "%" << endl;
        cout << endl;
    }

    return 0;
}