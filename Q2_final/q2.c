#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
unsigned long long calcuateReserve(int n);
int isPalindrome(int num);
int main(void) {
    unsigned long long num, renum, checknum;
    int count = 0;
    scanf("%d", &num);
    checknum = num;
    do {
        renum = calcuateReserve(checknum);
        checknum = checknum + renum;
        count++;

        if (count >= 1000) {
            printf("NaN");
            break;
        }
    } while (isPalindrome(checknum) == 0); 

    if (isPalindrome(checknum))
    {
        printf("%d %d", count, checknum);
    }
}
unsigned long long calcuateReserve(int n) { 
    int x;
    unsigned long long y = 0;

    while (n > 0) {\
        x = n % 10; 
        n /= 10; 
        y = y * 10 + x; 
    }
    return y;
}
int isPalindrome(int num) {
    int x = 0, a;
    int n = num;
    while (n > 0) {
        a = n % 10;
        x = x * 10 + a;
        n /= 10;
    }
    return (num == x);
}