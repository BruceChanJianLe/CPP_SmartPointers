#include <iostream>
#include <string>
#include <memory>
#include "my_strc.hpp"

using namespace std;


void message(const string s)
{
    cout << endl << s << endl << flush;
}


// To display unique pointer
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


// To display shared pointer
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


// To display weak pointer alongside with shared pointer
void disp(const std::weak_ptr<myStrC> & o)
{
    // Must obtain a lock to use a weak pointer
    auto count = o.use_count();
    auto sp = o.lock();
    if(sp)
    {
        cout << sp->value() << " (w:" << count << " s:" << sp.use_count() << ")" << endl;
    }
    else
    {
        cout << "[null]" << endl;
    }
    cout << flush;
}


// Function to demonstarte that you cannot pass a unique pointer
// to a function without referencing it
void f(unique_ptr<myStrC> & p)
{
    message("f()");
    disp(p);
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

    // Unique pointer can only be pass by reference in function
    f(c);

    message("end of scope");
    return 0;
}