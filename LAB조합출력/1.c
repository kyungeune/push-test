#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void pick(int n, int picked[], int m, int toPick)
{
	int smallest = 0, lastIndex, i;

	if (toPick == 0) { //처음 뽑는거면

	}

	if (m == toPick)
		smallest = 0;
	else
		smallest = m - toPick;

	for (i = smallest; i < n; i++) {

		pick(m, picked, m, toPick - 1);
	}
}
int main(void)
{
	int picked[4];
	pick(7, picked, 4, 4);
}