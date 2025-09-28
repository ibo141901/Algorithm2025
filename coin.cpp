#include <iostream>
using namespace std;

int main() {
    int amount;
    cout << "�Ž��� �� �ݾ��� �Է��ϼ���: ";
    cin >> amount;

    int coins[] = { 500, 100, 50, 10 };
    int count[4] = { 0 };

    for (int i = 0; i < 4; i++) {
        count[i] = amount / coins[i];   // �ش� ���� ����
        amount %= coins[i];            // ���� �ݾ�
    }

    cout << "500��: " << count[0] << "��\n";
    cout << "100��: " << count[1] << "��\n";
    cout << "50��: " << count[2] << "��\n";
    cout << "10��: " << count[3] << "��\n";

    return 0;
}

