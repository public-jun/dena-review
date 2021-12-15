#include <Board.hpp>
#include <Player.hpp>
#include <Master.hpp>

int main(void)
{
	Board board;
	Player first(Player::kP1);
	Player second(Player::kP2);
	Master master(board, first, second);

	bool is_continue = true;

	// std::cout << CLEAR << std::endl;
	while (is_continue)
	{
		master.inputNum();
		//勝利判定
		master.judgeWinner(is_continue);
		master.changeTurn();
		master.printBoard();
	}
	return (0);
}
