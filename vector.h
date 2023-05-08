//
// Created by MSI on 30/04/2022.
//

#ifndef CURS9ABC_VECTOR_H
#define CURS9ABC_VECTOR_H
#define INITIAL_CAPACITY 4
#include <string>
#include <iostream>
#include <exception>

using namespace std;
template<typename elementType>
class IteratorVector;

template<typename elementType>
class Vector
{
private:
    int length;
    int capacity;
    elementType* elements;
    void ensureSize();
public:
    Vector() noexcept;
    Vector(const Vector& otherVector);
    Vector<elementType>& operator=(const Vector<elementType>&);
    int size() const noexcept;
    void push_back(const elementType& element);
    ~Vector() { if (this->elements != nullptr) { delete[] this->elements; } }
    void erase(int indexToDelete);
    elementType& at(int indexInList) const;

    elementType& operator [](int index);

    void setValueAtIndex(const elementType&, int );

    friend class IteratorVector<elementType>;
    //functiile care creaza iteratori
    IteratorVector<elementType> begin() noexcept;
    IteratorVector<elementType> end() noexcept;
};

template<typename elementType>
inline Vector<elementType>& Vector<elementType>::operator=(const Vector<elementType>& otherVector)
{
    ///operatorul de atribuire
    this->capacity = otherVector.capacity;
    this->length = otherVector.length;
    this->elements = new elementType[capacity];
    //copy the elements into the new vector, not the reference to the vector
    for (int i = 0; i < otherVector.length; i++)
        this->elements[i] = otherVector.elements[i];
    return *this;
}

template<typename elementType>
inline elementType& Vector<elementType>::operator[](int index)
{
    return this->at(index);
}

template<typename elementType>
Vector<elementType>::Vector(const Vector& otherVector)
{

    //copy constructor
    this->capacity = otherVector.capacity;
    this->length = otherVector.length;
    this->elements = new elementType[capacity];
    //copy the elements into the new vector, not the reference to the vector
    for (int i = 0; i < otherVector.length; i++)
        this->elements[i] = otherVector.elements[i];
}

template<typename elementType>
inline Vector<elementType>::Vector() noexcept
{
    ///constructorul implicit/fara parametri
    this->length = 0;
    this->capacity = INITIAL_CAPACITY;
    this->elements = new elementType[INITIAL_CAPACITY];
}


template<typename elementType>
void Vector<elementType>::ensureSize()
{
    ///modifica capacitatea vectorului (resize)
    if (this->length == this->capacity)
    {
        //resize
        this->capacity *= 2;
        elementType *newArray = new elementType[this->capacity];
        //copiem elementele in noul array
        for (int indexInList = 0; indexInList < this->length; indexInList++)
            newArray[indexInList] = this->elements[indexInList];

        elementType* oldArray = this->elements;
        this->elements = newArray;
        if(oldArray!=nullptr)
            delete[] oldArray;
    }
    else if (this->length == this->capacity / 4)
    {
        //resize capacitate la jumatate
        this->capacity /= 2;
        elementType* newArray = new elementType[this->capacity];
        //copiem elementele in noul array
        for (int indexInList = 0; indexInList < this->length; indexInList++)
            newArray[indexInList] = this->elements[indexInList];

        elementType* oldArray = this->elements;
        this->elements = newArray;
        if(oldArray!=nullptr)
            delete[] oldArray;
    }
}

template<typename elementType>
int Vector<elementType>::size() const noexcept
{
    ///returneaza lungimea vectorului
    return this->length;
}

template<typename elementType>
void Vector<elementType>::push_back(const elementType& element)
{
    ///adauga element in vector
    ensureSize();
    this->elements[this->length] = element;
    this->length++;
}

template<typename elementType>
inline void Vector<elementType>::erase(int indexToDelete)
{
    ///sterge elementul de po pozitia indexToDelete din vector;
    if (indexToDelete >= this->length)
        throw invalid_argument("Index out of range");
    for (int indexInList = indexToDelete; indexInList < this->length-1; indexInList++)
    {
        this->elements[indexInList] = this->elements[indexInList + 1];
    }
    this->length--;
}

template<typename elementType>
inline elementType& Vector<elementType>::at(int indexInList) const
{
    ///returneaza elementul de pe pozitia IndexInList
    if (indexInList >= this->length)
        throw invalid_argument("Index out of range");
    return this->elements[indexInList];
}


template<typename elementType>
inline void Vector<elementType>::setValueAtIndex(const elementType& element, int index)
{
    this->elements[index] = element;
}


template<typename elementType>
IteratorVector<elementType> Vector<elementType>::begin() noexcept
{
    ///returneaza un obiect de tip iterator pentru vectorul curent
    return IteratorVector<elementType> (*this);
}

template<typename elementType>
IteratorVector<elementType> Vector<elementType>::end() noexcept
{
    ///returneaza un obiect de tip iterator pentru vectorul curent si lungimea sa
    return IteratorVector<elementType>(*this, length);
}

//de aici incepe iteratorul


template<typename elementType>
class IteratorVector
{
private:
    const Vector<elementType>& vectorReference;
    int pozition;
public:
    IteratorVector(const Vector<elementType>& vector) noexcept;
    IteratorVector(const Vector<elementType>& vector, const int pozition) noexcept;
    IteratorVector<elementType>& operator=(const IteratorVector<elementType>&) = default;
    void next();
    bool valid() const noexcept;
    elementType& element() const;
    IteratorVector& operator++();
    bool operator==(const IteratorVector& other) const noexcept;
    bool operator!=(const IteratorVector& other) const noexcept;
    elementType& operator*();
};

template<typename elementType>
IteratorVector<elementType>::IteratorVector(const Vector<elementType>& vector) noexcept:vectorReference{vector}, pozition{0} {}

template<typename elementType>
IteratorVector<elementType>::IteratorVector(const Vector<elementType>& vector, const int pozition) noexcept: vectorReference{vector}, pozition{pozition}{}

template<typename elementType>
bool IteratorVector<elementType>::valid() const noexcept
{
    ///verifica daca pozitia este valida
    return pozition < vectorReference.length;
}

template<typename elementType>
void IteratorVector<elementType>::next()
{
    if (valid())
        pozition++;
    else
        throw invalid_argument("Invalid iterator!\n");
}

template<typename elementType>
elementType& IteratorVector<elementType>::element() const
{
    if(valid())
        return vectorReference.at(pozition);
    throw invalid_argument("Invalid iterator!");
}

template<typename elementType>
IteratorVector<elementType>& IteratorVector<elementType>::operator++()
{
    next();
    return (*this);
}

template<typename elementType>
bool IteratorVector<elementType>::operator==(const IteratorVector& other) const noexcept
{
    return pozition == other.pozition;
}

template<typename elementType>
bool IteratorVector<elementType>::operator!=(const IteratorVector& other) const noexcept
{
    return !(*this == other);
}

template<typename elementType>//
inline elementType& IteratorVector<elementType>::operator*()
{
    return element();

}



#endif //CURS9ABC_VECTOR_H
