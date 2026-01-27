#include "Rules.hpp"
#include <iostream>

#include <string>



Rules::Rules() : bit_depth(8), cnt_syms(8) {

//    std::cout << "Wrong ctor was called\n";

    Hasse.resize(8);
    Hasse = {'a', 'b', 'd', 'c', 'h', 'g', 'e', 'f'};
    table_plus = new char*[bit_depth];
    for(int i = 0; i < bit_depth; ++i){
        table_plus[i] = new char[bit_depth]; // Изменено: bit_depth вместо bit_depth + 1
    }

    // Инициализация первой строки и первого столбца
    for(int i = 0; i < bit_depth; ++i){
        table_plus[0][i] = 'a' + i;
        table_plus[i][0] = 'a' + i;
    }

    // Заполнение остальных ячеек (убраны дубликаты)
    table_plus[1][1] = 'd';
    table_plus[1][2] = 'h'; 
    table_plus[1][3] = 'c';
    table_plus[1][4] = 'f';
    table_plus[1][5] = 'a';
    table_plus[1][6] = 'e';
    table_plus[1][7] = 'g';

    table_plus[2][1] = 'h'; 
    table_plus[2][2] = 'e';
    table_plus[2][3] = 'g';
    table_plus[2][4] = 'b';
    table_plus[2][5] = 'd';
    table_plus[2][6] = 'a';
    table_plus[2][7] = 'f';

    table_plus[3][1] = 'c';
    table_plus[3][2] = 'g';
    table_plus[3][3] = 'h';
    table_plus[3][4] = 'a';
    table_plus[3][5] = 'b';
    table_plus[3][6] = 'f';
    table_plus[3][7] = 'e';

    table_plus[4][1] = 'f';
    table_plus[4][2] = 'b';
    table_plus[4][3] = 'a';
    table_plus[4][4] = 'h';
    table_plus[4][5] = 'g';
    table_plus[4][6] = 'c';
    table_plus[4][7] = 'd';

    table_plus[5][1] = 'a';
    table_plus[5][2] = 'd';
    table_plus[5][3] = 'b';
    table_plus[5][4] = 'g';
    table_plus[5][5] = 'e';
    table_plus[5][6] = 'h';
    table_plus[5][7] = 'c';

    table_plus[6][1] = 'e';
    table_plus[6][2] = 'a';
    table_plus[6][3] = 'f';
    table_plus[6][4] = 'c';
    table_plus[6][5] = 'h';
    table_plus[6][6] = 'd';
    table_plus[6][7] = 'b';

    table_plus[7][1] = 'g';
    table_plus[7][2] = 'f';
    table_plus[7][3] = 'e';
    table_plus[7][4] = 'd';
    table_plus[7][5] = 'c';
    table_plus[7][6] = 'b';
    table_plus[7][7] = 'a';



// plus_c

    table_plus_c = new char*[bit_depth];
    for(int i = 0; i < bit_depth; ++i){
        table_plus_c[i] = new char[bit_depth]; // Изменено: bit_depth вместо bit_depth + 1
    }

    // Инициализация первой строки и первого столбца
    for(int i = 0; i < bit_depth; ++i){
        table_plus_c[0][i] = 'a';
        table_plus_c[i][0] = 'a';
    }

    // Заполнение остальных ячеек (убраны дубликаты)
    table_plus_c[1][1] = 'a';
    table_plus_c[1][2] = 'a'; 
    table_plus_c[1][3] = 'a';
    table_plus_c[1][4] = 'a';
    table_plus_c[1][5] = 'b';
    table_plus_c[1][6] = 'a';
    table_plus_c[1][7] = 'a';

    table_plus_c[2][1] = 'a'; 
    table_plus_c[2][2] = 'a';
    table_plus_c[2][3] = 'a';
    table_plus_c[2][4] = 'b';
    table_plus_c[2][5] = 'b';
    table_plus_c[2][6] = 'b';
    table_plus_c[2][7] = 'a';

    table_plus_c[3][1] = 'a';
    table_plus_c[3][2] = 'a';
    table_plus_c[3][3] = 'a';
    table_plus_c[3][4] = 'b';
    table_plus_c[3][5] = 'b';
    table_plus_c[3][6] = 'a';
    table_plus_c[3][7] = 'a';

    table_plus_c[4][1] = 'a';
    table_plus_c[4][2] = 'b';
    table_plus_c[4][3] = 'b';
    table_plus_c[4][4] = 'b';
    table_plus_c[4][5] = 'b';
    table_plus_c[4][6] = 'b';
    table_plus_c[4][7] = 'b';

    table_plus_c[5][1] = 'b';
    table_plus_c[5][2] = 'b';
    table_plus_c[5][3] = 'b';
    table_plus_c[5][4] = 'b';
    table_plus_c[5][5] = 'b';
    table_plus_c[5][6] = 'b';
    table_plus_c[5][7] = 'b';

    table_plus_c[6][1] = 'a';
    table_plus_c[6][2] = 'b';
    table_plus_c[6][3] = 'a';
    table_plus_c[6][4] = 'b';
    table_plus_c[6][5] = 'b';
    table_plus_c[6][6] = 'b';
    table_plus_c[6][7] = 'b';

    table_plus_c[7][1] = 'a';
    table_plus_c[7][2] = 'a';
    table_plus_c[7][3] = 'a';
    table_plus_c[7][4] = 'b';
    table_plus_c[7][5] = 'b';
    table_plus_c[7][6] = 'b';
    table_plus_c[7][7] = 'b';


// multipl x_s


    table_times = new char*[bit_depth];
    for(int i = 0; i < bit_depth; ++i){
        table_times[i] = new char[bit_depth];
    }

    // Инициализация первой строки и первого столбца
    for(int i = 0; i < bit_depth; ++i){
        table_times[0][i] = 'a';
        table_times[i][0] = 'a';
    }

    // Заполнение остальных ячеек
    table_times[1][1] = 'b';
    table_times[1][2] = 'c'; 
    table_times[1][3] = 'd';
    table_times[1][4] = 'e';
    table_times[1][5] = 'f';
    table_times[1][6] = 'g';
    table_times[1][7] = 'h';

    table_times[2][1] = 'c'; 
    table_times[2][2] = 'b';
    table_times[2][3] = 'e';
    table_times[2][4] = 'd';
    table_times[2][5] = 'g';
    table_times[2][6] = 'f';
    table_times[2][7] = 'h';

    table_times[3][1] = 'd';
    table_times[3][2] = 'e';
    table_times[3][3] = 'h';
    table_times[3][4] = 'h';
    table_times[3][5] = 'e';
    table_times[3][6] = 'd';
    table_times[3][7] = 'f';

    table_times[4][1] = 'e';
    table_times[4][2] = 'd';
    table_times[4][3] = 'h';
    table_times[4][4] = 'h';
    table_times[4][5] = 'd';
    table_times[4][6] = 'e';
    table_times[4][7] = 'a';

    table_times[5][1] = 'f';
    table_times[5][2] = 'g';
    table_times[5][3] = 'e';
    table_times[5][4] = 'd';
    table_times[5][5] = 'b';
    table_times[5][6] = 'c';
    table_times[5][7] = 'h';

    table_times[6][1] = 'g';
    table_times[6][2] = 'f';
    table_times[6][3] = 'd';
    table_times[6][4] = 'e';
    table_times[6][5] = 'c';
    table_times[6][6] = 'b';
    table_times[6][7] = 'h';

    table_times[7][1] = 'h'; // Изменено: было 'g'
    table_times[7][2] = 'h'; // Изменено: было 'f'
    table_times[7][3] = 'f'; // Изменено: было 'e'
    table_times[7][4] = 'a';
    table_times[7][5] = 'h';
    table_times[7][6] = 'h';
    table_times[7][7] = 'a';


// times_c

    table_times_c = new char*[bit_depth];

    for(int i = 0; i < bit_depth; ++i){
        table_times_c[i] = new char[bit_depth];
    }

    for(int i = 0; i < bit_depth; ++i){
        table_times_c[0][i] = 'a';
        table_times_c[i][0] = 'a';
    }

    table_times_c[1][1] = 'a';
    table_times_c[1][2] = 'a'; 
    table_times_c[1][3] = 'a';
    table_times_c[1][4] = 'a';
    table_times_c[1][5] = 'a';
    table_times_c[1][6] = 'a';
    table_times_c[1][7] = 'a';

    table_times_c[2][1] = 'a'; 
    table_times_c[2][2] = 'b';
    table_times_c[2][3] = 'a';
    table_times_c[2][4] = 'd';
    table_times_c[2][5] = 'd';
    table_times_c[2][6] = 'b';
    table_times_c[2][7] = 'b';

    table_times_c[3][1] = 'a';
    table_times_c[3][2] = 'a';
    table_times_c[3][3] = 'a';
    table_times_c[3][4] = 'b';
    table_times_c[3][5] = 'b';
    table_times_c[3][6] = 'b';
    table_times_c[3][7] = 'b';

    table_times_c[4][1] = 'a';
    table_times_c[4][2] = 'd';
    table_times_c[4][3] = 'b';
    table_times_c[4][4] = 'h';
    table_times_c[4][5] = 'g';
    table_times_c[4][6] = 'c';
    table_times_c[4][7] = 'c';

    table_times_c[5][1] = 'a';
    table_times_c[5][2] = 'd';
    table_times_c[5][3] = 'b';
    table_times_c[5][4] = 'g';
    table_times_c[5][5] = 'e';
    table_times_c[5][6] = 'h';
    table_times_c[5][7] = 'c';

    table_times_c[6][1] = 'a';
    table_times_c[6][2] = 'b';
    table_times_c[6][3] = 'b';
    table_times_c[6][4] = 'c';
    table_times_c[6][5] = 'h';
    table_times_c[6][6] = 'c';
    table_times_c[6][7] = 'd';

    table_times_c[7][1] = 'a';
    table_times_c[7][2] = 'b';  
    table_times_c[7][3] = 'b'; 
    table_times_c[7][4] = 'c';
    table_times_c[7][5] = 'c';
    table_times_c[7][6] = 'd';
    table_times_c[7][7] = 'd';


}

