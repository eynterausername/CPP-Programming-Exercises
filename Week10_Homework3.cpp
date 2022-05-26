#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	int w = 16, h = 8;
	MonsterWorld game(w, h);

	game.add(new Zombie("박수빈좀비", "◎", rand() % w, rand() % h));
	game.add(new Vampire("구지희박쥐", "★", rand() % w, rand() % h));
	game.add(new KGhost("강기천귀신", "♥", rand() % w, rand() % h));
	game.add(new Jiangshi("강인재강시", "↔", rand() % w, rand() % h, true));
	game.add(new Jiangshi("서지환강시", "↕", rand() % w, rand() % h, false));
	game.add(new Tuman("김흔수귀신", "좌", rand() % w, rand() % h));
	game.add(new Tuman("정현수귀신", "우", rand() % w, rand() % h));
	game.play(500, 10);
	printf("------게임 종료-------------------\n");
	getchar();
	getchar();
}