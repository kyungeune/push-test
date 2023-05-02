#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>

unsigned long long reverse_number(unsigned long long n) {
    uint64_t ret = 0;
    int remainder = 0;

    while (n != 0) {
        remainder = n % 10;
        ret = ret * 10;
        ret = ret + remainder;
        n = n / 10;
    }

    return ret;
}

int main(void) {
    unsigned long long num1, num2, number;
    int count = 0;

    scanf("%llu", &number);
    num1 = number;
    num2 = reverse_number(number);

    while (num1 != num2) {
        count++;
        number = num1;
        num1 += num2;
        num2 = reverse_number(num1);
        if (count > 1000) {
            printf("NaN\n");
            return;
        }

    }

    printf("%d %llu\n", count, num1);
}