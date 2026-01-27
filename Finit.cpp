#include "Finit.hpp"

#include <iostream>
#include <cassert>
#include <algorithm>  // для std::find
#include <cmath>


Finit::Finit() : bit_depth(8) {

    num1.resize(bit_depth);
//    num2.resize(bit_depth);
//    res.resize(bit_depth);

    aybuben.resize(8);
    aybuben = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    r = Rules(8, 8);
    make_normal_for_us(num1);

    num1 = "a";


}

Finit::Finit(const Finit& M){
    bit_depth = M.bit_depth;
    aybuben = M.aybuben;
    num1 = M.num1;
    dop_num1 = M.dop_num1;
    r = M.r;
    sign = M.sign;
    lilbit = M.lilbit;
#if 1
    rest = M.rest;
    empty_set = M.empty_set;
    full_segment = M.full_segment;
    rest_value = new Finit;
    *rest_value = *M.rest_value;
#endif
}

Finit& Finit::operator=(const Finit& obj){
    if(*this == obj) return *this;
    bit_depth = obj.bit_depth;
    aybuben = obj.aybuben;
    num1 = obj.num1;
    dop_num1 = obj.dop_num1;
    r = obj.r;
    sign = obj.sign;
    lilbit = obj.lilbit;
#if 1
    rest = obj.rest;
    empty_set = obj.empty_set;
    full_segment = obj.full_segment;
    rest_value = new Finit;
    *rest_value = *obj.rest_value;
#endif
    return *this;
}

Finit::Finit(std::string num) : bit_depth(8) {
    rest_value = new Finit;
    r = Rules(8, 8);

    if(num[0] == '-') {sign = false; num = num.substr(1);}
    else sign = true;


    make_normal_for_us(num);  // здесь num -- строка без знака, информация о знаке в поле sign

    this->num1 = num;

    aybuben.resize(8);
    aybuben = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
//    lilbit = false;

//    r = Rules(8, 8);
}

void Finit::make_normal_for_us(std::string& num){
    if (num.length() < bit_depth) {
        // Дополняем слева символами 'a' (нулями)
        std::string padding(bit_depth - num.length(), 'a');
        num = padding + num;
    }
}

std::string Finit::make_normal_for_user(const std::string& num) const{
    std::string ans;
    ans.resize(10);
//    assert(num.length() == bit_depth);
    for(int i = 0; i < bit_depth; ++i){
        if(num[i] != 'a'){
            ans = num.substr(i);
            break;
        } 
    }
    if(num == "aaaaaaaa") return "a";
    return ans;
}

bool operator<(const Finit& num1, const Finit& num2){  // сравнивает модули!!!
    int bit_depth = num1.bit_depth;

//        if(!num1.get_sign() && num2.get_sign()) return true;
//    if(num1.get_sign() && !num2.get_sign()) return false;

    Rules r = num1.r;

    std::vector<char> hasse = r.get_hasse();
    bool flag = false;

    for(int i = 0; i < bit_depth; ++i){
        auto it = std::find(hasse.begin(), hasse.end(), num1[i]);
        int index_1 = std::distance(hasse.begin(), it);
        auto it1 = std::find(hasse.begin(), hasse.end(), num2[i]);
        int index_2 = std::distance(hasse.begin(), it1);

        if(index_1 < index_2) {flag = true; break;}
        else if(index_1 > index_2) {flag = false; break;}
    }

    return flag;
}

bool operator<=(const Finit& obj1, const Finit& obj2){
    if(obj1 < obj2 || obj1 == obj2) return true;
    return false;
}

Finit::~Finit(){if(rest_value) delete rest_value;}

Finit operator+(const Finit& left_op, const Finit& right_op){
    Rules R(8, 8);

    int len_left = left_op.num1.length();
    int len_right = right_op.num1.length();


    Finit ref_left_op(left_op);
    Finit ref_right_op(right_op);

    std::string res;
    res.resize(8);

    char x = 'a';
    char x_new = 'a';

    for(int i = 7; i != -1; --i){

        char l = left_op.num1[i];
        char r = right_op.num1[i];

        res[i] = R.eval_plus(l, r);


        x_new = R.eval_plus_c(l, r);

        if(x_new == 'a') x_new = R.eval_plus_c(res[i], x);

        res[i] = R.eval_plus(res[i], x);


        x = x_new;
    }

    Finit obj(res);
#if 0
    if(left_dop < right_op || right_dop < left_op){
        obj.lilbit = true;
    }
#endif
    return obj;

}

