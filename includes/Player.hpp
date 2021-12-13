#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	public:
		explicit Player(int piece);
		Player(const Player &other);
		Player &operator=(const Player &other);
		~Player();

		static const int kCYAN = 1;
		static const int kRED = -1;

		int getPiece() const;
		int getMove() const;

	private:
		Player();

		int piece_;
		int move_;
};

#endif
