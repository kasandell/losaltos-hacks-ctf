//Encrypt a string passed in using Dan's Super Baller Encryption Algorithm
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
    //easy access to individual characters
    vector<char> alphabet(apb.begin(), apb.end());
    //get user input
    string input;
    getline(cin, input);
    int sz = input.size();
    //final result
    string s = "";
    for(auto &c: input)
    {
        //magical encryption stuff right here
        auto it = find(alphabet.begin(), alphabet.end(), c);
        rotate(alphabet.begin(), it, alphabet.end());
        char z = alphabet[x];
        z = z^(sz%count);
        x++;
        count++;

        //append to final string
        s += z;
    }
    //output to user
    cout << s << endl;
    return 0;
};
