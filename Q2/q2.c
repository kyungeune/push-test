#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdint.h>
int calculateReverse(int n[], int length, int arr)
{
	int number = 0;
	number = n[length - arr - 1];
	return number;
}
int main(void)
{
	int number1[1000]={0}, number2[1000]={0}, number[1000]={0};
	int count=0, i=0, num=0, num1Length=0, dansun=0, length=0, j=0, same=0; //dansun=2049
	scanf("%d", &dansun);
	
	while(dansun>0) {
		number[i] = dansun % 10;
		i++;
		dansun /= 10;
	}
	number[i] = '\0';
	for (length = 0; number[length] != '\0'; length++);
	for (num = 0; num < length; num++)
		number1[num] = calculateReverse(number, length, num);

	i = 0;
	while (number1[i] != number2[i]) {
		i++;
		count++;
		num1Length = 0;
		same = 0;
		for (num1Length = 0; number1[num1Length] != '\0'; num1Length++); 
		for (num = 0; num < num1Length; num++)
			number2[num] = calculateReverse(number1, num1Length, num);
		number2[num] = '\0';
		
		for (j = 0; j < num1Length; j++) {
			if (number1[j] != number2[j])
			{
				//number1에 number2를 넣어라.
				for (num = 0; num < num1Length; num++)
					number1[num] = number2[num];
				number1[num] = '\0';
				break;
			}
			else {
				for (num = 0; num < num1Length; num++) {
					if (number1[num] == number2[num])
						same = 1;
				}
				if (same == 1)
					break;
			}
		}
		i = 0;
	}

	printf("%d ", count);
	for (i = 0; number2[i] != '\0'; i++) {
		printf("%d", number2[i]);
	}
}