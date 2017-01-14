#include "Term.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, variant<string, int, float> > parseArgs(int argc, char** argv)
{
    map<string, variant<string, int, float> > argTable;
    for(int i = 0; i< argc; i++)
    {
        if(argv[i] == "-account")
        {

            argTable[argv[i]] = atoi(argv[i+1]);
        }
        else if(argv[i] == "-transfer")
        {
            argTable[argv[i]] = atof(argv[i+1]);
        }
        else if(argv[i] = "-to")
        {
            argTable[argv[i]] = atoi(argv[i+1]);
        }
    }
    return argTable;
}


int main(int argc, char** argv)
{
    auto mp = parseArgs(argc, argv);
    if(mp.find("-account") == mp.end())
    {
        cout << "Unable to launch terminal";
        return -1;
    }
    Terminal term(mp["-account"]);
    if(mp.find("-to") != mp.end() && mp.find("-transfer") != mp.end())
    {
        Account acctTo(mp["-to"]);
        term.transfer(acctTo, mp["-transfer"]);
    }
    return 0;
}
