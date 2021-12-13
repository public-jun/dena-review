#include <Board.hpp>
#include <Player.hpp>

int main(void)
{
	Board board;
	Player first(Player::kFirst);
	Player second(Player::kLast);
	// Player &tmp = first;

	bool is_continue = true;

	board.printBoard();
	while (is_continue)
	{
		//入力を求める
		std::string input;
		std::cout << "行番号(1 ~ 7)を入力してください" << std::endl;
		if (!std::getline(std::cin, input))
			break;
		//Boardにセット

		//表示
	}
	return (0);
}
