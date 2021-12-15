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
		void changeTurn();
		void judgeWinner(bool &is_continue);
		bool is_victory_col(Board &board);

	private:
		Master();
		Master(const Master &);
		Master &operator=(const Master &);

		static const int kWidth = 7;
		static const int kHeight = 6;
		Board &board_;
		Player *tmp_;
		Player &p1_;
		Player &p2_;

};

#endif
