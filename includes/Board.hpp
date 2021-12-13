#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>

class Board
{
	public:
		Board();
		~Board();
		void printBoard() const;

	private:
		Board(const Board &other);
		Board &operator=(const Board &other);
		static const int kWidth = 7;
		static const int kHeight = 6;
		int board_[kHeight][kWidth];

		void printHeader() const;
		void printFooter() const;
};

#endif
