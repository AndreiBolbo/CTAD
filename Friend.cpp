//
// Created by MSI on 10/05/2022.
//

#include "Friend.h"
Friend::Friend(const Friend &f) {
    id1 =f.id1;
    id2 = f.id2;
}
Friend::Friend(int id1, int id2) {
    this->id1 = id1;
    this->id2 = id2;
}
Friend::Friend() {
    id1 = 0;
    id2 = 0;

}

int Friend::get_id1() {
    return id1;
}

int Friend::get_id2() {
    return id2;
}
Friend &Friend::operator=(const Friend &f) {
    id1 = f.id1;
    id2 = f.id2;
}

bool Friend::operator==(const Friend &f) {
    return (id1==f.id1 && id2==f.id2);
}