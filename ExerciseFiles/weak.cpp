#include "my_strc.hpp"
#include "my_func.hpp"

using namespace std;


int main(int argc, char ** argv)
{
    message("create shared pointer");
    auto a = std::make_shared<myStrC>("thing");

    message("make several copies");
    auto c1 = a;
    auto c2 = a;
    auto c3 = a;
    auto c4 = a;
    auto c5 = a;

    message("reference count is now 6");
    disp(a);

    message("create weak pointer");
    auto w1 = std::weak_ptr<myStrC>(a);
    disp(w1);

    message("destory copies");
    c1.reset();
    c2.reset();
    c3.reset();
    c4.reset();
    c5.reset();

    message("reference count should be 1");
    disp(a);

    message("check weak pointer");
    disp(w1);

    message("destroy a");
    a.reset();

    message("check weak pointer");
    disp(w1);

    message("end of scope");
    return 0;
}