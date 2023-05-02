#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int get_cycle_number(int n)
{
	int count = 1;
	while (n != 1) {
		printf("%d ", n);
		count++;
		if (n % 2 == 0)
			n /= 2;
		else
			n = n * 3 + 1;
	}
	printf("1\n");
	return count;
}
int main(void)
{
	int n, length;
	scanf("%d", &n);
	length = get_cycle_number(n);
	printf("사이클의 길이: %d",length);
}