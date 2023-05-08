#ifndef PROIECTSDA_USER_H
#define PROIECTSDA_USER_H
#include<cstring>
#include <string>
#include <ostream>

using namespace std;
class User {
private:
    int id;
    char* nume;
    char* oras;
    int varsta;
public:
    User();
    User(int, const char*, const char*, int);
    User(const User&);

    char *getNume() const;

    char *getOras() const;

    bool operator==(const User &rhs) ;

    User& operator=(const User& rhs);

    bool operator<(const User &rhs) const;

    bool operator>(const User &rhs) const;

    bool operator<=(const User &rhs) const;

    bool operator>=(const User &rhs) const;

    friend ostream &operator<<(ostream &os, const User &user);

    int getVarsta() const;
    int get_id() const;
};

#endif //PROIECTSDA_USER_H
