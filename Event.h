//
// Created by MSI on 22/05/2022.
//

#ifndef CURS9ABC_EVENT_H
#define CURS9ABC_EVENT_H

#include "sstream"
#include "vector.h"
#include "User.h"
using namespace std;
class Event {
private:
    int id;
    string details;
    Vector<User> participants;
    Vector<User> interested;
    Vector<User> maybe;
public:
    Event();
    Event(int id,string details, Vector<User> particpants, Vector<User> interested,Vector<User> maybe);
    Event(const Event &e);
    ~Event()= default;
    Event& operator= (const Event &e);
    string get_details();
    Vector<User> get_participants();
    Vector<User> get_interested();
    Vector<User> get_maybe();
    void add_participant(const User &user);
    void add_interested(const User &user);
    void add_maybe(const User &user);
    int get_id();
    void set_id(int id);
    bool operator==(const Event &e);
};


#endif //CURS9ABC_EVENT_H
