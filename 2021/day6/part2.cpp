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
    vector<long long> fishes;
    for (int i = 0; i < 9; i++) {
        fishes.push_back(count(fish.begin(), fish.end(), i));
    }
    int fishesRepro = 0;
    for (int i = 0; i < 256; i++) {
        rotate(fishes.begin(), fishes.begin()+1, fishes.end());
        fishes[6] += fishes[8];
        /*fishesRepro = fishes[0];
        fishes[0] = 0;
        for (int x = 0; x < 8; x++) {
            fishes[x] = fishes[x+1];
        }
        fishes[8] = fishesRepro;
        fishes[6] += fishesRepro;*/
    }
    long long total = 0;
    for (auto i : fishes) {
        total += i;
    }
    cout << total;
    return 0;
}
