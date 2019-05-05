#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <stdexcept>
#include "lsl.h"

using namespace std;
template<typename T>
class Cola
{
public:
    Cola(){}
    ~Cola(){lista.clear();}
    bool empty() const;
    size_t size() const;
    const T& front() const;
    const T& back();
    void push(const T& elem);
    void pop();
    void popBack();
private:
    LSL<T> lista;
};
#endif // COLA_H

template<typename T>
bool Cola<T>::empty() const
{
    return lista.empty();
}

template<typename T>
size_t Cola<T>::size() const
{
    return lista.size();
}

template<typename T>
const T &Cola<T>::front() const
{
    if(empty())
        throw invalid_argument("front() on empty queue");
    return lista.fornt();
}

template<typename T>
const T &Cola<T>::back()
{
     if(empty())
         throw invalid_argument("back() on empty queue");
     return lista.back();
}

template<typename T>
void Cola<T>::push(const T &elem)
{
    lista.push_back(elem);
}

template<typename T>
void Cola<T>::pop()
{
    lista.pop_front();
}

template<typename T>
void Cola<T>::popBack()
{
    lista.pop_back();
}
