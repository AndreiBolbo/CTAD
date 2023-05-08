//
// Created by MSI on 14/05/2022.
//
#include "time.h"
#include "mesaj.h"
Mesaj::Mesaj()
{
    id_1=id_2=0;
    ttime = time(0);
}

string Mesaj::get_text() {
    return text;
}
Mesaj::Mesaj(int id1, int id2, string text, time_t ttime) {
    this->id_1 = id1;
    this->id_2 = id2;
    this->text = text;
    this->ttime = ttime;
}

time_t Mesaj::get_time() {
    return ttime;
}

Mesaj &Mesaj::operator=(const Mesaj &m) {
    id_1=m.id_1;
    id_2 = m.id_2;
    text = m.text;
    ttime = m.ttime;
}

bool Mesaj::operator<(const Mesaj &m) {
    if(difftime(ttime,m.ttime)<0)
        return true;
    return false;
}

int Mesaj::get_id1() {
    return id_1;
}

int Mesaj::get_id2() {
    return id_2;
}

bool Mesaj::operator==(const Mesaj &m) {
    return (text==m.text && id_1==m.id_1 && id_2 == m.id_2);
}
bool Mesaj::operator>(const Mesaj &m) {
    if(difftime(ttime,m.ttime)>0)
        return true;
    return false;
}
