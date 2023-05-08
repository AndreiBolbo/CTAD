//
// Created by MSI on 10/05/2022.
//

#ifndef CURS9ABC_FRIEND_H
#define CURS9ABC_FRIEND_H


class Friend {
    int id1;
    int id2;
public:
    Friend();
    Friend(int id1,int id2);
    Friend(const Friend &f);
    Friend& operator = (const Friend &f);
    bool operator==(const Friend &f);
    int get_id1();
    int get_id2();
};


#endif //CURS9ABC_FRIEND_H
