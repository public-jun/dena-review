#include <Board.hpp>
#include <color.hpp>

Board::Board()
{
	for (int row = 0; row < kHeight; ++row)
	{
		for (int col = 0; col < kWidth; ++col)
		{
			board_[row][col] = 0;
		}
	}
}

Board::~Board() {}

void Board::printFooter() const
{
	for(int col = 0; col < kWidth; ++col)
	{
		std::cout << "  " << col + 1 << " ";
	}
	std::cout << std::endl;
}

void Board::printBoard() const
{
	for (int row = 0; row < kHeight; ++row)
	{
		for (int col = 0; col < kWidth; ++col)
		{
			std::cout << "|";
			if (board_[row][col] == 0)
				std::cout << "   " << std::flush;
			else if (board_[row][col] == 1)
				std::cout << CYAN << " O " << END << std::flush;
			else if (board_[row][col] == -1)
				std::cout << RED << " O " << END << std::flush;
		}
		std::cout << "|" << std::endl;
	}
	printFooter();
}
