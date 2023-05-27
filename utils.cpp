#include <iostream>
#include <algorithm>
#include <string>
#include <tuple>

using namespace std;

tuple<int, double> checkCorrect(string input, string answer) {
    // 정확도 측정
    int correct = 0;

    // 두 입력을 유니코드로 변경
    wstring unicode_input(input.begin(), input.end());
    wstring unicode_answer(answer.begin(), answer.end());

    int long_length = max(unicode_input.length(), unicode_answer.length());
    int short_length = min(unicode_input.length(), unicode_answer.length());
    for (int i=0; i<long_length; i++) {
        if(i>short_length) {
            break;
        }
        if(unicode_input[i] == unicode_answer[i]){
            correct++;
        }
    }

    return {long_length - correct, double(correct) / double(answer.length()) * 100};
}