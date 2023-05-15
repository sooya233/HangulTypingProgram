#include <iostream>
#include <string>
#include <ctime>
#include "utils.h"
using namespace std;

const string short_sentence[5] = {
    "안녕하세요. 심화프로그래밍 프로젝트입니다.",
    "해당 문장은 체크를 위한 문장입니다.",
    "속도, 정확도, 시간을 측정합니다.",
    "프로젝트 성공하고 싶습니다.",
    "제발 잘 됐으면 좋겠습니다."
};

const string script = "안녕하세요. 한글 타자연습기 프로그램입니다."\
"단어 연습, 짧은 문장 연습, 긴 글 연습이 가능합니다."\
"1. 단어 연습"\
"2. 짧은 문장 연습"\
"3. 긴 글 연습"\
"------------------------------------------------"\
"원하시는 옵션을 선택하세요.";

int main() {
    int input;
    cout << script;
    cin >> input;

    //TODO: 원하는 옵션을 통하여 단어/문장/긴글 연습 모듈 선언 및 실행
    
    clock_t start, end;
    for(int i=0; i<5; i++) {
        cout << "진행도 [" << i << "/5]" << endl;
        if(cin.fail()) { // 버퍼 비우기
            cin.clear();
        }

        cout << short_sentence[i] << endl;

        // 시간 측정
        start = clock();
        string input;
        getline(cin, input);
        end = clock();

        double correct = checkCorrect(input, short_sentence[i]);

        cout << "소요시간 : " << (double)(end-start)/(double)1000 << "(초)" << endl;
        cout << "정확도 : " << correct << "%" << endl;
        cout << endl;
    }

    return 0;
}