#if 1

void Rules::print_plus(){
    std::cout << "---Table of addition +_s--- \n\n";
    std::cout << "+s| ";
    for(int i = 0; i < 8; ++i){
        std::cout  << static_cast<char>('a' + i) << "\t";
    }
    std::cout << "\n";
    std::cout << "";
    for(int j = 0; j < 29; ++j){
        std::cout << "--";
    }
    std::cout << "\n";


    char table[8][8] = {
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'b', 'd', 'h', 'c', 'f', 'a', 'e', 'g'},
        {'c', 'h', 'e', 'g', 'b', 'd', 'a', 'f'},
        {'d', 'c', 'g', 'h', 'a', 'b', 'f', 'e'},
        {'e', 'f', 'b', 'a', 'h', 'g', 'c', 'd'},
        {'f', 'a', 'd', 'b', 'g', 'e', 'h', 'c'},
        {'g', 'e', 'a', 'f', 'c', 'h', 'd', 'b'},
        {'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'},
    };


    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << " | ";
        for(int j = 0; j < bit_depth; ++j){
            std::cout <<  table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";
}

#endif


void Rules::print_plus_c(){
    std::cout << "---Table of addition +_c--- \n\n";
    std::cout << "+c| ";
    for(int i = 0; i < 8; ++i){
        std::cout  << static_cast<char>('a' + i) << "\t";
    }
    std::cout << "\n";
    std::cout << "";
    for(int j = 0; j < 29; ++j){
        std::cout << "--";
    }
    std::cout << "\n";

    char table[8][8] = {
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'b', 'a'},
        {'a', 'a', 'a', 'b', 'b', 'b', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'b', 'b', 'a', 'a'},
        {'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b'},
        {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
        {'a', 'a', 'b', 'a', 'b', 'b', 'b', 'b'},
        {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b'},
    };

    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << " | ";
        for(int j = 0; j < bit_depth; ++j){
            std::cout <<  table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";
}

void Rules::print_times(){
    std::cout << "---Table of multiplication *_s--- \n\n";
    std::cout << "*s| ";
    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << "\t";
    }
    std::cout << "\n";
    
    std::cout << "";
    for(int j = 0; j < bit_depth * 2 + 13; ++j){
        std::cout << "--";
    }
    std::cout << "\n";

    char table[8][8] = {
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'},
        {'a', 'c', 'b', 'e', 'd', 'g', 'f', 'h'},
        {'a', 'd', 'e', 'h', 'h', 'e', 'd', 'a'},
        {'a', 'e', 'd', 'h', 'h', 'd', 'e', 'a'},
        {'a', 'f', 'g', 'e', 'd', 'b', 'c', 'h'},
        {'a', 'g', 'f', 'd', 'e', 'c', 'b', 'h'},
        {'a', 'h', 'h', 'a', 'a', 'h', 'h', 'a'},
    };

    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << " | ";
        for(int j = 0; j < bit_depth; ++j){
            std::cout << table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";
}


void Rules::print_times_c(){
    std::cout << "---Table of multiplication *_c--- \n\n";
    std::cout << "*c| ";
    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << "\t";
    }
    std::cout << "\n";
    std::cout << "";
    for(int j = 0; j < 29; ++j){
        std::cout << "--";
    }
    std::cout << "\n";

    char table[8][8] = {
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'a', 'a', 'a', 'a', 'a', 'a'},
        {'a', 'a', 'b', 'a', 'd', 'd', 'b', 'b'},
        {'a', 'a', 'a', 'a', 'b', 'b', 'b', 'b'},
        {'a', 'a', 'd', 'b', 'h', 'g', 'c', 'c'},
        {'a', 'a', 'd', 'b', 'g', 'e', 'h', 'c'},
        {'a', 'a', 'b', 'b', 'c', 'h', 'c', 'd'},
        {'a', 'a', 'b', 'b', 'c', 'c', 'd', 'd'},
    };

    for(int i = 0; i < bit_depth; ++i){
        std::cout << static_cast<char>('a' + i) << " | ";
        for(int j = 0; j < bit_depth; ++j){
            std::cout << table[i][j] << "\t";
        }
        std::cout << "\n";
    }

    std::cout << "\n\n";
}


