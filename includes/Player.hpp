#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player
{
	public:
		explicit Player(int order);
		Player(const Player &other);
		Player &operator=(const Player &other);
		~Player();

		static const int kFirst = 1;
		static const int kLast = -1;

		int getOrder() const;
		int getMove() const;

	private:
		Player();

		int order_;
		int move_;
};

#endif
