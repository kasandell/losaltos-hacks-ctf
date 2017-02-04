#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string lookup = "./136789bglo";
    ifstream inf("compressed.txt");
    while(!inf.eof() && inf.good())
    {
        unsigned int c;
        
        inf >> c;
        unsigned int c1 = c >> 4;
        unsigned int c2 = c & 0x0F;
        cout << lookup[c1] << lookup[c2];
    }
    cout << endl;
    inf.close();
    return 0;


}
