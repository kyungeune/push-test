#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOARD_SIZE 3
void display(char b[][BOARD_SIZE]) //게임판 출력
{
	int i, j;
	printf("    0 1 2\n");
	printf("  -------");
	for (j = 0; j < BOARD_SIZE; j++)
	{
		printf("\n%d : ", j);
		for (i = 0; i < BOARD_SIZE; i++) {
			if (b[j][i] == 'X' || b[j][i] == 'O')
				printf("%c ", b[j][i]);
			else
				printf("  ");
		}
	}
	printf("\n");
}
int whoWins(char b[][3], char turn, int xi, int yi)
{
	int sum=0, x=0, y=0;

	x = xi;
	y = yi;
	while (b[x][y] == turn && y != -1) { //가로
		sum++; 
		y--;
	}
	x = xi;
	y = yi;
	sum -= 1;
	while (b[x][y] == turn && y<BOARD_SIZE) {
		sum++;
		y++;
	}
	if (sum == BOARD_SIZE)
		return 1;

	x = xi;
	y = yi;
	sum = 0;
	while (b[x][y] == turn && x != -1) { //세로
		sum++;
		x--;
	}
	x = xi;
	y = yi;
	sum -= 1;
	while (b[x][y] == turn && x < BOARD_SIZE) {
		sum++;
		x++;
	}
	if (sum == BOARD_SIZE)
		return 1;

	x = xi;
	y = yi;
	sum = 0;
	while (b[x][y] == turn && x != -1 && y!=-1) { //대각선 \모양
		sum++;
		x--;
		y--;
	}
	x = xi;
	y = yi;
	sum -= 1;
	while (b[x][y] == turn && x < BOARD_SIZE && y<BOARD_SIZE) {
		sum++;
		x++;
		y++;
	}
	if (sum == BOARD_SIZE)
		return 1;

	x = xi;
	y = yi;
	sum = 0;
	while (b[x][y] == turn && x != -1 && y < BOARD_SIZE) { //대각선 /모양
		sum++;
		x--;
		y++;
	}
	x = xi;
	y = yi;
	sum -= 1;
	while (b[x][y] == turn && x < BOARD_SIZE && y != -1) {
		sum++;
		x++;
		y--;
	}
	if (sum == BOARD_SIZE)
		return 1;
	
	return 0;
}
int main(void)
{
	char b[BOARD_SIZE][BOARD_SIZE], turn='X';
	int i, j, checkBoard = 0, finish = 0, x=0, y=0, rePut=1;
	for (i = 0; i < BOARD_SIZE; i++) //보드판 리셋
		for (j = 0; j < BOARD_SIZE; j++)
			b[i][j] = ' ';

	display(b);
	while (checkBoard < BOARD_SIZE* BOARD_SIZE)
	{
		rePut = 1;
		while (rePut == 1) //놓기
		{
			printf("Player %c(행 열):", turn);
			scanf("%d %d", &x, &y);
			if (x < BOARD_SIZE && y < BOARD_SIZE) {
				if (b[x][y] == ' ') {
					b[x][y] = turn;
					display(b);
					rePut = 0;
				}
			}
		}

		finish = whoWins(b, turn, x, y); //승리멘트 출력
		if (finish == 1)
		{
			printf("Player %c wins!", turn);
			break;
		}

		if (turn == 'X') //turn 바꾸기
			turn = 'O';
		else if (turn == 'O')
			turn = 'X';
		checkBoard+=1;
		if(checkBoard==BOARD_SIZE*BOARD_SIZE)
		{
			printf("Nobody wins!");
			break;
		}
	}
}