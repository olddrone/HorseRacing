#include "Head.h"

int main(void)
{
	int num = 0;
	num = Intro();
	Horse* horse = (Horse*)malloc(sizeof(Horse) * num);
	InitHorse(&*horse, num);
	Game(&*horse, num);
	gotoxy(0, IY * num);
	DeleteHorse(&*horse, num);
	return 0;
}
