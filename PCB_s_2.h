//
// Created by chicha-man on 12.10.2021.
//

#ifndef LAB3_2_PCB_S_2_H
#define LAB3_2_PCB_S_2_H
#include <iostream>

namespace PCB_1 {
    struct contact {
        bool exist;
        bool type; //F - out, T - in
        int connect;
        double x;
        double y;
        contact(){
            exist = false;
            type = false;
            connect = -1;
            x = 0;
            y = 0;
        }
    };

    class PCB {
    private:
        static const int sz = 10;
        int curr_sz;
        contact arr[sz];
    public:
        PCB() : curr_sz(0) {};

        static int getSZ() {return sz;}
        contact * getARR() {return arr;}

        int create_contact(bool type, double x, double y);
        int establish_connect(int name1, int name2);
        int operator +(const contact & src);// +=
        int correction_check(int name1, int name2);
        int get_track_length(int name1, int name2);
        PCB & select_group(int type);
        friend std::ostream & operator << (std::ostream& buff, const PCB & plate);
        //преобразование типов в и из класса в число
    };
}

#endif //LAB3_2_PCB_S_2_H
