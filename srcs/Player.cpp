#include <Player.hpp>

Player::Player() {}

Player::Player(int piece) : piece_(piece), move_col_(-1), move_row_(-1) {}

Player::Player(const Player &other)
{
	*this = other;
}

Player &Player::operator=(const Player &other)
{
	piece_ = other.getPiece();
	move_col_ = other.getMoveCol();
	return (*this);
}

Player::~Player() {}


int Player::getPiece() const
{
	return (piece_);
}

int Player::getMoveCol() const
{
	return (move_col_);
}

int Player::getMoveRow() const
{
	return (move_row_);
}

void Player::setMoveCol(int col)
{
	move_col_ = col;
}

void Player::setMoveRow(int row)
{
	move_row_ = row;
}


void Player::setMove(int col, int row)
{
	setMoveCol(col);
	setMoveRow(row);
}
