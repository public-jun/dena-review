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
			board_.bePlacedPiece(tmp_->getPiece(), col);
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


void Master::judgeWinner(bool &is_continue)
{
	Board judge_board = board_.generateJudgeBoard(tmp_->getPiece());
	judge_board.printBoard();
	(void)is_continue;
	// is_continue = false;
}

void Master::changeTurn()
{
	if (tmp_ == &p1_)
		tmp_ = &p2_;
	else
		tmp_ = &p1_;
}
