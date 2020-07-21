#include "head.h"

void gotoxy(int x, int y)
{
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


int Intro()
{
	int cnt = 0;
	printf("�渶 ���� \n");
	while (TRUE)
	{
		printf("������ ���� ����<�ִ� 10>�� �Է��ϰ� enter : ");
		scanf("%d", &cnt);

		// 0���� �۰ų� 10���� ū ���� �Է��ϸ�
		if (0 < cnt AND cnt < 10)
			break;
		else
			printf("�ٽ� ���� �Է����ּ��� \n");
	}
	return cnt;
}

void InitHorse(Horse* horse, int num)
{
	int i;
	SetName(&*horse, num);
	for (i = 0; i < num; ++i)
	{
		// ��ü�� ��� ��� �ʱ�ȭ
		horse[i].grade = 0;
		horse[i].finish = FALSE;
		horse[i].time = 0;
		horse[i].xpos = 0;
	}

}

void SetName(Horse* horse, int num)
{
	char arr[LEN];
	for (int i = 0; i < num; ++i)
	{
		printf("%d�� �� �̸� : ", i + 1);
		while (TRUE)
		{
			scanf("%s", &arr);
			if (strlen(arr) > 6)			// �̸��� 3�� �̻��̸�
				printf("�ٽ� �Է��ϼ��� \n");
			else
				break;
		}
		horse[i].name = (char*)malloc(strlen(arr) + 1);
		strcpy(horse[i].name, arr);
	}
}

void DeleteHorse(Horse* h, int num)
{
	int idx;
	for (idx = 0; idx < num; ++idx)
	{
		if (h[idx].name != NULL)
			free(h[idx].name);							// name �޸� ����
	}
	free(h);												// horse �޸� ����
	printf("���� ����!");
}

bool CheckClear(Horse* horse, int num)
{
	int i;
	for (i = 0; i < num; ++i)
	{
		if (horse[i].finish == FALSE)
			return FALSE;
	}
	return TRUE;
}

void Game(Horse* horse, int num)
{
	CLEAR();
	Game1(&*horse, num);
	Game2(&*horse, num);
}

void Game1(Horse* horse, int num)
{
	CLEAR();
	int idx;
	gotoxy(IX, 0);
	printf("�ҿ� �ð� : ");
	gotoxy(0, 2);
	printf("<start>  1         10         20        30        40(end)  ���  �ð�(��)\n");
	printf("----------------------------------------------------------------------");
	for (idx = 0; idx < num; ++idx)
	{
		horse[idx].ypos = IY + idx * 2;
		gotoxy(0, horse[idx].ypos);
		printf("%s :", horse[idx].name);
	}
	gotoxy(0, IY + num * 2);				// ������ ���� ��
	printf("�ƹ� Ű�� ������ ���ָ� �����մϴ�.");
}

void Game2(Horse* horse, int num)
{
	SEED();
	double Time = 0.0, start, finish;
	int idx = 0, ch, mv, rank = 1;
	while (!(CheckClear(&*horse, num)))
	{
		if (kbhit())
		{
			start = clock();
			Sleep(100);
			ch = random(0, num);			// 0~num-1 ��° �ε���
			if (horse[ch].finish == TRUE)
				continue;
			mv = random(1, 2);			// 1~2 �̵� �Ÿ�
			if (horse[ch].finish == FALSE)
				horse[ch].xpos += mv;
			if (horse[ch].xpos >= CLEAR AND horse[ch].finish == FALSE)
			{
				horse[ch].xpos = CLEAR;
				horse[ch].finish = TRUE;
				horse[ch].grade = rank++;
				finish = clock();
				Time += ((double)(finish - start) / CLOCKS_PER_SEC);
				horse[ch].time = Time;
				gotoxy(18 + horse[ch].xpos, horse[ch].ypos);
				printf("%d��", horse[ch].grade);
				gotoxy(25 + horse[ch].xpos, horse[ch].ypos);
				printf("%.3lf", horse[ch].time);
			}
			gotoxy(10 + horse[ch].xpos, horse[ch].ypos);
			for (idx = 0; idx < 2; ++idx)
			{
				gotoxy(10 + horse[ch].xpos - 3 + idx, horse[ch].ypos);
				printf(" ");
			}
			printf(">%d", horse[ch].xpos);
			finish = clock();
			Time += ((double)(finish - start) / CLOCKS_PER_SEC);
			gotoxy(IX + 12, 0);
			printf("%.3lf��", Time);
		}
	}
}