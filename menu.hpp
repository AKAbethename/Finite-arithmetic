#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class menu{
  public:
    void print_menu();
    void print_value_from_bdd(const std::string& value);
    bool correct_data(std::string str);
    void del_a_before(std::string& stroka);
    void input_nums(std::string&, std::string&);
};


#endif
