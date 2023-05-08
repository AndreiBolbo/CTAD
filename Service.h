//
// Created by MSI on 23/05/2022.
//

#ifndef CURS9ABC_SERVICE_H
#define CURS9ABC_SERVICE_H

#include "Repo.h"
class Service {
private:
    Repo repository;
public:

    Service(Repo &r);
    ~Service() = default;
    Service(const Service &s);
    bool read_user_by_id(int id);
    User show_user_by_id(int id);
    void add_user(int id, char *nume, char *oras, int varsta);
    void del_user(int id, char *nume, char *oras, int varsta);
    void update_user(int id, char *nume, char *oras, int varsta);
    void add_event(int id, string details);
    void del_event(int id);
    //void update_event(int id,string details);
    void add_friend(int id1,int id2);
    void del_friend(int id1,int id2);
    void add_mesage(int id1,int id2, string text, time_t tt);
    void del_mesage(int id1,int id2, string text, time_t tt);
    Vector<User> get_all_users();
    Vector<Friend> get_all_friends();
    Vector<Event> get_all_events();
    vector<Mesaj> get_all_mesaje();
    Mesaj read_mesage_by_id(int id1,int id2,string text);
    void add_participant_by_id(int id, User &u);
    void add_interested_by_id(int id, User &u);
    void add_maybe_by_id(int id, User &u);
};


#endif //CURS9ABC_SERVICE_H
