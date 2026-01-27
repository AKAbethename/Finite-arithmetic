#include "menu.hpp"
//#include "acts.hpp"
#include "Finit.hpp"

#include <vector>
#include <limits>
#include <algorithm>



void menu::print_menu(){
    std::cout << "\n";
    std::cout << "|--------------------------------------------------------------------------|\n";
    std::cout << "|       Курсовая работа. Калькулятор <<большой>> конечной арифметики       |\n";
    std::cout << "|--------------------------------------------------------------------------|\n";

//    char ans = 'b';

    std::string ans = "b";

while(ans != "9"){


    std::cout << "             |----------------------------------|\n";
    std::cout << "             |              Menu                |\n";
    std::cout << "             |----------------------------------|\n\n";

    std::vector<int> values = {1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1};

    std::cout << "Диаграмма Хассе: a -- b -- d -- c -- h -- g -- e -- f\n\n";

//    std::cout << "Введите первое число из диапазона [-ffffffff; ffffffff]: \n";

    std::string str1, str2;
    str1.resize(10); str2.resize(10);

#if 0
    
    bool flag = false;
    
    while(!flag){
        std::cin >> str1;
        del_a_before(str1);
        flag = correct_data(str1);
        if(!flag) std::cout << "Введите корректные данные!\n";
        else flag = true;
    }

    std::cout << "Введите второе число из диапазона [-ffffffff; ffffffff]: \n";

    flag = false;
    while(!flag){
        std::cin >> str2;
        del_a_before(str2);
        flag = correct_data(str2);
        if(!flag) std::cout << "Введите корректные данные!\n";
        else break;
    }

#endif

#if 0
    input_nums(str1, str2);
#endif
    Finit obj1(str1);
    Finit obj2(str2);
    Finit res;
    Finit tmpp = -obj2;

//    std::cout << "Итак вы ввели два числа:\n\nПервое число: " << obj1 << "\nВторое число: " << obj2 << "\n\n";
    std::cout << "Выберите действие:\n";



    std::cout << "|=================================================================================|\n";

    std::cout << "|                     Выберите действие из списка ниже:                           |\n";
    std::cout << "|                                                                                 |\n";
    std::cout << "| [1] > Сложение                                                                  |\n";
    std::cout << "| [2] > Вычитание                                                                 |\n";
    std::cout << "| [3] > Умножение                                                                 |\n";
    std::cout << "| [4] > Деление                                                                   |\n";
    std::cout << "| [5] > Вывод таблицы сложения                                                    |\n";
    std::cout << "| [6] > Вывод таблицы сложения с переносом                                        |\n";
    std::cout << "| [7] > Вывод таблицы умножения                                                   |\n";
    std::cout << "| [8] > Вывод таблицы умножения с переносом                                       |\n";
    std::cout << "| [9] > Выход                                                                     |\n";

    std::cout << "|=================================================================================|\n";


    std::cout << "\n";
    std::cin >> ans;

    std::string frame;

    if(ans[0] >= 49 && ans[0] <= 55 && ans.length() == 1) std::cout << "\nВаше действие -- [" << ans << "]\n\n";

if(ans.length() == 1){

    switch (ans[0])
    {
    case '1':
        input_nums(str1, str2);
        obj1 = Finit(str1);
        obj2 = Finit(str2);
        std::cout << "Итак вы ввели два числа:\n\nПервое число: " << obj1 << "\nВторое число: " << obj2 << "\n\n";
        res = summ(obj1, obj2);
        frame = std::string((obj1.get_num1().length() + obj2.get_num1().length() + res.get_num1().length() + 21), '~');
        std::cout << "                                                                     |" <<frame << "|\n";
        std::cout << "                                                                     | " << obj1 << " + " << obj2 << " = " << res << "\n";
        std::cout << "                                                                     |" << frame << "|\n";
        break;

    case '2':
    input_nums(str1, str2);
        obj1 = Finit(str1);
        obj2 = Finit(str2);
        std::cout << "Итак вы ввели два числа:\n\nПервое число: " << obj1 << "\nВторое число: " << obj2 << "\n\n";
        res = subb(obj1, obj2);
        frame = std::string((obj1.get_num1().length() + obj2.get_num1().length() + res.get_num1().length() + 21), '~');
        std::cout << "                                                                     |" <<frame << "|\n";
        std::cout << "                                                                     | " << obj1 << " - " << obj2 << " = " << res << "\n";
        std::cout << "                                                                     |" << frame << "|\n";

        break;

    case '3':
    input_nums(str1, str2);
        obj1 = Finit(str1);
        obj2 = Finit(str2);
        std::cout << "Итак вы ввели два числа:\n\nПервое число: " << obj1 << "\nВторое число: " << obj2 << "\n\n";
        res = multy(obj1, obj2);
        frame = std::string((obj1.get_num1().length() + obj2.get_num1().length() + res.get_num1().length() + 21), '~');
        std::cout << "                                                                     |" <<frame << "|\n";
        std::cout << "                                                                     | " << obj1 << " * " << obj2 << " = " << res << "\n";
        std::cout << "                                                                     |" << frame << "|\n";
        break;
    
    case '4':
    input_nums(str1, str2);
        obj1 = Finit(str1);
        obj2 = Finit(str2);
        std::cout << "Итак вы ввели два числа:\n\nПервое число: " << obj1 << "\nВторое число: " << obj2 << "\n\n";
        res = int_div(obj1, obj2);
        frame = std::string((obj1.get_num1().length() + obj2.get_num1().length() + res.get_num1().length() + 31), '~');
        std::cout << "                                                                     |" <<frame << "|\n";
        std::cout << "                                                                     | " << obj1 << " / " << obj2 << " = " << res << "\n";
        std::cout << "                                                                     |" << frame << "|\n\n\n";
        break;

    case '5':
        obj1.get_r().print_plus();
        std::cout << "\n";
        break;

    case '6':
        obj1.get_r().print_plus_c();
        std::cout << "\n";
        break;

    case '7':
        obj1.get_r().print_times();
        std::cout << "\n";
        break;

    case '8':
        obj1.get_r().print_times_c();
        std::cout << "\n";
        break;

    case '9':
        std::cout << "\n";
        break;

    default:
        std::cout << "Некорректный ввод! Попробуйте ввести данные еще раз!\n\n";
        break;
    }
}

else{std::cout << "Некорректный ввод! Попробуйте выбрать действие еще раз!\n\n";}

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


}


}


