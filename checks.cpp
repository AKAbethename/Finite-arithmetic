#include "checks.hpp"
#include <iostream>

void check_one(){
    std::cout << "Let's check everything\n\n";

    std::vector<std::string> alph = {"a", "b", "c", "d", "e", "f", "g", "h"};

    bool flag1 = true;

    int ans = 1;

    Finit addition("abcdefgh");

//    for(auto& el1: alph){
//        for(auto& el2: alph) {
//            for(auto& el3: alph){
//                for(auto& el4: alph){
                    for(auto& el5: alph){
                        for(auto& el6: alph){
                            for(auto& el7: alph){
                                for(auto& el8: alph){
                                    std::string numnum(/*el1 + el2 + el3 + el4 + */el5 + el6 + el7 + el8);
                                    
                                    Finit obj1(el5 + el6 + el7 + el8);
                                    Finit obj2(el7+el8+el5+el6);
                                    if(obj1 < obj2){
                                
                                        Finit res_sub(obj2-obj1);
                                        Finit res_add(res_sub + obj1);
                                        std::cout << obj2 << " - " << obj1 << " = " << obj2 - obj1 << "\n";
                                        std::cout << obj1 << " + " << obj2 - obj1 << " = "  << obj2 << "\n";

                                        int obj1_int = obj1.translate();
                                        int obj2_int = obj2.translate();
                                        int obj_sub = (obj2 - obj1).translate();
                                        std::cout << obj2_int << " - " << obj1_int << " = " << obj2_int - obj1_int << "\n";
                                        std::cout << obj1_int << " + " << obj2_int - obj1_int << " = " << obj2_int << "\n";
                                        if(obj2_int - obj1_int != obj_sub) ans = 0;
                                        std::cout << "ans = " << ans << "------\n";
                                    }

                                }                       
                            }
                        }
                    }
//                }
//            }
//        }
//    }

    std::cout << "ans equals " << ans << "\n";
}


void check_two(){
    std::cout << "Let's check everything\n\n";

    std::vector<std::string> alph = {"a", "b", "c", "d", "e", "f", "g", "h"};

    bool flag1 = true;

    int ans = 1;

    int max_count = 50;
    int i = 0;
    bool flag_to_break = false;


    Finit addition("abcdefgh");
    //    for(auto& el1: alph){
//        for(auto& el2: alph) {
//            for(auto& el3: alph){
//                for(auto& el4: alph){
                    for(auto& el5: alph){
                        for(auto& el6: alph){
                            for(auto& el7: alph){
                                for(auto& el8: alph){
                                    std::string numnum(/*el1 + el2 + el3 + el4 + */el5 + el6 + el7 + el8);
                                    
                                    Finit obj1(el5 + el6 + el7 + "bdf");
                                    Finit obj2(el7+el8+el5 + "ddf");
                                    std::cout << obj1 << " * " << obj2 << " = " << multy(obj1, obj2) << "\n";
                                    int _obj1 = obj1.translate();
                                    int _obj2 = obj2.translate();
                                    std::cout << _obj1 << " * " << _obj2 << " = " << multy(obj1, obj2).translate() << "\n";
                                    int one = multy(obj1, obj2).get_sign() ? 1:-1;
                                    if(_obj1 * _obj2 != (multy(obj1, obj2).translate() * one) && !multy(obj1, obj2).get_lilbit()) {
                                        ans = 0;
                                        std::cout << obj1 << " and " << obj2 << "\n";
                                        break;
                                    }
                                    std::cout << "-----------------\n";
                                    ++i;
                                    if(i > max_count) flag_to_break = true;
                                    if(flag_to_break) break;
                                    }
                                    if(flag_to_break) break;
                                }    
                                if(flag_to_break) break;                   
                            }
                            if(flag_to_break) break;
                        }
//                }
//            }
//        }
//    }
                        if(ans == 1) std::cout << "everything was true\n";
                        else std::cout << "everything was false\n";

}


void check_three(){
    std::cout << "Let's check everything\n\n";

    std::vector<std::string> alph = {"a", "b", "c", "d", "e", "f", "g", "h"};

    bool flag1 = true;

    int ans = 1;

    int max_count = 20;
    int i = 0;
    bool flag_to_break = false;


    Finit addition("abcdefgh");
    //    for(auto& el1: alph){
//        for(auto& el2: alph) {
//            for(auto& el3: alph){
//                for(auto& el4: alph){
                    for(auto& el5: alph){
                        for(auto& el6: alph){
                            for(auto& el7: alph){
                                for(auto& el8: alph){
                                    std::string numnum(/*el1 + el2 + el3 + el4 + */el5 + el6 + el7 + el8);
                                    
                                    Finit obj1(el5 + el6 + el7 + "c");
                                    Finit obj2("-" + el7+el8+el5 + "d");
                                    Finit rest("eb");
                                    Finit M(multy(obj1, obj2));
                                   
                                    Finit Mm(summ(M, rest));
                                    Finit chastnoe(int_div(Mm, obj1));

                                    int obj1_ = obj1.translate();
                                    int obj2_ = obj2.translate();
                                    int rest_ = rest.translate();
                                    int M_ = M.translate();
                                    int Mm_ = Mm.translate();
                                    int chastnoe_ = chastnoe.translate();

                                    std::cout << obj1 << " * " << obj2 << " = " << M << "\n";
                                    std::cout << "in numbers: " << obj1_ << " * " << obj2_ << " = "
                                                                << M_ << "\n";
                                    if(M_ != obj1_ * obj2_) ans = 0;

                                    std::cout << Mm << " / " << obj1 << " = " 
                                                    << chastnoe << "\n";

                                    std::cout << "in numbers: " << Mm_ << " / " << obj1_
                                                << " = " << chastnoe_ << "[" << (chastnoe.get_rest() ? (*chastnoe.rest_value).translate() : 0) << "]\n";

                                    if(chastnoe_ * obj1_ + (*chastnoe.rest_value).translate() != Mm_) ans = 0;

                                

                                    std::cout << "-----------------\n";
                                    ++i;
                                    if(i > max_count) flag_to_break = true;
                                    if(flag_to_break) break;
                                    }
                                    if(flag_to_break) break;
                                }    
                                if(flag_to_break) break;                   
                            }
                            if(flag_to_break) break;
                        }
//                }
//            }
//        }
//    }
                        if(ans == 1) std::cout << "everything was true\n";
                        else std::cout << "everything was false\n";

}