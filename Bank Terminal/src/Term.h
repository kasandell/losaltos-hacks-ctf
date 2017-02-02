#ifndef _TERM_H
#define _TERM_H
#include <ctime>
#include <iostream>
#include <chrono>
#include <thread>
#include <future>
#include "Db.h"//hidden. our database tech is proprietary and revolutionary

using namespace std;
class Account
{
    public:
        Account(int acctNumber): acctNumber(acctNumber){amt = Database::getAmount(acctNumber);}
        //increase the amount of money the account holds, update it in the database
        void addAmt(float amount) {amt += amount; Database::updateAmount(acctNumber, amt);}
        //decrease the amount of money the account holds, update it in the database
        void reduceAmt(float amount){amt -= amount; Database::updateAmount(acctNumber, amt);}
        //get the amount of money in the user's account
        float getAmount(){return amt;}
        ~Account()
        {
            //write the final amount once the user closes the program
            Database::updateAmount(acctNumber, amt);
        }
    private:
        int acctNumber;
        float amt;
};



//V 1.0
class Terminal
{
    public:
        Terminal();
        //initialize the terminal with an account we are transferring out of
        Terminal(int acctNumber);
        //transfer an amount from one account to another
        bool transfer(Account& acct, float amt);


    private:
        //unique account that we are logged into
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
        cout << "Insufficient funds" << endl;
        return false;
    }
    else
    {
        auto x = std::async(launch::async, [&acct, &amt](){acct.addAmt(amt);return 0;});//add amount to the file we are transferring to 
        this_thread::sleep_for(chrono::seconds(5));//TODO: change this because although it helps reduce server load, people can exploit it if they are smart
        x.get();
        userLoggedIn->reduceAmt(amt);
    }
    return true;
}




#endif
