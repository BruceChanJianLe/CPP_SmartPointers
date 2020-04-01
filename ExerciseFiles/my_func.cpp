#include "my_func.hpp"

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