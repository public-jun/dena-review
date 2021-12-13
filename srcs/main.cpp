#include <Board.hpp>
#include <Player.hpp>
#include <Master.hpp>

int main(void)
{
	Board board;
	Player first(Player::kCYAN);
	Player second(Player::kRED);
	Master master(board, first, second);

	bool is_continue = true;

	std::cout << CLEAR << std::endl;
	board.printBoard();
	while (is_continue)
	{
		master.inputNum();
		master.printBoard();
		master.changeTurn();
	}
	return (0);
}
