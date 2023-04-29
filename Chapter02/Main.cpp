#include "Game.h"

int main(int argc, char **argv)
{
	// Gameインスタンスを生成
	Game game;

	// ゲームの初期化に成功したら、ゲームループを開始する
	bool success = game.Initialize();
	if (success)
	{
		game.RunLoop();
	}
	// ゲームの終了処理
	game.Shutdown();
	return 0;
}
