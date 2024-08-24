#include <bits/stdc++.h>
using namespace std;

class King
{
public:
    string symbol;
    pair<int, int> position;
};

class Queen
{
public:
    string symbol;
    pair<int, int> position;
};

class Bishop
{
public:
    string symbol;
    pair<int, int> position;
};

class Knight
{
public:
    string symbol;
    pair<int, int> position;
};

class Rooks
{
public:
    string symbol;
    pair<int, int> position;
};
class Pawns
{
public:
    string symbol;
    pair<int, int> position;
};

class White
{
public:
    King k;
    Queen q;
    Bishop b;
    Knight n;
    Rooks r;
    Pawns p;

    White()
    {
        // namikaran and postion
        k.symbol = "WK";

        q.symbol = "WQ";

        b.symbol = "WB";
        n.symbol = "WN";
        r.symbol = "WR";
        p.symbol = "WP";
    }
};

class Black
{
public:
    King k;
    Queen q;
    Bishop b;
    Knight n;
    Rooks r;
    Pawns p;

    Black()
    {
        // namikaran and postion
        k.symbol = "BK";

        q.symbol = "BQ";

        b.symbol = "BB";
        n.symbol = "BN";
        r.symbol = "BR";
        p.symbol = "BP";
    }
};

class Board
{
private:
    vector<vector<string>> board;
    map<pair<int, int>, string> boardconfig;
    bool whiteTurn = true;

    bool isValidPawnMove(string piece, int r1, int c1, int r2, int c2)
    {
        if (piece[0] == 'W')
        {
            if (c1 == c2)
            {
                if (r2 == r1 + 1 && board[r2][c2] == "--")
                    return true;
                if (r1 == 1 && r2 == r1 + 2 && board[r2][c2] == "--" && board[r1 + 1][c2] == "--")
                    return true;
            }
            else if (abs(c1 - c2) == 1 && r2 == r1 + 1 && board[r2][c2] != "--" && board[r2][c2][0] == 'B')
            {

                return true;
            }
        }
        else if (piece[0] == 'B')
        {
            if (c1 == c2)
            {
                if (r2 == r1 - 1 && board[r2][c2] == "--")
                    return true;
                if (r1 == 6 && r2 == r1 - 2 && board[r2][c2] == "--" && board[r1 - 1][c2] == "--")
                    return true;
            }
            else if (abs(c1 - c2) == 1 && r2 == r1 - 1 && board[r2][c2] != "--" && board[r2][c2][0] == 'W')
            {

                return true;
            }
        }
        return false;
    }

    bool isValidKingMove(string piece, int r1, int c1, int r2, int c2)
    {
        // aaju baju na ho
        if(piece[0] = "W")
            if(board[r2][c2] != "--" and board[r2][c2][0] == "B")
                return false;

        if (piece[0] = "B")
            if (board[r2][c2] != "--" and board[r2][c2][0] == "W")
                return false;

        return abs(r2 - r1) <= 1 && abs(c2 - c1) <= 1;
    }

    bool isValidRookMove(string piece, int r1, int c1, int r2, int c2)
    {
        if (r1 == r2)
        {
            for (int i = min(c1, c2) + 1; i < max(c1, c2); ++i)
            {
                if (board[r1][i] != "--")
                    return false;
            }
            return true;
        }
        else if (c1 == c2)
        {

            for (int i = min(r1, r2) + 1; i < max(r1, r2); ++i)
            {
                if (board[i][c1] != "--")
                    return false;
            }
            return true;
        }
        return false;
    }

    // bool isValidBishopMove(string piece, int r1, int c1, int r2, int c2)
    // {
    // }

    // bool isValidKnightMove(string piece, int r1, int c1, int r2, int c2)
    // {
    // }

    // bool isValidQueenMove(string piece, int r1, int c1, int r2, int c2)
    // {
    // }

    bool isPossible(string piece, int r1, int c1, int r2, int c2)
    {
        if (piece[1] == 'P')
            return isValidPawnMove(piece, r1, c1, r2, c2);
        if (piece[1] == 'K')
            return isValidKingMove(piece, r1, c1, r2, c2);
        if (piece[1] == 'R')
            return isValidRookMove(piece, r1, c1, r2, c2);
        // if (piece[1] == 'B')
        //     return isValidBishopMove(piece, r1, c1, r2, c2);
        // if (piece[1] == 'N')
        //     return isValidKnightMove(piece, r1, c1, r2, c2);
        // if (piece[1] == 'Q')
        //     return isValidQueenMove(piece, r1, c1, r2, c2);
        return false;
    }

public:
    Board()
    {
        board.resize(8, vector<string>(8, "--"));

        board[0][0] = "WR";
        boardconfig[{0, 0}] = "WR";
        board[0][1] = "WN";
        boardconfig[{0, 1}] = "WN";
        board[0][2] = "WB";
        boardconfig[{0, 2}] = "WB";
        board[0][3] = "WQ";
        boardconfig[{0, 3}] = "WQ";
        board[0][4] = "WK";
        boardconfig[{0, 4}] = "WK";
        board[0][5] = "WB";
        boardconfig[{0, 5}] = "WB";
        board[0][6] = "WN";
        boardconfig[{0, 6}] = "WN";
        board[0][7] = "WR";
        boardconfig[{0, 7}] = "WR";

        for (int i = 0; i < 8; i++)
        {
            board[1][i] = "WP";
            boardconfig[{1, i}] = "WP";
        }

        board[7][0] = "BR";
        boardconfig[{7, 0}] = "BR";
        board[7][1] = "BN";
        boardconfig[{7, 1}] = "BN";
        board[7][2] = "BB";
        boardconfig[{7, 2}] = "BB";
        board[7][3] = "BQ";
        boardconfig[{7, 3}] = "BQ";
        board[7][4] = "BK";
        boardconfig[{7, 4}] = "BK";
        board[7][5] = "BB";
        boardconfig[{7, 5}] = "BB";
        board[7][6] = "BN";
        boardconfig[{7, 6}] = "BN";
        board[7][7] = "BR";
        boardconfig[{7, 7}] = "BR";

        for (int i = 0; i < 8; i++)
        {
            board[6][i] = "BP";
            boardconfig[{6, i}] = "BP";
        }
    }

    void state()
    {
        for (int i = 7; i >= 0; i--)
        {
            for (int j = 0; j < 8; j++)
            {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isValid(string src, string des)
    {
        int row1 = 8 - (src[1] - '0');
        int col1 = src[0] - 'a';
        int row2 = 8 - (des[1] - '0');
        int col2 = des[0] - 'a';

        string piece = boardconfig[{row1, col1}];

        if (piece == "--")
        {
            return false;
        }

        return isPossible(piece, row1, col1, row2, col2);
    }

    void play(string src, string des)
    {
        int row1 = 8 - (src[1] - '0');
        int col1 = src[0] - 'a';
        int row2 = 8 - (des[1] - '0');
        int col2 = des[0] - 'a';

        if (!isValid(src, des))
        {
            cout << "Invalid Move\n";
            return;
        }

        board[row2][col2] = board[row1][col1];
        board[row1][col1] = "--";
        boardconfig[{row2, col2}] = boardconfig[{row1, col1}];
        boardconfig.erase({row1, col1});


        state();
    }
};

int main()
{
    cout << "---------- Chess -------------\n";

    Board b;
    b.state();

    string src, des;
    while (cin >> src >> des)
    {
        if (src == "exit")
        {
            break;
        }
        b.play(src, des);
    }

    return 0;
}
