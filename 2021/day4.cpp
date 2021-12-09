#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    string input;
    cin >> input;
    vector<int> nums, done;
    for (int i = 0; i < input.length(); i++) {
        int n = 0;
        if (input[i] != ',') {
            int tmp = i;
            for (int x = tmp; x < input.length(); x++) {
                if (input[x] == ',') break;
                else n = n*10 + input[x]-'0';
                i = x;
            }
            nums.push_back(n);
        }
    }
    vector<vector<vector<int>>> boards;
    for (int i = 0; i < 100; i++) {
        vector<vector<int>> board = {};
        for (int x = 0; x < 5; x++) {
            vector<int> row = {};
            for (int c = 0; c < 5; c++) {
                int num = 0;
                cin >> num;
                row.push_back(num);
            }
            board.push_back(row);
        }
        boards.push_back(board);
    }
    vector<vector<vector<int>>> newboard = boards;
    int sum = -1;
    for (int i = 0; i < nums.size(); i++) {
        for (int x = 0; x < boards.size(); x++) {
            for (int c = 0; c < boards[x].size(); c++) {
                if (find(boards[x][c].begin(), boards[x][c].end(), nums[i]) != boards[x][c].end()) {
                    bool hori = true, verti = true;
                    int vert = 0;
                    for (int j = 0; j < boards[x][c].size(); j++) {
                        if (boards[x][c][j] == nums[i]) {
                            boards[x][c][j] = -1;
                            for (int l = 0; l < 5; l++) {
                                if (boards[x][l][j] != -1) verti = false;
                            }
                            if (verti) vert = j;
                        }
                        else if (boards[x][c][j] != -1) hori = false;
                    }
                    //part 2 stuff added to this
                    if (hori || verti) {
                        if (done.size() == 99 && find(done.begin(), done.end(), x) == done.end()) {
                            sum++;
                            for (auto q : boards[x]) {
                                for (auto u : q) {
                                    if (u != -1) sum += u;
                                }
                            }
                            sum *= nums[i];
                            break;
                        }
                        if (find(done.begin(), done.end(), x) == done.end()) {
                            done.push_back(x);
                        }
                    }
                }
            }
            if (sum > -1) break;
        }
        if (sum > -1) break;
    }
    cout << sum;
    return 0;
}
