#include <set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    auto v = std::vector<char>(str.begin(), str.end());
    set<char> s;
    for(const auto&c: v)
    {
        s.insert(c);
    }
    for(auto&c: s)
    {
        cout << c;
    }
    cout << endl;
    return 0;
}
