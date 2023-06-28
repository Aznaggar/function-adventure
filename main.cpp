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
    poly.debug_printArgs();
    auto poly2 = -poly;
    poly.debug_printArgs();
    // std::cout << poly.call(2.02f) << std::endl;
    // std::cout << poly.strigify() << std::endl;
}

int main()
{
    testing();
    // std::list<std::string> l1{"A", "B", "C"}, l2{"E", "F", "G"};
    // l1.merge(l2);
    // const auto print = [](const std::list<std::string>& l){
    //     std::for_each(l.cbegin(), l.cend(),[](const std::string& s){ std::cout << s << " ";});
    //     std::cout << std::endl;
    // };
    // print(l1);
    // print(l2);
}
