#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int number1, number2, remainder1 = 0, remainder2 = 0, carry_count = 0, carry = 0;

	scanf("%d %d", &number1, &number2);

	while (number1!=0||number2!=0)
	{
		remainder1 = number1 % 10;
		remainder2 = number2 % 10;

		if (remainder1 + remainder2 + carry > 9) {
			carry_count += 1;
			carry = 1;
		}
		else
			carry = 0;

		number1 /= 10;
		number2 /= 10;
	}

	printf("%d", carry_count);
	return 0;
}