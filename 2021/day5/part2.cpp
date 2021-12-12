#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    vector<vector<int>> board(989, vector<int>(989));
    string x1, x2, y1, y2;
    string tmp1, tmp2;
    for (int i = 0; i < 500; i++) {
        getline(cin, x1, ',');
        cin >> y1;
        cin >> tmp2;
        getline(cin, tmp1, ' ');
        getline(cin, x2, ',');
        cin >> y2;
        if (stol(x1) == stol(x2)) {
            for (int y = min(stol(y1), stol(y2)); y <= max(stol(y2), stol(y1)); y++) board[y][stol(x1)]++;
        }
        else if (stol(y1) == stol(y2)) {
            for (int x = min(stol(x1), stol(x2)); x <= max(stol(x2), stol(x1)); x++) board[stol(y1)][x]++;
        }
        else {
            if (stol(x1) > stol(x2)) {
                if (stol(y1) > stol(y2)) {
                    for (int x = 0; x <= stol(x1)-stol(x2); x++) board[stol(y1)-x][stol(x1)-x]++;
                }
                else {
                    for (int x = 0; x <= stol(x1)-stol(x2); x++) board[stol(y1)+x][stol(x1)-x]++;
                }
            }
            else {
                if (stol(y1) > stol(y2)) {
                    for (int x = 0; x <= stol(x2)-stol(x1); x++) board[stol(y1)-x][stol(x1)+x]++;
                }
                else {
                    for (int x = 0; x <= stol(x2)-stol(x1); x++) board[stol(y1)+x][stol(x1)+x]++;
                }
            }
        }
    }
    int total = 0;
    for (auto i : board) {
        for (auto x : i) {
            if (x >= 2) total++;
        }
    }
    cout << total;
    return 0;
}
