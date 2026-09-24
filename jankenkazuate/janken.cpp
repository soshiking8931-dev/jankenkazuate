#include"include.h"
#include"janken.h"
#include"rand.h"

void showHand(const int* hand, int size)
{
	for (int a = 0;a < size;++hand,++a)
	{
		if (a == 0)
		{
			cout << "あなたは";
		}
		else if(a != 0)
		{
			cout << "cpuは";
		}

		switch (playhand(*hand))
		{
		case グー:
			cout << "グーをだした！" << endl;
			break;
		case チョキ:
			cout << "チョキをだした！" << endl;
			break;
		case パー:
			cout << "パーをだした！" << endl;
			break;
		}
	}
}

int cpuHand()
{
	return rand() % 3;
}

void janken()
{
	bool finish = true;
	srand((unsigned int)time(NULL));
	while (finish == true)
	{
		int playhand[2] = { 0, cpuHand()};
		int size = sizeof(playhand) / sizeof(playhand[0]);
		cout << "じゃんけんゲーム！" << endl
			<< endl
			<< "何を出す？,,, 0,,,グー　1,,,チョキ　2,,,パー" << endl
			<< " >> " << flush;
		cin >> playhand[0];
		if (playhand[0] > 2 || playhand[0] < 0)
		{
			cout << "有効な値を入力してやり直してね。" << endl;
			break;
		}
		else
		{
			showHand(playhand, size);
		}

		switch (winJuge((playhand[0] - playhand[1] + 2) % 3))
		{
		case DLOW:
			cout << "あいこ！やり直し" << endl;
			break;
		case LOSE:
			cout << "あなたのまけ" << endl;
			finish = false;
			break;
		case WIN:
			cout << "あなたのかち" << endl;
			finish = false;
			break;
		}

	}
	

}