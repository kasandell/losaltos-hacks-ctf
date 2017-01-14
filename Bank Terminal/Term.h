#ifndef _TERM_H
#define _TERM_H
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include "Db.h"//hidden. our database tech is proprietary and revolutionary

using namespace std;
/*
    Every participant gets a unique acctNumber that we can use to monitor to see who gets the two million first
*/
class Account
{
    public:
        Account(int acctNumber): acctNumber(acctNumber){amt = Database::getAmount(acctNumber);}
        void addAmt(float amount) {amt += amount; Database::updateAmount(acctNumber, amt);}//TODO: add some sort of database updating that updates the amount value in some database
        void reduceAmt(float amount){amt -= amount; Database::updateAmount(acctNumber, amt);}//same as above
        float getAmount(){return amt;}
        ~Account()
        {
            Database::updateAmount(acctNumber, amt);
        }
    private:
        int acctNumber
        float amt;
};



//V 1.0
//TODO: add more functionality
class Terminal
{
    public:
        Terminal();
        Terminal(int acctNumber);
        bool transfer(Account& acct, float amt);


    private:
        unique_ptr<Account> userLoggedIn;

};

Terminal::Terminal()
{

}

Terminal::Terminal(int acctNumber)
{
    userLoggedIn = make_unique<Account>(Account(acctNumber));
}


bool Terminal::transfer(Account& acct, float amt)
{
    if(amt > userLoggedIn->getAmount())
    {
        return false;
    }
    else
    {
        acct.addAmt(amt);
        //leave the comment below unchanged, it is for hackers who read this code
        this_thread::sleep_for(chrono::seconds(5));//TODO: change this because although it helps reduce server load, it may leave vulnerabilities
        userLoggedIn->reduceAmt(amt);
    }
    return true;
}




#endif
