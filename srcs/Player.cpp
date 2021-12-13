#include <Player.hpp>

Player::Player() {}

Player::Player(int piece) : piece_(piece), move_(-1) {}

Player::Player(const Player &other)
{
	*this = other;
}

Player &Player::operator=(const Player &other)
{
	piece_ = other.getPiece();
	move_ = other.getMove();
	return (*this);
}

Player::~Player() {}


int Player::getPiece() const
{
	return (piece_);
}

int Player::getMove() const
{
	return (move_);
}
