#include "my_strc.hpp"
#include <memory>

using namespace std;


void myStrC::msg(const string s)
{
    if(!data.empty())
    {
        cout << __mystrc_class << ": " << s << " (" << data << ")" << endl;
    }
    else
    {
        cout << __mystrc_class << ": " << s << endl;
    }
    cout << flush;
}


myStrC::myStrC()
: data({})
{
    msg("default ctor");
}


myStrC::myStrC(const string s)
: data(s)
{
    msg("cstring ctor");
}


myStrC::myStrC(const myStrC & f)
: data(f.data)
{
    msg("copy ctor");
}


myStrC::myStrC(myStrC && o)
: data(std::move(o.data))
{
    o.data = {};
    msg("move ctor");
}


myStrC::~myStrC()
{
    msg("dtor");
}


myStrC & myStrC::operator = (myStrC o)
{
    swap(o);
    msg("copy and swap =");
    return * this;
}


const string myStrC::value () const
{
    return data;
}


myStrC::operator const string () const
{
    return value();
}


void myStrC::swap(myStrC & o)
{
    std::swap(this->data, o.data);
}