#include "my_strc.hpp"
#include "my_func.hpp"

using namespace std;


// There are several ways to create a custom deleter
// 1. function
// 2. functor
// 3. lambda

void deleter(const myStrC * o)
{
    cout << "deleter: ";
    if(o)
    {
        cout << o->value() << endl;
    }
    else
    {
        cout << "[null]" << endl;
    }
    cout << flush;
    delete o;
}


class D
{
public:
    void operator () (const myStrC * o)
    {
        cout << "deleter: ";
        if(o)
        {
            cout << o->value() << endl;
        }
        else
        {
            cout << "[null]" << endl;
        }
        cout << flush;
        delete o;
    }
};


int main(int argc, char ** argv)
{
    message("first method using a function");
    message("create share pointer");
    std::shared_ptr<myStrC> a(new myStrC("thing"), &deleter);

    message("display a");
    disp(a);

    message("reset a");
    a.reset();
    disp(a);

    message("second method using class functor");
    message("create second share pointer");
    std::shared_ptr<myStrC> b(new myStrC("thing2"), D());

    message("display b");
    disp(b);

    message("reset b");
    b.reset();
    disp(b);

    message("third method using lambda");
    message("create third share pointer");
    std::shared_ptr<myStrC> c(new myStrC("thing3"), [=](const myStrC * o)
    {
        cout << "deleter: ";
        if(o)
        {
            cout << o->value() << endl;
        }
        else
        {
            cout << "[null]" << endl;
        }
        cout << flush;
        delete o;
    }
    );

    message("display c");
    disp(c);

    message("reset c");
    c.reset();
    disp(c);

    message("end of scope");
    return 0;
}