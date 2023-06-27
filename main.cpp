#include <iostream>
#include <iomanip>
#include <sstream>

#include <vector>
#include <map>
#include <string>

#include "obj"
#include "pre"

void testing()
{
    obj::polynomial::Polynomial<> poly({
        {7u, 1},
        {4u, -2},
        {9u, 3}
    });
    poly.printArgs();
    auto poly2 = -poly;
    poly.printArgs();
    // std::cout << poly.call(2.02f) << std::endl;
    // std::cout << poly.strigify() << std::endl;
}

int main()
{
    testing();
}
