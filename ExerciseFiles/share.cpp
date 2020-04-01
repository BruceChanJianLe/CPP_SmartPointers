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
    cout << "* a == * b " << (* a == * b ? "true" : "false") << endl;

    message("reset a to two");
    a.reset(new myStrC("two"));
    disp(a);
    disp(b);

    cout << "a == b " << (a == b ? "true" : "false") << endl;
    cout << "* a == * b " << (* a == * b ? "true" : "false") << endl;

    message("b.swap(a)");
    b.swap(a);
    disp(a);
    disp(b);

    message("std::swap using obj");
    std::swap(a, b);
    disp(a);
    disp(b);

    message("std::swap using pointer");
    std::swap(*a, *b);
    disp(a);
    disp(b);

    message("end of scope");
    return 0;
}