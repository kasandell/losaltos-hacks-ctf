#include <bitset>
#include <numeric>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;





int main()
{
    string str;
   
    getline(cin, str);
    string lookup = "./:abcghklmopstw";
    vector<uint8_t> addrs;
    for(const auto& c: str)
    {
        addrs.push_back(lookup.find(c));
    }
    ofstream out("hi.txt");
    for(int i = 0; i < addrs.size(); i+=2)
    {
        uint8_t c = (addrs[i] << 4) | (addrs[i+1] & 0x0F);
        cout << static_cast<unsigned int>(c)<< " ";
        out << static_cast<unsigned int>(c) << " ";
    }
    cout << endl;
    out.close();
    return 0;
}
