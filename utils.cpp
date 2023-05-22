#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, double> checkCorrect(string input, string answer) {
    // 정확도 측정
    // TODO: 현재 문자열 비교는 멀티바이트를 통하여 비교. 그러나, (안 녕하, 안녕 하)를 비교하면, 3바이트 차이로 정확도가 3개 잘못된 것으로 나옴.
    // 이를 유니코드로 변환하여 비교하는 과정 필요.
    int correct = 0;
    for (int i=0; i<input.length(); i++) {
        if(i>answer.length()) {
            break;
        }
        if(input[i] == answer[i]){
            correct++;
        }
    }

    return {input.length() - correct, double(correct) / double(answer.length()) * 100};
}