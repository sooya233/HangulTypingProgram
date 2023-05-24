#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, double> checkCorrect(string input, string answer) {
    // 정확도 측정
    int correct = 0;

    // 두 입력을 유니코드로 변경
    wstring unicode_input(input.begin(), input.end());
    wstring unicode_answer(answer.begin(), answer.end());

    for (int i=0; i<unicode_input.length(); i++) {
        if(i>unicode_answer.length()) {
            break;
        }
        if(unicode_input[i] == unicode_answer[i]){
            correct++;
        }
    }

    return {input.length() - correct, double(correct) / double(answer.length()) * 100};
}