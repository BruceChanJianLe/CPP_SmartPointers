#include <iostream>
#include <string>
#include <memory>
#include "my_strc.hpp"

using namespace std;


void message(const string s)
{
    cout << endl << s << endl << flush;
}


void disp(std::unique_ptr<myStrC> & o)
{
    if(o)
    {
        cout << o->value() << endl;
    }
    else
    {
        cout << "null" << endl;
    }
    cout << flush;
}


int main(int argc, char ** argv)
{
    message("create unique pointer one");
    std::unique_ptr<myStrC> a(new myStrC("one"));
    disp(a);

    message("make_unique two");
    auto b = std::make_unique<myStrC>("two");
    disp(a);
    disp(b);

    message("reset a to three");
    a.reset(new myStrC("three"));
    disp(a);
    disp(b);

    message("move b to c");
    auto c = std::move(b);
    disp(a);
    disp(b);
    disp(c);

    message("reset a");
    a.reset();
    disp(a);
    disp(b);
    disp(c);

    message("end of scope");
    return 0;
}