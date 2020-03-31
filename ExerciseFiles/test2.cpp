#include <iostream>
#include <string>
#include <memory>
#include "my_strc.hpp"

using namespace std;


void message(const string s)
{
    cout << endl << s << endl << flush;
}


void disp(const std::shared_ptr<myStrC> & o)
{
    if(o)
    {
        cout << o->value() << " (" << o.use_count() << ")" << endl;
    }
    else
    {
        cout << "null" << endl;
    }
    cout << flush;
}


int main(int argc, char ** argv)
{
    message("create share pointer with new");
    std::shared_ptr<myStrC> a1(new myStrC("none"));
    auto a = std::make_shared<myStrC>("new");

    message("reset a to one");
    a.reset(new myStrC("one"));
    disp(a);

    message("b = a");
    auto b = a;
    disp(a);
    disp(b);

    cout << "a == b " << (a == b ? "true" : "false") << endl;
    // printf("%s", *a == *b ? "true" : "false");
    // cout << "* a == * b " << (* a == * b ? "true" : "false") << endl;
    cout << &a ;

    message("reset a to two");
    a.reset(new myStrC("two"));
    disp(a);
    disp(b);



    message("end of scope");
    return 0;
}