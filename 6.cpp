#include <iostream>
#include <sstream>
//#include <gtest/gtest.h>

using namespace std;

bool czyLitera(char pznak)
{
    return pznak >= 65 && pznak <= 90 || pznak >= 97 && pznak <= 122;
}

bool czyLiczba(char pznak)
{
    return pznak >= 48 && pznak <= 57;
}

int ile_slow(string zdanie)
{
    char pznak = zdanie[0];

    if (czyLitera(pznak))
    {
        int ile = 0;

        for (char c : zdanie) 
        {
            if (c != ' ' && !czyLitera(c) && !czyLiczba(c))
            {
                throw domain_error("Znak nie jest poprawny");
            }
        }

        istringstream iss(zdanie);

        string slowo;

        while (iss >> slowo) 
        {
            ile++;
        }


        return ile;
    }
    else
    {
        throw invalid_argument("Pierwszy znak musi byc litera");
    }
}

/*
TEST(TestZnak1, Zdanie1)
{
    string zdanie1 = " abcd";
    //expect throws
}
*/

int main()
{
    try
    {
        int ile = ile_slow("abcd ghy kkkk asdasdd sadasd");

        cout << ile << endl;
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
}

