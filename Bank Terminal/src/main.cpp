#include "Term.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <future>

using namespace std;

map<string, string> parseArgs(int argc, char** argv)
{
    map<string, string> argTable;
    for(int i = 0; i< argc -1 ; i++)
    {
        string s = argv[i];
        if(s == "-account")
        {
            argTable[argv[i]] = (argv[i+1]);//atoi
        }
        else if(s == "-transfer")
        {
            argTable[argv[i]] = (argv[i+1]);//atof
        }
        else if(s == "-to")
        {
            argTable[argv[i]] = (argv[i+1]);//atoi
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
        //user will have write access, needs to write something like the following
        /*
        vector<future<int> > v;
        for(int i = 0; i < 100; i++)
        {
            v.emplace_back(async(launch::async, [&term, &acctTo, &mp](){term.transfer(acctTo, atof(mp["-transfer"].c_str())); return 0; }));
        }
        for(auto &&f: v)
        {
            f.get();

        }
        */
    }

    return 0;
}
