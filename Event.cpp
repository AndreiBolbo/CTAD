//
// Created by MSI on 22/05/2022.
//

#include "Event.h"
Event::Event()= default;
Event::Event(int id,string details, Vector<User> particpants, Vector<User> interested, Vector<User> maybe) {
    this->details = details;
    this->id = id;
    this->participants = particpants;
    this->interested = interested;
    this->maybe = maybe;
}
Event::Event(const Event &e) {
    this->id = e.id;
    this->details = e.details;
    this->participants = e.participants;
    this->interested = e.interested;
    this->maybe = e.maybe;
}

void Event::set_id(int id) {
    this->id = id;
}
Event &Event::operator=(const Event &e) = default;

string Event::get_details() {
    return details;
}

Vector<User> Event::get_participants() {
    return participants;
}

Vector<User> Event::get_interested() {
    return interested;
}

Vector<User> Event::get_maybe() {
    return maybe;
}

void Event::add_interested(const User &user) {
    interested.push_back(user);
}

void Event::add_participant(const User &user) {
    participants.push_back(user);
}

void Event::add_maybe(const User &user) {
    maybe.push_back(user);
}

int Event::get_id() {
    return id;
}

bool Event::operator==(const Event &e) {

    return(this->details == e.details);
}