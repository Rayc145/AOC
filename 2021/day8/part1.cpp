#include <iostream>
#include <bits/stdc++.h>


using namespace std;

int main()
{
    int total = 0;
    for (int i = 0; i < 200; i++) {
        string word;
        for (int x = 0; x < 11; x++){
            cin >> word;
        }
        for (int x = 0; x < 4; x++) {
            cin >> word;
            int l = word.length();
            if (l == 2 || l == 4 || l == 3 || l == 7) total++;
        }
    }
    cout << total;
    return 0;
}
