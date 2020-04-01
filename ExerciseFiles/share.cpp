#include "my_strc.hpp"
#include "my_func.hpp"

using namespace std;

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