//bool Finit::get_lilbit(){return lilbit;}

void Finit::set_lilbit(bool flag){
    lilbit = flag;
}

bool Finit::get_lilbit() const{return lilbit;}


#if 0
Finit operator+(const Finit& left_op, const Finit& right_op){
    Rules R(8, 8);

    int len_left = left_op.num1.length();
    int len_right = right_op.num1.length();


    std::string res;
    res.resize(8);

    char x = 'a';
    char x_new = 'a';

    for(int i = 7; i != -1; --i){

        char l = left_op.num1[i];
        char r = right_op.num1[i];

        res[i] = R.eval_plus(l, r);


        x_new = R.eval_plus_c(l, r);

        if(x_new == 'a') x_new = R.eval_plus_c(res[i], x);

        res[i] = R.eval_plus(res[i], x);


        x = x_new;
    }

    Finit obj(res);

    return obj;
}

#endif

char Finit::operator[](int index) const{
    return num1[index];
}

#if 1
bool operator==(const Finit& left_op, const Finit& right_op){
    int bit_depth = left_op.bit_depth;

    for(int i = 0; i < bit_depth; ++i){
        if(left_op[i] != right_op[i]) return false;
    }
    return true;
}

#endif

bool Finit::get_rest() const{return rest;}

bool Finit::get_empty_set() const{return empty_set;}

bool Finit::get_full_segment() const{return full_segment;}


std::ostream& operator<<(std::ostream& m, const Finit& obj) {
    std::string ans = obj.make_normal_for_user(obj.num1);
    if(obj.lilbit){ m << "Переполнение!"; return m;}
    if(obj.get_empty_set()) {m << "Ø"; return m;}
    if(obj.get_full_segment()) {m << "[" << obj.MIN << "; " << obj.MAX << "]"; return m;}
    if(!obj.get_sign()) m << "-";
    if(obj.get_rest()) {m << ans << "[" << *obj.rest_value << "]"; return m;}
    m << ans;
    return m;
}


void Finit::eval_dop(){
    Rules R(bit_depth, bit_depth);
    std::string last_num("f", bit_depth);

    std::string almost_dop;

    almost_dop.resize(bit_depth);

    for(int i = 0; i < bit_depth; ++i){
        for(const auto& el: aybuben){
            if(R.eval_plus(num1[i], el) == 'f') almost_dop[i] = el;
        }
    }
    std::string one_str = "aaaaaaab";
    Finit one(one_str);
    
    Finit cur(almost_dop);

    this->dop_num1 = (cur + one).num1;

//    if(num1 == "aaaaaaaa") this->dop_num1 = "ffffffff";
    if(num1 == "aaaaaaaa") this->dop_num1 = "aaaaaaaa";

}

std::string Finit::get_dop() const{return dop_num1;}


Finit operator-(const Finit& left_op, Finit& right_op){
    Rules R(8, 8);

    right_op.eval_dop();

//    std::cout << "right op is " << right_op << "\n";

//    std::cout << right_op.get_dop() << " is dop\n";

    Finit tmp(right_op.get_dop());

    return left_op + tmp;
}


std::string Finit::get_num1() {
    std::string result = make_normal_for_user(num1);
    if (!sign) {
        return "-" + result;  // правильно: сложение строк
    }
    return result;
}

bool Finit::get_sign() const{return sign;}

int Finit::get_bit_depth() const{return bit_depth;}

void Finit::set_sign(bool flag){sign = flag;}

