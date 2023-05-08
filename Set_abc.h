//
// Created by MSI on 22/05/2022.
//

#ifndef CURS9ABC_SET_ABC_H
#define CURS9ABC_SET_ABC_H
#include "ABC.h"
#include "vector.h"
template<class T>
class Set_abc {
private:
    ABC<T> elemente;
   // vector<T> elemente_ordonate;
public:
    Set_abc() = default;
    ~Set_abc() =  default;
    Set_abc(const Set_abc<T> & set)
    {
        elemente = set.elemente;
    }

    bool exist(T elem)
    {
        ///verifica daca T elem exista
        return elemente.search(elem);
    }
    void insert(T elem)
    {
        ///adauga elem
        if(exist(elem)==0)
        {
            elemente.add(elem);
        }

    }
    void remove(T elem)
    {
        ///sterge elem din set
        elemente.del(elem);
    }
    int size()
    {
        ///returneaza lungimea Set-ului
        vector<T>elements = elemente.get_all();
        return elements.size();
    }
    vector<T> get_all()
    {
        ///returneaza toate elementele multimii
        return elemente.get_all();
    }
    Set_abc& operator=(const Set_abc<T> &set) = default;

};

#endif //CURS9ABC_SET_ABC_H
