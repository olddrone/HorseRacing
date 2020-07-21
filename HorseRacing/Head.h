#pragma once
#pragma once

// C관련 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <time.h>		
#include <string.h>

// Window 헤더 파일
#include <Windows.h>

// 매크로 선언
#define AND	&&
#define OR		||
#define SEED()	srand((unsigned)time(NULL))		// 시드(Seed)값 설정
#define random(a,b)	(rand() %b + a)				// 난수(a ~ b)
#define CLEAR() system("cls")						// 출력 화면을 비워줌
#pragma warning (disable:4996)						// 보안(_s)관련 함수 에러X

// 상수 선언
enum { LEN = 20, MAX_LEN = 6, MAX_CNT = 10, CLEAR = 40 };
enum { IX = 55, IY = 4 };

typedef int bool;

// 구조체
typedef struct HORSE
{
	char* name;		// 이름
	int			xpos;			// 이동 거리
	int			ypos;			// 화면에 출력할 y좌표
	int			grade;			// 등수
	double	time;			// 주행 시간
	bool		finish;			// 도착 유무 검사
}Horse;

// 함수 선언
void	gotoxy(int x, int y);					// (x, y)로 이동
int		Intro();
void	InitHorse(Horse*, int);				// 객체 초기화 함수
void	SetName(Horse*, int);				// 이름 동적할당
void	DeleteHorse(Horse*, int);		// 이름 메모리 해제 및 객체 메모리 해제
bool	CheckClear(Horse*, int);			// 모든 말들이 도착했는지 유무 검사
void	Game(Horse*, int);
void	Game1(Horse*, int);
void	Game2(Horse*, int);
