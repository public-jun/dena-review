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

	while (is_continue)
	{
		master.inputNum();
		master.judgeWinner(is_continue);
		master.isDraw(is_continue);
		master.changeTurn();
	}
	return (0);
}
