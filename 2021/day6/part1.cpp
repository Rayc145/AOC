#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    vector<int> fish;
    string input;
    cin >> input;
    int counter = 0;
    while (counter < input.length()) {
        if (input[counter] != ',') {
            fish.push_back(input[counter]-'0');
        }
        counter++;
    }
    for (int i = 0; i < 80; i++) {
        int tmp = fish.size();
        for (int x = 0; x < tmp; x++) {
            fish[x]--;
            if (fish[x] < 0) {
                fish[x] = 6;
                fish.push_back(8);
            }
        }
    }
    cout << fish.size();
    return 0;
}