Finit summ(Finit& obj1, Finit& obj2){
    Finit e("a");
//    std::cout << "here?\n";
    if(obj1 == obj2 && obj1 == e) return e; 
    if(obj1 == e)return obj2;
    if(obj2 == e) return obj1;

//    std::cout << obj1 << " and " << obj2 << " is check\n";
    if(obj1.get_sign() && obj2.get_sign()){
        Finit sum = obj1 + obj2;
        sum.set_sign(true);  // positive sum
        obj1.eval_dop();
        obj2.eval_dop();
        Finit obj1_dop = obj1.get_dop();
        Finit obj2_dop = obj2.get_dop();
        if(obj1_dop <= obj2 || obj2_dop <= obj1) sum.set_lilbit(true);
        if(sum == e) sum.set_sign(true);
        return sum;
    }
    else if(!obj1.get_sign() && !obj2.get_sign()){
        Finit sum = obj1 + obj2;
        sum.set_sign(false);  // negative sum
        obj1.eval_dop();
        obj2.eval_dop();
        Finit obj1_dop = obj1.get_dop();
        Finit obj2_dop = obj2.get_dop();
        if(obj1_dop <= obj2 || obj2_dop <= obj1) sum.set_lilbit(true);
        if(sum == e) sum.set_sign(true);
        return sum;
    }
    else if(obj1.get_sign() && !obj2.get_sign()){
//        std::cout << "we are here!" << "\n";
        Finit sum;
        if(obj1 < obj2){sum = obj2 - obj1; sum.set_sign(false);} // исправил меньшее на большее
        else{sum = obj1 - obj2; sum.set_sign(true);}
        if(sum == e) sum.set_sign(true);
        return sum;
    }
    else if(!obj1.get_sign() && obj2.get_sign()){
        Finit sum;
        if(obj1 < obj2){sum = obj2 - obj1; sum.set_sign(true);}
        else{sum = obj1 - obj2; sum.set_sign(false);}
        if(sum == e) sum.set_sign(true);
        return sum;
    }
    return Finit();
}


Finit subb(Finit& obj1, Finit& obj2){
    Finit tmp = obj2;
    Finit e("a");
//    std::cout << "here?\n";
    if(obj2.get_sign()) tmp.set_sign(false);
    else tmp.set_sign(true);
    if(obj1 == e) {if(tmp == e) tmp.set_sign(true); return tmp;}
    else if(obj2 == e) return obj1;
    return summ(obj1, tmp);
}

Finit operator-(Finit num1){
    num1.set_sign(false);
    return num1;
}

Finit one_mult_one(Finit& obj1, Finit& obj2){ // каждый из операндов -- одна буква!
    Rules R(8, 8);
    std::string part1;
    part1.resize(8);

    part1[0] = R.eval_times_c(obj1[7], obj2[7]);
    part1[1] = R.eval_times(obj1[7], obj2[7]);
    return Finit(part1);

}

Finit mult_with_a(Finit& obj1, Finit& obj2){  // умножение чисел виде ?a..a * ?a..a  example: daaa * faa
    auto cnt_of_a = [](Finit& obj) -> int {
        int ans = 0;
        for(char c: obj.get_num1()){
            if(c == 'a') ans++;
        }
        return ans;
    };
    int bit_depth = obj1.get_bit_depth();

    int cnt_1 = cnt_of_a(obj1);
    int cnt_2 = cnt_of_a(obj2);

    std::string last_part(cnt_1 + cnt_2, 'a');  // aaa + aa
    std::string let1(1, obj1[bit_depth - cnt_1 - 1]);
    std::string let2(1, obj2[bit_depth - cnt_2 - 1]);

    Finit letter1(let1);  // d
    Finit letter2(let2);  // f

    Finit first_part = one_mult_one(letter1, letter2);

    std::string res; res.resize(10);
    res = first_part.get_num1() + last_part;

    Finit resultat(res);

    return Finit(res);


}

int Finit::cnt_of_a() const{
    int ans = 0;
    std::string num_for_user = make_normal_for_user(num1);
//    std::cout << num_for_user << " in func cnt_of_a\n";
        for(char c: num_for_user){
            if(c == 'a') ans++;
        }
        return ans;
}


Finit multy(Finit& obj1, Finit& obj2){
    if(obj1.get_num1() == "a" || obj2.get_num1() == "a") return Finit("a");
    Finit cnt("ab");
    Finit step("ab");
    
    Finit min, max;
    min = (obj1 < obj2) ? obj1 : obj2;
    max = (obj1 < obj2) ? obj2 : obj1;
    Finit ans(max);

    if(ans.get_lilbit()) std::cout << "error!\n";
    while(cnt < min){
        Finit sum(summ(ans, max));
        ans = sum;
        cnt = summ(step, cnt);

        if(ans.get_lilbit()) break;
    }

    if(obj1.get_sign() == obj2.get_sign()) ans.set_sign(true);
    else ans.set_sign(false);

    return ans;

}

