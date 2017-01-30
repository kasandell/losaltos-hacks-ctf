#include "Term.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, string> parseArgs(int argc, char** argv)
{
    cout << "in" << endl;
    map<string, string> argTable;
    for(int i = 0; i< argc -1 ; i++)
    {
        string s = argv[i];
        if(s == "-account")
        {
            cout << "account: " << argv[i+1] << endl;
            argTable[argv[i]] = (argv[i+1]);//atoi
        }
        else if(s == "-transfer")
        {
            cout << "amount: " << argv[i+1] << endl;
            argTable[argv[i]] = (argv[i+1]);//atof
        }
        else if(s == "-to")
        {
            cout << "to: " << argv[i+1] << endl;
            argTable[argv[i]] = (argv[i+1]);//atoi
        }
        else
        {
            continue;
        }
    }
    cout << "Made it" << endl;
    return argTable;
}


int main(int argc, char** argv)
{
    if(argc != 7)
        return -1;
    auto mp = parseArgs(argc, argv);
    if(mp.find("-account") == mp.end())
    {
        cout << "Unable to launch terminal" << endl;
        return -1;
    }
    Terminal term(atoi(mp["-account"].c_str()));
    if(mp.find("-to") != mp.end() && mp.find("-transfer") != mp.end())
    {
        Account acctTo(atoi(mp["-to"].c_str()));
        term.transfer(acctTo, atof(mp["-transfer"].c_str()));
    }
    return 0;
}
