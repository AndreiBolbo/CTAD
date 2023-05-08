//
// Created by MSI on 23/05/2022.
//

#ifndef CURS9ABC_UI_H
#define CURS9ABC_UI_H

#include "Service.h"
class UI {
private:
    Service &s;
public:
    UI(Service &s);
    ~UI()= default;
    void run_menu();
    void displayMenu_1();
    void show_users();
    void show_friends(int id_1);
    void show_mesages(int id_1, int id_2);
    void add_user(int id, char *nume, char *oras, int varsta);
    void del_user(int id, char *nume, char *oras, int varsta);
    void update_user(int id, char *nume, char *oras, int varsta);
    void add_event(int id, string details);
    void add_friend(int id1,int id2);
    void del_friend(int id1,int id2);
    void add_mesage(int id1,int id2, string text, time_t tt);
    void del_mesage(int id1,int id2, string text, time_t tt);
    void show_events();
};


#endif //CURS9ABC_UI_H
