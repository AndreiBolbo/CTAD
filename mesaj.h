//
// Created by MSI on 14/05/2022.
//

#ifndef CURS9ABC_MESAJ_H
#define CURS9ABC_MESAJ_H

#include "sstream"

using namespace std;
class Mesaj {
private:
    int id_1; // id trimitator
    int id_2; //id destinatar
    string text; //mesaj
    time_t ttime; // ora
public:
    Mesaj();
    Mesaj(int id1,int id2, string text, time_t ttime);
    time_t get_time();
    Mesaj& operator=(const Mesaj &m);
    bool operator==(const Mesaj &m);
    bool operator<(const Mesaj &m);
    bool operator>(const Mesaj &m);
    int get_id1();
    int get_id2();
    string get_text();
};


#endif //CURS9ABC_MESAJ_H
