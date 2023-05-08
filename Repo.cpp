//
// Created by MSI on 21/05/2022.
//

#include "Repo.h"
Repo::Repo(const Repo &r) {
    this->friends= r.friends;
    this->events = r.events;
    this->mesaje = r.mesaje;
    this->users = r.users;
}
Repo::Repo(Vector<User> users, Set_abc<Mesaj> mesaje, Vector<Friend> friends, Vector<Event> events) {
    this->users = users;
    this->mesaje = mesaje;
    this->events = events;
    this->friends = friends;
}

Repo &Repo::operator=(const Repo &r) {
    if(this != &r)
    {
        this->friends= r.friends;
        this->events = r.events;
        this->mesaje = r.mesaje;
        this->users = r.users;
        return *this;
    }

}

void Repo::add_event(Event &e) {
    for(int i=0;i<events.size();i++)
        if(events[i].get_id()==e.get_id())
            throw(invalid_argument("exista deja evenimentul"));
    events.push_back(e);

}

void Repo::add_friend(Friend &f) {


    int ok=0;
    for(int i=0;i<users.size();i++)
    {

        if(users[i].get_id() == f.get_id1())
            ok++;
        else if(users[i].get_id()== f.get_id2())
            ok++;
    }
    for(int i=0;i<friends.size();i++)
    {
        if(friends[i] == f)
           throw invalid_argument("exista deja prietenia");
    }
    if(ok==2)
        friends.push_back(f);
    else
        throw invalid_argument("nu exista ambii useri");

}
void Repo::add_user(User &u) {
    for(int i=0;i<users.size();i++)
    {
        if(users[i] == u or users[i].get_id()== u.get_id())
           throw invalid_argument("exista deja userul");
    }
    users.push_back(u);
}

void Repo::add_mesaj(Mesaj &m) {


    int ok=0;
    for(auto & user : users)
    {
        if(user.get_id() == m.get_id1())
            ok++;
        else if(user.get_id()== m.get_id2())
            ok++;
    }

    if(ok==2)
        mesaje.insert(m);
    else
        throw invalid_argument("nu exista ambii useri");
}

void Repo::del_user(User &u) {
    /**sterge user-ul u daca se afla in vector;
     *
     */
    for(int i=0;i<users.size();i++)
    {
        if(users[i] == u)
            users.erase(i);
    }
}

void Repo::del_mesaj(Mesaj &m) {
    if(mesaje.exist(m))
        mesaje.remove(m);
}

void Repo::del_event(Event &e) {
    for(int i=0;i<events.size();i++)
    {
        if(events[i] == e)
            events.erase(i);
    }

}

void Repo::del_friend(Friend &f) {
    for(int i=0;i<friends.size();i++)
    {
        if(friends[i] == f)
            friends.erase(i);
    }
}

Vector<User> Repo::get_all_users() {
    return users;
}

Vector<Event> Repo::get_all_events() {
    return  events;
}

Vector<Friend> Repo::get_all_friends() {
    return friends;
}

vector<Mesaj> Repo::get_all_mesaje() {
    return mesaje.get_all();
}

void Repo::update_event(Event &e) {
    for(int i=0;i<events.size();i++)
    {
        if(events[i] == e)
            events[i]= e;
    }
}

void Repo::update_user(User &u) {
    for(int i=0;i<users.size();i++)
    {
        if(users[i].get_id() == u.get_id())
            users[i] = u;
    }
}