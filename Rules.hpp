#ifndef RULES_HPP
#define RULES_HPP

#include <vector>
#include <string>

class Rules{
  private: 
    int bit_depth; // разрядность, количество разрядов (в нашем случае 8)
    int cnt_syms;  // длина арифметики (в нашем случае так же 8)
    char** table_plus = nullptr;

    char** table_plus_c = nullptr;

    char** table_times = nullptr;

    char** table_times_c = nullptr;

    std::vector<char> Hasse;

//    char** plus;
    
    std::vector<std::string> plus;

    std::vector<std::string> plus_c;

//    char** times;

    std::vector<std::string> times;

    std::vector<std::string> times_c;


  public:

    Rules();

    Rules(int, int);


    void print_plus();
    void print_plus_c();

    void print_times();

    void print_times_c();

    void print_vector_plus();

    char eval_plus(char one, char two) const;

    char eval_plus_c(char one, char two) const;

    char eval_times(char one, char two) const;

    char eval_times_c(char one, char two) const;

    std::vector<char> get_hasse();

};


#endif