#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

//要判断一个数是否是两个质数的乘积，并找到其最大的质数因子，可以按照以下步骤进行：

//1.判断质数：首先判断一个数是否是质数。质数是指大于 1 的自然数，且只能被 1 和它本身整除。
//2.因子分解：对于给定的数 n，分解它为质数因子。我们需要检查 n 是否可以表示为两个质数的乘积。
//3.输出最大质数因子：如果 n 是两个质数的乘积，输出其中最大的质数因子。

// 判断一个数是否是质数
int is_prime(int n) {
    if (n <= 1) return 0;  // 1 不是质数
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;  // 如果能整除，则不是质数
    }
    return 1;  // 是质数
}



// 主函数
int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("没有质数因子\n");
        return 0;
    }

    int factor1 = 0, factor2 = 0;

    // 查找质数因子
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && is_prime(i)) {
            int other_factor = n / i;
            if (is_prime(other_factor)) {
                factor1 = i;
                factor2 = other_factor;
                break;  // 找到两个质数因子后退出
            }
        }
    }

    if (factor1 > 0 && factor2 > 0) {
        // 输出最大的质数因子
        printf("最大质数因子是：%d\n", factor1 > factor2 ? factor1 : factor2);
    }
    else {
        printf("无法表示为两个质数的乘积\n");
    }

    return 0;
}
