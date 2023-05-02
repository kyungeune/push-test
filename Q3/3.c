#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdint.h>
unsigned long long yes111(unsigned long long input_number)
{
	int num = 1;
	unsigned long long n = 1;

	n = num * input_number;

	while ( n>1 ) {
		if (n % 10 == 1)
			n /= 10;
		else {
			num += 1;
			n = input_number * num;
		}
	}

	return num * input_number;
}
int main(void)
{
	unsigned long long input_number, number;
	int count = 0, i;

	scanf("%llu", &input_number);
	
	number = yes111(input_number);
	while (number >= 1) {
		count++;
		number /= 10;
	}
	printf("%d", count);
}