#pragma once
#pragma once

// C���� ��� ����
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		
#include <string.h>

// Window ��� ����
#include <Windows.h>

// ��ũ�� ����
#define AND	&&
#define OR		||
#define SEED()	srand((unsigned)time(NULL))		// �õ�(Seed)�� ����
#define random(a,b)	(rand() %b + a)				// ����(a ~ b)
#define CLEAR() system("cls")						// ��� ȭ���� �����
#pragma warning (disable:4996)						// ����(_s)���� �Լ� ����X

// ��� ����
enum { LEN = 20, MAX_LEN = 6, MAX_CNT = 10, CLEAR = 40 };
enum { IX = 55, IY = 4 };

typedef int bool;

// ����ü
typedef struct HORSE
{
	char* name;		// �̸�
	int			xpos;			// �̵� �Ÿ�
	int			ypos;			// ȭ�鿡 ����� y��ǥ
	int			grade;			// ���
	double	time;			// ���� �ð�
	bool		finish;			// ���� ���� �˻�
}Horse;

// �Լ� ����
void	gotoxy(int x, int y);					// (x, y)�� �̵�
int		Intro();
void	InitHorse(Horse*, int);				// ��ü �ʱ�ȭ �Լ�
void	SetName(Horse*, int);				// �̸� �����Ҵ�
void	DeleteHorse(Horse*, int);		// �̸� �޸� ���� �� ��ü �޸� ����
bool	CheckClear(Horse*, int);			// ��� ������ �����ߴ��� ���� �˻�
void	Game(Horse*, int);
void	Game1(Horse*, int);
void	Game2(Horse*, int);
