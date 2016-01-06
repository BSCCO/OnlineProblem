//Given an integer n, return all distinct solutions to the n - queens puzzle.
//
//Each solution contains a distinct board configuration of the n - queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.


#include<iostream>
#include<vector>
#include<string>

using std::vector;
using std::string;
typedef vector<int>::size_type size;

bool firstLineAllowed(vector<bool> &forbiddenPositions);
void updateForbiddenPosition(const vector<int> &queensPosition, vector<bool> &forbiddenPosition);
int findFirstAllowedPosition(const vector<bool> &fp);
void init(vector<bool>&);
vector<string> converPositionToBoard(const vector<int> &position);

vector<vector<string>> solveNQueens(int n) {
	if (n < 3) {
		return vector<vector<string>>{};
	}
	vector<vector<string>> result;
	vector<int> queensPosition;	//用于记录王后所在位置，queenPosition[i]表示第i行的王后在第几列
	queensPosition.push_back(0);
	vector<vector<bool>> forbiddenPositions(n+1, vector<bool>(n, false));
	updateForbiddenPosition(queensPosition, forbiddenPositions[1]);
	while (!forbiddenPositions[0].back()) {
		int row = queensPosition.size();
		int position = findFirstAllowedPosition(forbiddenPositions[row]);
		if (position != n) {
			queensPosition.push_back(position);
			updateForbiddenPosition(queensPosition, forbiddenPositions[row + 1]);
		}
		else if(queensPosition.size() != n){
			forbiddenPositions[row - 1][queensPosition.back()] = true;
			init(forbiddenPositions[row]);
			queensPosition.pop_back();
		}
		else if (queensPosition.size() == n) {
			result.push_back(converPositionToBoard(queensPosition));
			forbiddenPositions[row - 1][queensPosition.back()] = true;
			init(forbiddenPositions[row]);
			queensPosition.pop_back();
		}
	}
	return result;
}

bool firstLineAllowed(vector<bool>& forbiddenPositions)
{
	bool r=true;
	for (auto i : forbiddenPositions) {
		r = r&&i;
	}
	return r;
}

void updateForbiddenPosition(const vector<int> &queensPosition, vector<bool> &forbiddenPosition) {	//0可以放，1不可以放
	auto row = queensPosition.size();
	for (size i = 0; i < row; ++i) {
		int Qp = queensPosition[i];
		forbiddenPosition[Qp] = true;

		int QLeftForbidden = Qp - (row - i);
		if (QLeftForbidden >= 0) {
			forbiddenPosition[QLeftForbidden] = true;
		}

		int QRightForbidden = Qp + (row - i);
		if (QRightForbidden < forbiddenPosition.size()) {
			forbiddenPosition[QRightForbidden] = true;
		}
	}
}

int findFirstAllowedPosition(const vector<bool> &fp) {
	int i = 0;
	while (i < fp.size() && fp[i]) {
		++i;
	}
	return i;
}

void init(vector<bool> &f) {
	for (auto i : f) {
		i = false;
	}
}
vector<string> converPositionToBoard(const vector<int> &position) {
	vector<string> board(position.size(), string(position.size(), '-'));
	int i = 0;
	for (auto p : position) {
		board[i++][p] = 'Q';
	}
	return board;
}

void testSolveNQueens() {
	vector<vector<string>> b = solveNQueens(11);
	for (auto r : b) {
		for (auto l : r) {
			std::cout << l << std::endl;
		}
		std::cout << std::endl
			<< std::endl;
	}
	std::cout << "共" << b.size() << "种放法。" << std::endl;
}