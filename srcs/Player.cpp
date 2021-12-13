#include <Player.hpp>

Player::Player() {}

Player::Player(int order) : order_(order), move_(-1) {}

Player::Player(const Player &other)
{
	*this = other;
}

Player &Player::operator=(const Player &other)
{
	order_ = other.getOrder();
	move_ = other.getMove();
	return (*this);
}

Player::~Player() {}


int Player::getOrder() const
{
	return (order_);
}

int Player::getMove() const
{
	return (move_);
}
