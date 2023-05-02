#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	static int count = 0;
	printf("%d ", n);
	count++;
	if (n == 1)
		return count;
	if (n % 2 == 0) {
		n /= 2;
	}
	else {
		n = n * 3 + 1;
	}
	return get_cycle_number(n);
}
int main(void)
{
	int n, length;
	scanf("%d", &n);
	length = get_cycle_number(n);
	printf("\n사이클의 길이: %d", length);
}