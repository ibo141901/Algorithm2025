#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "거슬러 줄 금액을 입력하세요: ";
    cin >> amount;

    int coins[] = { 500, 100, 50, 10 };
    int count[4] = { 0 };

    for (int i = 0; i < 4; i++) {
        count[i] = amount / coins[i];   // 해당 동전 개수
        amount %= coins[i];            // 남은 금액
    }

    cout << "500원: " << count[0] << "개\n";
    cout << "100원: " << count[1] << "개\n";
    cout << "50원: " << count[2] << "개\n";
    cout << "10원: " << count[3] << "개\n";

    return 0;
}

