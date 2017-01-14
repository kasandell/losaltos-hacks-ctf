#ifndef _DB_H
#define _DB_H
#include <string>
#include <fstream>

using namespace std;
class Database
{
    public:
        Database();
        static bool updateAmount(int acctNumber, float newAmt);
        static float getAmount(int acctNumber);
    private:
        static string baseDirectory;
};

string Database::baseDirectory = "/tmp/losaltoshacks/";//TODO: set up this dir on the computer

void Database::updateAmount(int acctNumber, float newAmt)
{
    ofstream out((baseDirectory + to_string(acctNumber));
    if(!out.bad())
    {
        out << newAmt;
        out.close();
        return true;
    }
    return false;
}

float Database::getAmount(int acctNumber)
{
    ifstream in((baseDirectory + to_string(acctNumber)));
    if(!in.bad())
    {
        float ret;
        in >> ret;
        in.close();
        return ret;
    }
}
#endif
