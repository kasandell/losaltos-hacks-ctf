#ifndef _DB_H
#define _DB_H
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class Database
{
    public:
        Database();
        static bool updateAmount(int acctNumber, float newAmt);
        static float getAmount(int acctNumber);
        static void WIN();
    private:
        static string baseDirectory;
};

string Database::baseDirectory = "/tmp/losaltoshacksdb/";//TODO: set up this dir on the computer


void Database::WIN()
{
    cout << "Congrats, you've finished!" << endl << "Please submit the following hash, and your names to the first page from this CTF: " << endl << "838eae573a858f9fabfa88e1c9a68bd4fd90ea87263b8507486255fc04c69b18" << endl;
}

bool Database::updateAmount(int acctNumber, float newAmt)
{
    ofstream out((baseDirectory + to_string(acctNumber)));
    if(!out.bad())
    {
        out << newAmt;
        out.close();
        return true;
    }
    cout << "Unable to write to directory" << endl;
    return false;
}

float Database::getAmount(int acctNumber)
{
    ifstream in((baseDirectory + to_string(acctNumber)));
    if(!in.bad())
    {
        float ret;
        in >> ret;
        cout << "account has " << ret << " dollars in it" << endl;
        in.close();
        return ret;
    }
    cout << "Unable to read from directory" << endl;
}
#endif
