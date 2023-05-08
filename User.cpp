#include "User.h"

User::User() {
    this->id = 0;
    this->varsta = 0;
    this->nume = nullptr;
    this->oras = nullptr;
}

int User::get_id() const {
    return id;
}
User::User(int id, const char* nume, const char* oras, int varsta) {
    this->id = id;
    this->nume = new char[strlen(nume) + 1];
    strcpy(this->nume, nume);
    this->oras = new char[strlen(oras) +1];
    strcpy(this->oras, oras);
    this->varsta = varsta;
}
User::User(const User &rhs) {
    this->id = rhs.id;
    this->nume = new char[strlen(rhs.nume) + 1];
    strcpy(this->nume, rhs.nume);
    this->oras = new char[strlen(rhs.oras) + 1];
    strcpy(this->oras, rhs.oras);
    this->varsta = rhs.varsta;
}

bool User::operator==(const User &rhs)  {
    return strcmp(this->nume, rhs.nume) == 0 &&
           strcmp(this->oras, rhs.oras) == 0 &&
           this->varsta == rhs.varsta;
}

User& User::operator=(const User &rhs) {
    if(this != &rhs) {
        this->nume = new char[strlen(rhs.nume) + 1];
        strcpy(this->nume, rhs.nume);
        this->oras = new char[strlen(rhs.oras) + 1];
        strcpy(this->oras, rhs.oras);
        this->varsta = rhs.varsta;
        this->id = rhs.id;
        return *this;
    }
}

bool User::operator<(const User &rhs) const {
    return this->varsta < rhs.varsta;
}

bool User::operator>(const User &rhs) const {
    if(this!= nullptr)
    return this->varsta > rhs.varsta;
}

ostream &operator<<(ostream &os, const User &user) {
    os <<" id: "<<user.id<< " nume: " << user.nume << " oras: " << user.oras << " varsta: " << user.varsta;
    return os;
}

char *User::getNume() const {
    return nume;
}

char *User::getOras() const {
    return oras;
}

int User::getVarsta() const {
    return varsta;
}
