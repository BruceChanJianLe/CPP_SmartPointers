// My string wrapper class

#ifndef __MYSTRC_H_
#define __MYSTRC_H_

#include <iostream>
#include <string>

using namespace std;


static const string __mystrc_class = "my_strc";
static const string __mystrc_version = "1.0";

class myStrC
{
private:
    string data {};
    void msg(const string);
public:
    myStrC();
    myStrC(const string s);
    myStrC(const myStrC &);
    myStrC(myStrC &&);
    ~myStrC();
    myStrC & operator = (myStrC);
    const string value() const;
    operator const string () const;
    void swap(myStrC &);
};

#endif