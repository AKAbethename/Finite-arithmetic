#include <iostream>

#include "Rules.hpp"
#include "Finit.hpp"
#include "menu.hpp"
#include "checks.hpp"

#include <vector>

int main(){
    std::cout << "Hello, world!\n";

    Rules r;

    Rules r_new(8, 8);

//    r_new.print_vector_plus();

    char inp_1;
    char inp_2;

#if 0

    menu m;
    m.print_menu();

    std::string input_num;
    input_num.resize(10);


    Finit obj1("fffffffe");
    std::cout << "obj1 = " << obj1 << '\n';

    Finit obj2("bh");
    std::cout << "obj2 = " << obj2 << '\n';

    int answer = static_cast<int>(obj2 < obj1);

    std::cout << "check< " << obj2 << " < " << obj1 << " is " << answer << "\n";


    obj1.eval_dop();
    obj2.eval_dop();

    Finit obj1_dop(obj1.get_dop());
    Finit obj2_dop(obj2.get_dop());

//    std::cout << multy(obj1, obj2) << " is multy\n";

    std::cout << obj1_dop << " is obj1_dop\n";
    std::cout << obj2_dop << " is obj2_dop\n";

    std::cout << summ(obj1, obj2) << " is obj1 + obj2\n";

    std::cout << obj1 << " + " << obj2 << " = " << summ(obj1, obj2) << "\n";

    std::cout << obj1.translate() << " + " << obj2.translate() << " = " << summ(obj1, obj2).translate() << "\n";

    std::cout << obj1 << " * " << obj2 << " = " << multy(obj1, obj2) << "\n";

    std::cout << obj1.translate() << " * " << obj2.translate() << " = " << multy(obj2, obj1).translate() << "\n";

    std::cout << obj1 << " / " << obj2 << " = " << int_div(obj1, obj2) << "\n";

    Finit div(int_div(obj1, obj2));

    Finit mult1(div.get_num1());
    Finit mult2(obj2);
    Finit rest(*div.rest_value);
    mult2.set_sign(true);
    Finit M(multy(mult1, mult2));
    std::cout << mult1 << " * " << mult2 << " + " << rest << " = " << summ(M, rest) << "\n";
    Finit e("a");

    std::cout << "NOD is " << "(" << obj1 << ", " << obj2 << ") = " << gcd(obj1, obj2) << "\n";

#endif

#if 0

Finit obj1("ffffffff");
    std::cout << "obj1 = " << obj1 << '\n';

    Finit obj2("ffffffff");
    std::cout << "obj2 = " << obj2 << '\n';

    int answer = static_cast<int>(obj2 < obj1);

    std::cout << "check< " << obj2 << " < " << obj1 << " is " << answer << "\n";


    obj1.eval_dop();
    obj2.eval_dop();

    Finit obj1_dop(obj1.get_dop());
    Finit obj2_dop(obj2.get_dop());

    std::cout << "dop of " << obj1 << " is " << obj1_dop << "\n";

//    std::cout << obj1 << " + " << obj2 << " = " << obj1 + obj2 << "\n";

//    std::cout << obj2 << " + " << obj2_dop << " = " << obj1+obj1_dop << " dopolnenie eli\n";

    std::cout << obj1 << " - " << obj2 << " = " << subb(obj1, obj2) << "\n";

#endif

    menu m;
    m.print_menu();

    
}