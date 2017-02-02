//Bank Terminal: controls the movement of money between accounts
#include "Term.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <future>

using namespace std;


//calling this program requires a special signature
map<string, string> parseArgs(int argc, char** argv)
{
    map<string, string> argTable;
    for(int i = 0; i< argc -1 ; i++)
    {
        string s = argv[i];
        if(s == "-account")//account to transfer out of (int)
        {
            argTable[argv[i]] = (argv[i+1]);
        }
        else if(s == "-transfer")//amount to transfer (float)
        {
            argTable[argv[i]] = (argv[i+1]);
        }
        else if(s == "-to")//account to transfer into (int)
        {
            argTable[argv[i]] = (argv[i+1]);
        }
        else
        {
            continue;
        }
    }
    return argTable;
}


int main(int argc, char** argv)
{
    //make sure users call correctly
    if(argc != 7)
    {
        cout << "Incorrect call to Terminal application" << endl;
        return -1;
    }
    auto mp = parseArgs(argc, argv);
    //again, ensure a correct call
    if(mp.find("-account") == mp.end())
    {
        cout << "Unable to launch terminal" << endl;
        return -1;
    }
    //initialize the bank terminal
    Terminal term(atoi(mp["-account"].c_str()));
    //run the transfer
    if(mp.find("-to") != mp.end() && mp.find("-transfer") != mp.end())
    {
        Account acctTo(atoi(mp["-to"].c_str()));
        term.transfer(acctTo, atof(mp["-transfer"].c_str()));
    }

    return 0;
}
