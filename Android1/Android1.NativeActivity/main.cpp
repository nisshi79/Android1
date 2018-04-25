#include "DxLib.h"

// プログラムは android_main から始まります

int getMod(int a, int b) {
	int buf = a % b;
	if (buf < 0)buf += b;
	return buf;
}
int android_main(void)
{
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}

	int a[9][9];
	int A[3][3];
	
	int ABC;
	int ott;

	for (int x = 0; x < 9; x++) {
			
		A[x/3][x%3] = x;
		if (GetRand(8) == x)A[x / 3][x % 3] = 100;
	}
	
	for(int x = 0; x < 9; x++){
		for (int y = 0; y < 9; y++) {
			ABC = getMod(x % 3 + y % 3,3);
			ott =  getMod(x / 3 +(y - 1) + y / 3, 3);
			a[x][y] = A[ABC][ott];
			DrawFormatString(x*(600 / 9)+50, y*(400 / 9)+50, GetColor(255, 255, 255),"%d",a[x][y]);
		}
	}
	
	/*DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), TRUE);*/	// 四角形を描画する

	WaitKey();				// キー入力待ち

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;					// ソフトの終了 



}
