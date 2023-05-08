//
// Created by MSI on 21/05/2022.
//

#ifndef CURS9ABC_REPO_H
#define CURS9ABC_REPO_H
#include "ABC.h"
#include "vector.h"
#include "User.h"
#include "mesaj.h"
#include "Friend.h"
#include "Event.h"
#include "Set_abc.h"
class Repo {
private:
    Vector<User> users;
    Set_abc<Mesaj> mesaje;
    Vector<Friend> friends;
    Vector<Event> events;
public:
    ~Repo() = default;
    Repo() = default;
    Repo(Vector<User> users, Set_abc<Mesaj> mesaje,Vector<Friend> friends, Vector<Event> events);
    Repo(const Repo &r);
    Repo& operator=(const Repo &r);
    void add_user(User &u);
    void add_mesaj(Mesaj &m);
    void add_friend(Friend &f);
    void add_event(Event &e);
    void del_user(User &u);
    void del_mesaj(Mesaj &m);
    void del_friend(Friend &f);
    void del_event(Event &e);
    Vector<User> get_all_users();
    Vector<Friend> get_all_friends();
    Vector<Event> get_all_events();
    vector<Mesaj> get_all_mesaje();
    void update_user(User &u);
    void update_event(Event &e);

};


#endif //CURS9ABC_REPO_H
