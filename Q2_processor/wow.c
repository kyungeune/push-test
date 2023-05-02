#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>

//13305261530450734933 -> ������ ����
long long reverse_number(long long n) { //unsigned long long�� 64bit���ڱ����ۿ��ȳ���. overflow�� ���� ������ �����ϰ� �Ǵ� ��.
    long long ret = 0;
    int remainder = 0;

    while (n != 0) {
        remainder = n % 10;
        ret = ret * 10;
        ret = ret + remainder;
        n = n / 10;
        //printf("ret: %llu n: %llu\n", ret, n);
    }

    return ret;
}

int main(void) {
    long long number1, number2;
    long long input_number;
    long long count = 0;

    scanf("%llu", &input_number);

    number1 = input_number;

    number2 = reverse_number(number1);
    while (number1 != number2) {
        count++;
        number1 = number2 + number1;
        number2 = reverse_number(number1);
        if (count > 1000) {
            printf("NaN\n");
            return;
        }

    }

    printf("%d %llu\n", count, number1);
}