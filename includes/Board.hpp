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
		Board(const Board &other);
		Board &operator=(const Board &other);

		int getPiece(int row, int col) const;
		void setPiece(int piece, int row, int col);

		void printBoard() const;
		int bePlacedPiece(int piece, int col);
		Board generateJudgeBoard(int piece);

		class BoardException : public std::exception
		{
			public:
				BoardException(const char *msg);
				virtual const char *what() const throw();

			private:
				const char *msg_;
		};

	private:
		static const int kWidth = 7;
		static const int kHeight = 6;
		int board_[kHeight][kWidth];

		void printFooter() const;
};

#endif
