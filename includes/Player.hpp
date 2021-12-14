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
		int getMove() const;

	private:
		Player();

		int piece_;
		int move_;
};

#endif
