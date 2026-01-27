#ifndef FINIT_HPP
#define FINIT_HPP

#include <vector>
#include <string>
#include "Rules.hpp"

class Finit{
  private:

    int bit_depth = 8;

    std::string num1;

    std::vector<char> aybuben;

    Rules r;

    std::string dop_num1;  // дополнение до bitdepth

    bool sign = true;

    bool lilbit = false;  // переполнение

    bool full_segment = false;  // результат деления 0 на 0 -- отрезок

    bool empty_set = false;  // результат деления на 0 -- пустое множество

    bool rest = false;  // если есть остаток при делении


  std::string MIN{"-ffffffff"};
    std::string MAX{"ffffffff"};

  public:

  Rules get_r();

  Finit* rest_value = nullptr;

    int translate();


    Finit();

    Finit(const Finit&);

    ~Finit();

    Finit(std::string num1);

    friend Finit operator+(const Finit& num1, const Finit& num2);

    friend Finit operator-(const Finit& num1, Finit& num2);

    friend Finit operator-(Finit num1);

    Finit& operator=(const Finit&);

    char operator[](int i) const;

    friend bool operator<(const Finit& num1, const Finit& num2);

    friend bool operator<=(const Finit&, const Finit&);

    friend bool operator==(const Finit& num1, const Finit& num2);

    friend std::ostream& operator<<(std::ostream& os, const Finit& obj);

    void eval_dop();

    std::string get_dop() const;

    void make_normal_for_us(std::string&);

    std::string make_normal_for_user(const std::string&) const;

    std::string get_num1();

    void set_lilbit(bool value);

    bool get_lilbit() const;

    bool get_sign() const;

    void set_sign(bool flag);

    int get_bit_depth() const;

    int cnt_of_a() const;

    void set_full_segment(bool flag);
    void set_empty_set(bool flag);
    void set_rest(bool flag);
    bool get_rest() const;
    bool get_empty_set()const;
    bool get_full_segment()const;

    

//    bool get_lilbit();



};

Finit summ(Finit& obj1, Finit& obj2);

Finit subb(Finit& obj1, Finit& obj2);

Finit one_mult_one(Finit& obj1, Finit& obj2);  // каждый из операндов -- одна буква!

Finit mult_with_a(Finit& obj1, Finit& obj2);  // умножение чисел виде ?a..a * ?a..a  example: daaa * faa

Finit multy(Finit& obj1, Finit& obj2);

Finit int_div(Finit& obj1, Finit& obj2);

Finit gcd(Finit obj1, Finit obj2);


#endif