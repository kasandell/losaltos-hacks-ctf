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
        out << static_cast<char>(c);
    }
    cout << endl;
    /*
    vector< bitset<4> > bits;
    for(const auto& i: addrs)
    {
        bitset<4> bts(i);
        bits.push_back(bts);
    }
    vector<string> rep;
    for(const auto& b: bits)
    {
        rep.push_back(b.to_string());
    }
    string str1 = accumulate(rep.begin(), rep.end(), string(""));
    if(str1.length() % 8) 
    {
        str1.append("0000");
    }
    vector<char> out;
    for(int i = 0; i < str1.length(); i += 8)
    {
        string s = str1.substr(i, 8);
        bitset<8> b(s);
        auto x = b.to_ulong();
        char c = static_cast<unsigned char>(x);
        cout << static_cast<unsigned int>(c) << endl;
        out.push_back(c);
    }
    string fin(out.begin(), out.end());
    ofstream outf("hi.txt");
    outf << fin;
    outf.close();
    */

    //bitset<str.length()> bts(str);
    return 0;
}
