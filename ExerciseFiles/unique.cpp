#include "my_strc.hpp"
#include "my_func.hpp"

using namespace std;


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