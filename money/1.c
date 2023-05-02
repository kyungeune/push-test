//³ª´Â ¶Ë¸ÛÃ»ÀÌ
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	long long i;
	int max = 0;

	for (i = 3; i < 1000000; i++) {
		if (i % 3 > max) {
			printf("%d\n", i);
			max = i%3;
			printf("%d\n", max);
		}
	}

	return 0;
}