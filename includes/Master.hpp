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

		void inputNum();
		void printBoard();
		void changeTurn();

	private:
		Master();
		Master(const Master &);
		Master &operator=(const Master &);
		Board &board_;
		Player *tmp_;
		Player &p1_;
		Player &p2_;

};

#endif
