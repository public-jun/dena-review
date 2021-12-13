#ifndef BOARD_HPP
#define BOARD_HPP

#include <Board.hpp>
#include <Player.hpp>
#include <iostream>
#include <string>
#include <exception>

class Board
{
	public:
		Board();
		~Board();
		void printBoard() const;

		void bePlacedPiece(int piece, int col);

		class BoardException : public std::exception
		{
			public:
				BoardException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

	private:
		Board(const Board &other);
		Board &operator=(const Board &other);
		static const int kWidth = 7;
		static const int kHeight = 6;
		int board_[kHeight][kWidth];

		void printFooter() const;
};

#endif
