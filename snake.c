#include<stdio.h>
#include<windows.h>
//#include<time.h>
#include<stdlib.h>

#define left 75
#define right 77
#define upper 72
#define lower 80 


int W=52;
int H=22;


struct xy
{
	int x;
	int y;
};
struct xy food;
struct sn{
	int lend;
	struct xy body[100];
};
struct sn snake;




void gotoxy(int x, int y);
void snake_food();
void snake_map(int W,int H);
void snake_make(void);
int snake_ai();
int snake_withfood(int i);






int main(int argc,char const *argv[])
{
	int a,b,as=1,i=0;
	snake_map(W,H);snake_food();
	snake_make();
	
	while(snake_ai())
	{
		if(_kbhit()){
		a=getch();
		b=getch();
	}

	as=	snake_move(b,as);
	i=snake_withfood(i);
		Sleep(200);
	}
	gotoxy(W/2,H+2);
	printf("i=%d",i);
	gotoxy(0,30);
	return 0;
}





void gotoxy(int x, int y) {
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

int snake_withfood(int i)
{
	if(snake.body[0].x==food.x&&snake.body[0].y==food.y)
	{
		snake.lend++;
		i++;
		snake_food();
	}
	return i;
}


int snake_ai()
{
	int a=1,i;
	if(snake.body[0].x==0||snake.body[0].x==W-1||snake.body[0].y==0||snake.body[0].y==H-1)
	{
		system("cls");
		gotoxy(W/2-2,H/2-1);
		printf("OVER");
		a=0;
	}
	for(i=1;i<snake.lend;i++)
	{
		if(snake.body[0].x==snake.body[i].x&&snake.body[0].y==snake.body[i].y)
		{
		system("cls");
		gotoxy(W/2-2,H/2-1);
		printf("OVER");
		a=0;
		}
	}
	return a;
}

void snake_food()
{
	srand((unsigned)time(NULL));
	food.x=rand()%50+1;
	food.y=rand()%20+1;
//	if(food.x!=0||food.x!=W-1||food.y!=0||food.y!=H-1)
//	{
	gotoxy(food.x,food.y);
	printf("O");
//	}else snake_food();
	gotoxy(snake.body[snake.lend-1].x,snake.body[snake.lend-1].y);
}

void snake_map(int W,int H)
{
	int i;
	for(i=0;i<W;i++)
	{
		gotoxy(i,0);
		printf("#");
		gotoxy(i,H);
		printf("#");
	}
	for(i=0;i<H;i++)
	{
		gotoxy(0,i);
		printf("#");
		gotoxy(W-1,i);
		printf("#");
	}
}



void snake_make(void)
{
	snake.lend=3;
	snake.body[0].x=22;
	snake.body[0].y=12;
	int i;
	for(i=1;i<snake.lend;i++)
	{
		snake.body[i].x=snake.body[i-1].x-1;
		snake.body[i].y=snake.body[i-1].y;
	}
	for (i=0;i<snake.lend;i++)
	{
		gotoxy(snake.body[i].x,snake.body[i].y);
		if(i==0) printf("0");
		else printf("#");
	}
	gotoxy(snake.body[snake.lend-1].x,snake.body[snake.lend-1].y);
}

int snake_move(int b,int as)
{
	int i;
	if(b==right&&as!=2)
	{
		for(i=snake.lend;i>=0;i--)
		{
			if(i==0) snake.body[0].x++;
			else {
				snake.body[i].x=snake.body[i-1].x;
				snake.body[i].y=snake.body[i-1].y;
			}
		}
		for(i=0;i<=snake.lend;i++)
		{
			if(i==0){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("0");
			}
			else if(i!=snake.lend)
			{
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("#");
			}
			else {
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf(" ");
			}
		}
		as=1;
	}
	else if(b==left&&as!=1)
	{
		for(i=snake.lend;i>=0;i--)
		{
			if(i==0) snake.body[i].x--;
			else {
				snake.body[i].x=snake.body[i-1].x;
				snake.body[i].y=snake.body[i-1].y;
			}
		}
		for(i=0;i<=snake.lend;i++)
		{
			if(i==0){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("0");
			}else if(i!=snake.lend){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("#");
			}else {
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf(" ");
			}
		}
		as=2;
	}
	else if(b==upper&&as!=4)
	{
		for(i=snake.lend;i>=0;i--)
		{
			if(i==0) snake.body[i].y--;
			else {
				snake.body[i].x=snake.body[i-1].x;
				snake.body[i].y=snake.body[i-1].y;
			}
		}
		for(i=0;i<=snake.lend;i++)
		{
			if(i==0){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("0");
			}else if(i!=snake.lend){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("#");
			}else {
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf(" ");
			}
		}
		as=3;
	}
	else if(b==lower&&as!=3)
	{
		for(i=snake.lend;i>=0;i--)
		{
			if(i==0){
				snake.body[i].y++;
			}else {
				snake.body[i].x=snake.body[i-1].x;
				snake.body[i].y=snake.body[i-1].y;
			}
		}
		for(i=0;i<=snake.lend;i++)
		{
			if(i==0){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("0");
			}else if(i!=snake.lend){
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf("#");
			}else {
				gotoxy(snake.body[i].x,snake.body[i].y);
				printf(" ");
			}
		}
		as=4;
	}
	gotoxy(snake.body[snake.lend-1].x,snake.body[snake.lend-1].y);
	return as;
}
