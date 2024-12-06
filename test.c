#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//Ҫ�ж�һ�����Ƿ������������ĳ˻������ҵ��������������ӣ����԰������²�����У�

//1.�ж������������ж�һ�����Ƿ���������������ָ���� 1 ����Ȼ������ֻ�ܱ� 1 ��������������
//2.���ӷֽ⣺���ڸ������� n���ֽ���Ϊ�������ӡ�������Ҫ��� n �Ƿ���Ա�ʾΪ���������ĳ˻���
//3.�������������ӣ���� n �����������ĳ˻���������������������ӡ�

// �ж�һ�����Ƿ�������
int is_prime(int n) {
    if (n <= 1) return 0;  // 1 ��������
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;  // �������������������
    }
    return 1;  // ������
}



// ������
int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("û����������\n");
        return 0;
    }

    int factor1 = 0, factor2 = 0;

    // ������������
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && is_prime(i)) {
            int other_factor = n / i;
            if (is_prime(other_factor)) {
                factor1 = i;
                factor2 = other_factor;
                break;  // �ҵ������������Ӻ��˳�
            }
        }
    }

    if (factor1 > 0 && factor2 > 0) {
        // ���������������
        printf("������������ǣ�%d\n", factor1 > factor2 ? factor1 : factor2);
    }
    else {
        printf("�޷���ʾΪ���������ĳ˻�\n");
    }

    return 0;
}
