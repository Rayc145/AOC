#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    vector<int> crabs;
    string input;
    int counter = 0;
    for (int i = 0; i < 999; i++) {
        string tmp;
        getline(cin, tmp, ',');
        crabs.push_back(stol(tmp));
    }
    string tmp;
    cin >> tmp;
    crabs.push_back(stol(tmp));
    sort(crabs.begin(), crabs.end());
    vector<int> fuels(crabs.back()+1);
    for (int i = 0; i < fuels.size(); i++) {
        for (int x = 0; x < crabs.size(); x++) {
            int mi = min(crabs[x], i), mx = max(crabs[x], i);
            for (int c = mi; c <= mx; c++) {
                fuels[i] += c - mi;
            }
        }
    }
    sort(fuels.begin(), fuels.end());
    cout << fuels[0];
    return 0;
}
