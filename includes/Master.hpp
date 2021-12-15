#ifndef MASTER_HPP
#define MASTER_HPP

#include <Board.hpp>
#include <Player.hpp>
#include <color.hpp>
#include <iostream>
#include <string>

class Master
{
	public:
		explicit Master(Board &board, Player &p1, Player &p2);
		~Master();

		Board &getBoard();

		void inputNum();
		void printBoard();

		void judgeWinner(bool &is_continue);
		bool isVictoryCol(Board &board);
		bool isVictoryRow(Board &board);
		bool isVictorySlash(Board &board);
		bool isVictoryBackSlash(Board &board);
		void printWinner();

		void isDraw(bool &is_continue);

		void changeTurn();

	private:
		Master();
		Master(const Master &);
		Master &operator=(const Master &);

		static const int kWidth = 7;
		static const int kHeight = 6;
		static const int kMaxTurn = 42;
		int count_turns;
		Board &board_;
		Player *tmp_;
		Player &p1_;
		Player &p2_;
};

#endif