bool menu::correct_data(std::string str){
    auto incorrect_char = [](std::string str) -> bool{
        std::vector<char> hasse = {'a', 'b', 'd', 'c', 'h', 'g', 'e', 'f', '-'};
        for(char c: str){
            auto it = find(hasse.begin(), hasse.end(), c);
            if(it == hasse.end()) return true;
        }
        return false;
    };
    Finit obj;
    int bit_depth = obj.get_bit_depth();
    if((str.length() > 8 && str[0] != '-') || (str.length() > 9 && str[0] == '-') 
                    ||  incorrect_char(str)) return false;
    return true;
}

void menu::del_a_before(std::string& stroka){
    std::vector<char> aybuben{'a', 'b', 'd', 'c', 'h', 'g', 'e', 'f'};
    int index = 0;
    for(char c: stroka){
        auto it = std::find(aybuben.begin(), aybuben.end(), c);
        if(*it == 'a')index++;
        else{break;}
    }
    stroka = stroka.substr(index);
}



void menu::input_nums(std::string& str1, std::string& str2){
    bool flag = false;

    std::cout << "Введите первое число из диапазона [-ffffffff; ffffffff]: \n";
    
    while(!flag){
        std::cin >> str1;
        del_a_before(str1);
        flag = correct_data(str1);
        if(!flag) std::cout << "Введите корректные данные!\n";
        else flag = true;
    }

    std::cout << "Введите второе число из диапазона [-ffffffff; ffffffff]: \n";

    flag = false;
    while(!flag){
        std::cin >> str2;
        del_a_before(str2);
        flag = correct_data(str2);
        if(!flag) std::cout << "Введите корректные данные!\n";
        else break;
    }

}