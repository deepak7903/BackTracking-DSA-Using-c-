#include <iostream>
#include <vector>
using namespace std;

bool dfs(vector<vector<char>> &board, string &word, int i, int j, int k) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[k]) {
        return false;
    }

    if (k == word.size() - 1) {
        return true;
    }

    char tmp = board[i][j];
    board[i][j] = '*';

    bool found = dfs(board, word, i + 1, j, k + 1) ||
                 dfs(board, word, i - 1, j, k + 1) ||
                 dfs(board, word, i, j + 1, k + 1) ||
                 dfs(board, word, i, j - 1, k + 1);

    board[i][j] = tmp;

    return found;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (dfs(board, word, i, j, 0)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {
        {'q', 'v', 'm', 'h'},
        {'d', 'e', 's', 'i'},
        {'d', 'g', 'f', 'g'},
        {'e', 'c', 'p', 'n'}
    };

    string word = "design";

    int n = board.size();
    int m = board[0].size();

    if (present(board, word, n, m)) {
        cout << "The word is present in the grid." << endl;
    } else {
        cout << "The word is not present in the grid." << endl;
    }
}