Finit int_div(Finit& obj1, Finit& obj2){
    Finit e("a");
    Finit add("b");
    Finit res("a");

    if(obj1 == res && obj2 == res) {res.set_full_segment(true); return res;}
    if(obj2 == res) {res.set_empty_set(true); return res;}

    if(obj2 == add) return obj1;
    

    if(e < obj1 && e < obj2 && (obj1.get_sign() && obj2.get_sign() 
                           ) ){

        if(obj1 < obj2) {res.set_rest(true); *res.rest_value = obj1; return res;}
        Finit tmp(obj1);
        while(obj2 <= tmp){
            tmp = subb(tmp, obj2);
            res = summ(res, add);
        }
        if(e < tmp){
            res.set_rest(true);
            *res.rest_value = tmp;
        }
        (*res.rest_value).set_sign(true);
    }
    else if(e < obj1 && e < obj2 && !obj1.get_sign() && obj2.get_sign()){
        Finit tmp(obj1);
        while(!tmp.get_sign()){
            if(tmp <= obj2 && !tmp.get_sign()){tmp.set_sign(true); tmp = subb(obj2, tmp);}  // если прибавляем к отрицательному положительное, большее
                                            // по модулю, то меняем знак отрицательного
            else{tmp = summ(tmp, obj2);}
            res = summ(res, add);
        }
        if(tmp.get_sign() && (e < tmp)){
            res.set_rest(true);
            *res.rest_value = tmp;    
        }
        res.set_sign(false);
        
    }

    else if(e < obj1 && e < obj2 && !obj1.get_sign() && !obj2.get_sign()){
        Finit tmp(obj1);
        Finit obj2_2(-obj2);
        obj2_2.set_sign(true);
        while(!tmp.get_sign()){
            if(tmp <= obj2_2 && !tmp.get_sign()){tmp.set_sign(true); tmp = subb(obj2_2, tmp);}  // если прибавляем к отрицательному положительное, большее
                                            // по модулю, то меняем знак отрицательного
            else{tmp = summ(tmp, obj2_2);}
            res = summ(res, add);
        }
        if(tmp.get_sign() && (e < tmp)){
            res.set_rest(true);
            *res.rest_value = tmp;    
        }
        res.set_sign(true);
    }

    else if(e < obj1 && e < obj2 && (obj1.get_sign() && !obj2.get_sign() 
                           ) ){
        if(obj1 < obj2) {res.set_rest(true); res.set_sign(true); *res.rest_value = obj1;  return res;}
        Finit obj2_obj2(obj2);
        obj2_obj2.set_sign(true);
        Finit tmp(obj1);
        while(obj2_obj2 <= tmp){
            tmp = subb(tmp, obj2_obj2);
            res = summ(res, add);
        }
        if(e < tmp){
            res.set_rest(true);
            *res.rest_value = tmp;
        }
        (*res.rest_value).set_sign(true);
        res.set_sign(false);
    }
    
    return res;
}


Finit gcd(Finit obj1, Finit obj2){
    if(obj1 == obj2) return obj1;
    if(obj2 < obj1) {Finit sub(subb(obj1, obj2)); return gcd(sub, obj2);}
    Finit sub(subb(obj2, obj1));
    return gcd(obj1, sub);
}

Rules Finit::get_r(){return r;}
void Finit::set_rest(bool flag){rest = flag;}

void Finit::set_full_segment(bool flag){full_segment = flag;}

void Finit::set_empty_set(bool flag){empty_set = flag;}

// убрать translate обязательно!!!!

int Finit::translate(){
    int ans = 0;
    int bit_depth = 8;
    std::vector<char> hasse = {'a', 'b', 'd', 'c', 'h', 'g', 'e', 'f'};
    auto get_index = [bit_depth, hasse](char symbol){
        for(int i = 0; i < bit_depth; ++i){
            if(hasse[i] == symbol) return i;
        }
        return -1;
    };

    for(int i = 0; i < bit_depth; ++i){
        ans += get_index(num1[i]) * pow(bit_depth, bit_depth-i-1);
    }

    return ans;
}


