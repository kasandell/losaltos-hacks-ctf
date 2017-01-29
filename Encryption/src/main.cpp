#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    //./DSBE -encrypt msg or ./DSBE -decrypt msg
    if(argc != 3)
    {
        cout << "Usage is ./DSBE -encrypt/-decrypt msg" << endl;
        return -1;
    }
    cout << argv[0] << " " << argv[1] << " " << argv[2] << endl;
    if(argv[1] == "-encrypt")
    {

    }
    else if(argv[1] == "-decrypt")
    {

    }
    else
    {
        cout << "Argument " << argv[1] << " not recognized." << endl;
        return 0;
    }
    return 0;

}
