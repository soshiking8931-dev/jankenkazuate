#include"include.h"
#include"janken.h"

int cpuHand(int x)
{
	return rand() % 3;
}

void janken()
{
	srand((unsigned int)time(NULL));
	int player = 0, cpu = 0;
	cout << "じゃんけんゲーム！" << endl
		<< endl
		<< "何を出す？,,, 1,,,グー　2,,,チョキ　3,,,パー" << endl
		<< " >> " << flush;
	cin >> player;

}