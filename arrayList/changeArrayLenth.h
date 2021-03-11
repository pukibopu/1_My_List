#ifndef _change_array_lenth_
#define _change_array_lenth_
#include <iostream>
#include <exception>
#include <algorithm>
using namespace std;

template <typename T>
void changeArrayLenth(T *&a, int oldLenth, int newLenth)
{
    if (newLenth < 0)
    {
        throw "newLenth<0";//throw the exception
    }
    T *temp = new T[newLenth];//new memory
    int num = max(oldLenth, newLenth);

    copy(a, a + num, temp);//move the array

    delete[] a;//delete the original array

    a = temp;
}
#endif