#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int H(int n)
{
	int i, sum=0;
	if (n == 1 || n == 0)
		return 1;
	for (i = 0; i < n; i++) {
		sum += H(n - 1 - i) * H(i);
	}
	return sum;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	printf("%d", H(n));
}