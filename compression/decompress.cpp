#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string lookup = "./:abcghklmopstw";
    string read;
    ifstream inf("hi.txt");
    getline(inf, read);
    inf.close();
    for(auto&c: read)
    {
        cout << static_cast<unsigned int>(c) << endl;
        unsigned int c1 = c >> 4;
        unsigned int c2 = c & 0x0F;
        cout << c1 << " " << c2 << endl;
        //cout << lookup[c1] << lookup[c2];
    }
    cout << endl;
    return 0;


}
