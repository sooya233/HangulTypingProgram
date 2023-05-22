#include <iostream>
#include <string>
#include <tuple>

using namespace std;

tuple<int, double> checkCorrect(string input, string answer) {
    // ��Ȯ�� ����
    // TODO: ���� ���ڿ� �񱳴� ��Ƽ����Ʈ�� ���Ͽ� ��. �׷���, (�� ����, �ȳ� ��)�� ���ϸ�, 3����Ʈ ���̷� ��Ȯ���� 3�� �߸��� ������ ����.
    // �̸� �����ڵ�� ��ȯ�Ͽ� ���ϴ� ���� �ʿ�.
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