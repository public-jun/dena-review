#include <Master.hpp>

Master::Master(Board &board, Player &p1, Player &p2) :
	board_(board), tmp_(&p1), p1_(p1), p2_(p2) {}

Master::~Master() {}

Board &Master::getBoard()
{
	return (board_);
}

void Master::inputNum()
{
	bool is_continue = true;
	while (is_continue)
	{
		std::cout << "Player"
				  << (tmp_ == &p1_ ? "1" : "2")
				  << " は行番号(1 ~ 7)を入力してください" << std::endl;
		std::string input;
		if (!std::getline(std::cin, input))
			std::exit(1);
		try
		{
			int col = std::stoi(input);
			int row = board_.bePlacedPiece(tmp_->getPiece(), col);
			tmp_->setMove(col - 1, row - 1);
			is_continue = false;
		}
		catch(const std::invalid_argument& e)
		{
			std::cerr << RED << "入力は無効です" << END << '\n' << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << END << '\n' << std::endl;
		}
	}
}

void Master::printBoard()
{
	board_.printBoard();
}

bool Master::is_victory_col(Board &board)
{
	// board.printBoard();
	int fixed_row = tmp_->getMoveRow();
	int total_points = tmp_->getPiece();
	int piece = tmp_->getPiece();
	for (int i = tmp_->getMoveCol() - 1; i >= 0 ; --i)
	{
		if (board.getPiece(fixed_row, i) == piece)
			total_points += piece;
		else
			break;
	}
	for (int i = tmp_->getMoveCol() + 1; i < kWidth ; ++i)
	{
		if (board.getPiece(fixed_row, i) == piece)
			total_points += piece;
		else
			break;
	}
	if (piece == Player::kP1 && total_points >= 4)
		return (true);
	else if (piece == Player::kP2 && total_points <= -4)
		return (true);
	return (false);
}

bool Master::is_victory_row(Board &board)
{
	// board.printBoard();
	int fixed_col = tmp_->getMoveCol();
	int total_points = tmp_->getPiece();
	int piece = tmp_->getPiece();

	for (int row = tmp_->getMoveRow() + 1; row < kHeight ; ++row)
	{
		if (board.getPiece(row, fixed_col) == piece)
			total_points += piece;
		else
			break;
	}
	if (piece == Player::kP1 && total_points >= 4)
		return (true);
	else if (piece == Player::kP2 && total_points <= -4)
		return (true);
	return (false);
}

void Master::judgeWinner(bool &is_continue)
{

	Board judge_board = board_.generateJudgeBoard(tmp_->getPiece());
	if (is_victory_col(judge_board)
		|| is_victory_row(judge_board))
	{
		// print_winner();
		is_continue = false;
	}
	// 	|| is_victory_row(tmp, judge_board)
	// 	|| is_victory_slash(tmp, judge_board)
	// 	|| is_victory_back_slash(tmp, judge_board))
	(void) is_continue;
}

void Master::changeTurn()
{
	if (tmp_ == &p1_)
		tmp_ = &p2_;
	else
		tmp_ = &p1_;
}
