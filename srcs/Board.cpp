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
	std::cout << CLEAR << std::endl;
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

void Board::bePlacedPiece(int piece, int col)
{
	if (col < 1 || col > 7)
	{
		throw(BoardException("1 ~ 7を入力してください"));
	}
	for (int i = 0; i < kHeight; ++i)
	{
		if (board_[kHeight - i - 1][col - 1] == 0)
		{
			board_[kHeight - i - 1][col - 1] = piece;
			return ;
		}
	}
	throw(BoardException("この行には駒は置けません"));
}

Board::BoardException::BoardException(const char *msg)
	:msg_(msg) {}

const char *Board::BoardException::what() const throw()
{
	return (msg_);
}
