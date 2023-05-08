//
// Created by MSI on 23/05/2022.
//

#include "Service.h"

#include <utility>
Service::Service(Repo &r) {
    repository = r;
}
Service::Service(const Service &s) {
    repository = s.repository;
}

void Service::add_user(int id, char *nume, char *oras, int varsta) {
    User u(id,nume,oras, varsta);
    repository.add_user(u);
}

void Service::update_user(int id, char *nume, char *oras, int varsta) {
    User u(id,nume,oras, varsta);
    repository.update_user(u);
}

void Service::del_user(int id, char *nume, char *oras, int varsta) {
    User u(id,nume,oras, varsta);
    repository.del_user(u);
    Vector<Friend> f = repository.get_all_friends();
    for(int i=0;i<f.size();i++)
        if(f[i].get_id1()==id or f[i].get_id2()==id)
            repository.del_friend(f[i]);
    vector<Mesaj> me = repository.get_all_mesaje();
    for(int i=0;i<me.size();i++)
        if(me[i].get_id1()==id or me[i].get_id2()==id)
            repository.del_mesaj(me[i]);

}

void Service::del_friend(int id1, int id2) {
    Friend f(id1,id2);
    repository.del_friend(f);
}

void Service::add_event(int id, string details) {
    Vector<User> particpants;
    Vector<User> maybe;
    Vector<User> interested;
    Event e(id,std::move(details),particpants,interested,maybe);
    repository.add_event(e);
}

void Service::del_event(int id) {
    Event e;
    e.set_id(id);
    repository.del_event(e);


}

void Service::add_friend(int id1, int id2) {
    Friend f(id1,id2);
    repository.add_friend(f);
}

void Service::add_mesage(int id1, int id2, string text, time_t tt) {
    Mesaj m(id1,id2,text,tt);
    repository.add_mesaj(m);
}

void Service::del_mesage(int id1, int id2, string text, time_t tt) {
    Mesaj m(id1,id2,text,tt);
    repository.del_mesaj(m);
}

Vector<Event> Service::get_all_events() {
    return  repository.get_all_events();
}

vector<Mesaj> Service::get_all_mesaje() {
    return repository.get_all_mesaje();
}

Vector<Friend> Service::get_all_friends() {
    return repository.get_all_friends();

}


bool Service::read_user_by_id(int id) {
    Vector<User> users = repository.get_all_users();
    for(int i=0;i<users.size();i++)
        if(users[i].get_id() == id)
            return true;
    return false;
}

User Service::show_user_by_id(int id) {
    Vector<User> users = repository.get_all_users();
    for(int i=0;i<users.size();i++)
        if(users[i].get_id() == id)
            return users[i];
}

void Service::add_participant_by_id(int id, User &u) {
    Vector<Event> events = get_all_events();
    for(int i=0;i<events.size();i++)
        if(events[i].get_id() ==id)
            events[i].add_participant(u);
}

void Service::add_interested_by_id(int id, User &u) {
    Vector<Event> events = get_all_events();
    for(int i=0;i<events.size();i++)
        if(events[i].get_id() ==id)
            events[i].add_interested(u);
}

void Service::add_maybe_by_id(int id, User &u) {
    Vector<Event> events = get_all_events();
    for(int i=0;i<events.size();i++)
        if(events[i].get_id() ==id)
            events[i].add_maybe(u);
}
Mesaj Service::read_mesage_by_id(int id1, int id2, string text) {
    vector<Mesaj> mesaje = repository.get_all_mesaje();

    for(int i=0;i<mesaje.size();i++)
        if(mesaje[i].get_id1() == id1 &&mesaje[i].get_id2()==id2 && mesaje[i].get_text()==text)
            return mesaje[i];
}
Vector<User> Service::get_all_users() {
    return repository.get_all_users();
}