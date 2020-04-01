#ifndef __MYFUNC_H_
#define __MYFUNC_H_

#include <iostream>
#include <string>
#include <memory>
#include "my_strc.hpp"

using namespace std;

void message(const string s);
void disp(std::unique_ptr<myStrC> & o);
void disp(const std::shared_ptr<myStrC> & o);
void disp(const std::weak_ptr<myStrC> & o);

#endif