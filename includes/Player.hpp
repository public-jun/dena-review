#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	public:
		explicit Player(int piece);
		Player(const Player &other);
		Player &operator=(const Player &other);
		~Player();

		static const int kP1 = 1;
		static const int kP2 = -1;

		int getPiece() const;
		int getMoveCol() const;
		int getMoveRow() const;
		void setMoveCol(int col);
		void setMoveRow(int row);
		void setMove(int col, int row);

	private:
		Player();

		int piece_;
		int move_col_;
		int move_row_;
};

#endif
