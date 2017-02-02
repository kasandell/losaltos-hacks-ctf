#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    int x = 13;
    int count = 1;
    string apb = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/:. ";
    vector<char> alphabet(apb.begin(), apb.end());
    string str;
    cin >> str;
    int sz = str.size();
    string s = "";
    for(auto& c: str)
    {
        char a = c^(sz%count);
        auto it = find(alphabet.begin(), alphabet.end(), a) + 1;
        rotate(alphabet.begin(), it, alphabet.end());
        rotate(alphabet.begin(), alphabet.end()-x-1, alphabet.end());
        c = alphabet.front();
        s+= c;
        x++;
        count++;
    }
    cout << s << endl;
    return 0;
}
