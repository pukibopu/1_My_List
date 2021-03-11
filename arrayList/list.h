#ifndef _ADT_LiST_
#define _ADT_LiST_
#include <iostream>

using namespace std;

template <typename T>
class list
{
public:
    
    ~list() {}

    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual T &get(int theIndex) const = 0;
    virtual int indexOf(const T &theElement) const = 0;
    virtual void erase(int theIndex) = 0;
    virtual void insertBefore(int theIndex, const T &theElement) = 0;
    virtual void output(ostream &out) const = 0;
};

#endif