#ifndef _array_list_
#define _array_list_
#include <iostream>
#include "list.h"
#include "changeArrayLenth.h"
#include<iterator>
using namespace std;
template <typename T>
class arrayList : public list<T>
{
public:
    //constructor构造函数
    arrayList(int initialCapacity = 10)
    {
        if (initialCapacity < 1)
            throw "initialCapacity<1";
        element = new T[initialCapacity];
        listSize = 0;
        arrayLength = initialCapacity;
    }
    arrayList(const arrayList<T> &);
    ~arrayList() { delete[] element; }

    //function成员函数
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T &get(int theIndex) const;
    int indexOf(const T &theElement) const;
    void erase(int theIndex);
    void insertBefore(int theIndex, const T &theElement);
    void output(ostream &out) const;
    void pushBack(const T &theElement);

private:
    T *element;
    int listSize;
    int arrayLength;
};

template <typename T>
arrayList<T>::arrayList(const arrayList<T> &theArrayList)
{
    //拷贝构造函数
    listSize = theArrayList.listSize;
    arrayLength = theArrayList.arrayLength;
    delete[] element;
    element = new T[arrayLength];
    copy(theArrayList.element, theArrayList.element + listSize, element);
}

template <typename T>
T &arrayList<T>::get(int theIndex) const
{
    if (theIndex < 0)
        throw "theIndex<0";
    return element[theIndex];
}

template <typename T>
int arrayList<T>::indexOf(const T &theElement) const
{
    int i = 0;
    for (; i <= listSize; i++)
    {
        if (element[i] == theElement)
            return i;
    }

    return -1;
}

template <typename T>
void arrayList<T>::insertBefore(int theIndex, const T &theElement)
{
    if (theIndex < 0 || theIndex > listSize)
        throw "inserttheIndex <0 or theIndex>listSize";

    if (listSize == arrayLength)
    {
        changeArrayLenth(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }

    copy_backward(element+theIndex, element+listSize,element+listSize+1);
    element[theIndex]=theElement;
    listSize++;
}

template <typename T>
void arrayList<T>::erase(int theIndex)
{
    if (theIndex < 0 || theIndex > listSize)
        throw "delete theIndex <0 or theIndex>listSize";
    copy(element+theIndex+1,element+listSize,element+theIndex);
    listSize--;
}
template <typename T>
void arrayList<T>::output(ostream& os)const
{ 
    copy(element,element+listSize,ostream_iterator<T>(cout," "));
}

template <typename T>
ostream& operator<<(ostream os,const arrayList<T>& x)
{
    x.output(os);
    return out;
}
template <typename T>
void arrayList<T>::pushBack(const T&theElement)
{
    if(listSize==arrayLength)
    {
        changeArrayLenth(element,arrayLength,2*arrayLength);

        arrayLength*=2;
     
    }
    element[++listSize]=theElement;
}
#endif