#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

using namespace std;

int main()
{
    int x = 13;
    int count = 1;
    string apb = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/:.";
    vector<char> alphabet(apb.begin(), apb.end());
    string input;
    cin >> input;
    int sz = input.size();
    string s = "";
    for(auto &c: input)
    {

        auto it = find(alphabet.begin(), alphabet.end(), c);
        rotate(alphabet.begin(), it, alphabet.end());
        char z = alphabet[x];
        z = z^(sz%count);
        s+= z;


        x++;
        count++;
    }
    cout << s << endl;
    return 0;
};