Rules::Rules(int bit_depth, int cnt_syms) : bit_depth(bit_depth), cnt_syms(cnt_syms), table_plus(nullptr),  // Явная инициализация
      table_plus_c(nullptr),
      table_times(nullptr),
      table_times_c(nullptr)  {

//    std::cout << "Right ctor was called\n";

    Hasse.resize(8);
    Hasse = {'a', 'b', 'd', 'c', 'h', 'g', 'e', 'f'};

    plus.resize((bit_depth * (bit_depth-1) / 2) + bit_depth);

    int k = 0;
    std::string left_op = "a";
    std::string right_op = "a";

    while(k < 8){  
        char ar[9] = "abcdefgh";  
        right_op[0] = ar[k];
        
        plus[k] = left_op + "+" + right_op + "=" + ar[k];
        
        ++k;
    }


    plus[8] = "b+b=d";
    plus[9] = "b+c=h";
    plus[10] = "b+d=c";
    plus[11] = "b+e=f";
    plus[12] = "b+f=a";
    plus[13] = "b+g=e";
    plus[14] = "b+h=g";

    plus[15] = "c+c=e";
    plus[16] = "c+d=g";
    plus[17] = "c+e=b";
    plus[18] = "c+f=d";
    plus[19] = "c+g=a";
    plus[20] = "c+h=f";

    plus[21] = "d+d=h";
    plus[22] = "d+e=a";
    plus[23] = "d+f=b";
    plus[24] = "d+g=f";
    plus[25] = "d+h=e";

    plus[26] = "e+e=h";
    plus[27] = "e+f=g";
    plus[28] = "e+g=c";
    plus[29] = "e+h=d";

    plus[30] = "f+f=e";
    plus[31] = "f+g=h";
    plus[32] = "f+h=c";

    plus[33] = "g+g=d";
    plus[34] = "g+h=b";

    plus[35] = "h+h=a";


// -----------------plus_c-----------

plus_c.resize((bit_depth * (bit_depth-1) / 2) + bit_depth);

    k = 0;
    left_op = "a";
    right_op = "a";

    while(k < 8){  
        char ar[9] = "abcdefgh";  
        right_op[0] = ar[k];
        
        plus_c[k] = left_op + "+" + right_op + "=" + "a";
        
        ++k;
    }


    plus_c[8] = "b+b=a";
    plus_c[9] = "b+c=a";
    plus_c[10] = "b+d=a";
    plus_c[11] = "b+e=a";
    plus_c[12] = "b+f=b";
    plus_c[13] = "b+g=a";
    plus_c[14] = "b+h=a";

    plus_c[15] = "c+c=a";
    plus_c[16] = "c+d=a";
    plus_c[17] = "c+e=b";
    plus_c[18] = "c+f=b";
    plus_c[19] = "c+g=b";
    plus_c[20] = "c+h=a";


    plus_c[21] = "d+d=a";
    plus_c[22] = "d+e=b";
    plus_c[23] = "d+f=b";
    plus_c[24] = "d+g=a";
    plus_c[25] = "d+h=a";

    plus_c[26] = "e+e=b";
    plus_c[27] = "e+f=b";
    plus_c[28] = "e+g=b";
    plus_c[29] = "e+h=b";

    plus_c[30] = "f+f=b";
    plus_c[31] = "f+g=b";
    plus_c[32] = "f+h=b";

    plus_c[33] = "g+g=b";
    plus_c[34] = "g+h=b";

    plus_c[35] = "h+h=b";


// ---------TIMES---------

    times.resize((bit_depth * (bit_depth-1) / 2) + bit_depth);
    k = 0;
    left_op = "a";
    right_op = "a";

    while(k < 8){  
        char ar[9] = "abcdefgh";  
        right_op[0] = ar[k];
        
        times[k] = left_op + "+" + right_op + "=" + "a";
        
        ++k;
    }


    times[8] = "b+b=b";
    times[9] = "b+c=c";
    times[10] = "b+d=d";
    times[11] = "b+e=e";
    times[12] = "b+f=f";
    times[13] = "b+g=g";
    times[14] = "b+h=h";

    times[15] = "c+c=b";
    times[16] = "c+d=e";
    times[17] = "c+e=d";
    times[18] = "c+f=g";
    times[19] = "c+g=f";
    times[20] = "c+h=h";


    times[21] = "d+d=h";
    times[22] = "d+e=h";
    times[23] = "d+f=e";
    times[24] = "d+g=d";
    times[25] = "d+h=a";

    times[26] = "e+e=h";
    times[27] = "e+f=d";
    times[28] = "e+g=e";
    times[29] = "e+h=a";

    times[30] = "f+f=b";
    times[31] = "f+g=c";
    times[32] = "f+h=h";

    times[33] = "g+g=b";
    times[34] = "g+h=h";

    times[35] = "h+h=a";



// ---------TIMES_C------------

times_c.resize((bit_depth * (bit_depth-1) / 2) + bit_depth);
    k = 0;
    left_op = "a";
    right_op = "a";

    while(k < 8){  
        char ar[9] = "abcdefgh";  
        right_op[0] = ar[k];
        
        times_c[k] = left_op + "+" + right_op + "=" + "a";
        
        ++k;
    }


    times_c[8] = "b+b=a";
    times_c[9] = "b+c=a";
    times_c[10] = "b+d=a";
    times_c[11] = "b+e=a";
    times_c[12] = "b+f=a";
    times_c[13] = "b+g=a";
    times_c[14] = "b+h=a";

    times_c[15] = "c+c=b";
    times_c[16] = "c+d=a";
    times_c[17] = "c+e=d";
    times_c[18] = "c+f=d";
    times_c[19] = "c+g=b";
    times_c[20] = "c+h=b";


    times_c[21] = "d+d=a";
    times_c[22] = "d+e=b";
    times_c[23] = "d+f=b";
    times_c[24] = "d+g=b";
    times_c[25] = "d+h=b";

    times_c[26] = "e+e=h";
    times_c[27] = "e+f=g";
    times_c[28] = "e+g=c";
    times_c[29] = "e+h=c";

    times_c[30] = "f+f=e";
    times_c[31] = "f+g=h";
    times_c[32] = "f+h=c";

    times_c[33] = "g+g=c";
    times_c[34] = "g+h=d";

    times_c[35] = "h+h=a";
    

}

void Rules::print_vector_plus(){
    for(const auto& el: plus){
        std::cout << el << "\t";
    }
    std::cout << "\n\n";
}

char Rules::eval_plus(char one, char two) const{
    for(const auto& str: plus){
        if((str[0] == one && str[2] == two) || (str[0] == two && str[2] == one)){
            return str[4];
      //      return str;
        }
    }
    return 'q';
}


char Rules::eval_plus_c(char one, char two) const{
    for(const auto& str: plus_c){
        if((str[0] == one && str[2] == two) || (str[0] == two && str[2] == one)){
            return str[4];
      //      return str;
        }
    }
    return 'q';
}


char Rules::eval_times(char one, char two) const{
    for(const auto& str: times){
        if((str[0] == one && str[2] == two) || (str[0] == two && str[2] == one)){
            return str[4];
      //      return str;
        }
    }
    return 'q';
}


char Rules::eval_times_c(char one, char two) const{
    for(const auto& str: times_c){
        if((str[0] == one && str[2] == two) || (str[0] == two && str[2] == one)){
            return str[4];
      //      return str;
        }
    }
    return 'q';
}


std::vector<char> Rules::get_hasse(){
    return Hasse;
}





