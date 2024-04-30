#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(int x, int y, int rows, int cols) {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

bool searchWord(vector<vector<char>>& grid, string word) {
    int rows = grid.size();
    int cols = grid[0].size();
    int len = word.length();

    // Check horizontally forward and backward
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= cols - len; ++j) {
            bool found = true;
            for (int k = 0; k < len; ++k) {
                if (grid[i][j + k] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;

            found = true;
            for (int k = 0; k < len; ++k) {
                if (grid[i][j + k] != word[len - k - 1]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
    }

    // Check vertically upward and downward
    for (int i = 0; i <= rows - len; ++i) {
        for (int j = 0; j < cols; ++j) {
            bool found = true;
            for (int k = 0; k < len; ++k) {
                if (grid[i + k][j] != word[k]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;

            found = true;
            for (int k = 0; k < len; ++k) {
                if (grid[i + k][j] != word[len - k - 1]) {
                    found = false;
                    break;
                }
            }
            if (found) return true;
        }
    }

    return false;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }

    int numWords;
    cin >> numWords;

    for (int i = 0; i < numWords; ++i) {
        string word;
        cin >> word;
        if (searchWord(grid, word)) {
            cout << "Yes ";
        } else {
            cout << "No ";
        }
    }

    cout << endl;

    return 0;
}
