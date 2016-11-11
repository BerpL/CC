#ifndef STACK_H
#define STACK_H
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    vector<T> v;
    friend Stack<T> operator+(const Stack<T> &x, const Stack<T> &y);
public:
    bool Empty() const;
    void Push(const T &v1);
    T Pop();
    T Top();
    void printStack();
};

template <class T>
Stack<T> operator+(const Stack<T> &x, const Stack<T> &y)
{
    Stack<T> res = x;
    for (int i = 0;i< x.v.size(); i++)
        res.v.push_back(y.v[i]);
    return res;
}

template <class T>
bool Stack<T>::Empty() const
{
    return v.empty();
}

template <class T>
void Stack<T>::Push(const T &v1)
{
    return v.push_back(v1);
}

template <class T>
T Stack<T>::Pop()
{
    return v.pop_back();
}

template <class T>
T Stack<T>::Top()
{
    return v.back();
}

template <class T>
void Stack<T>::printStack()
{
    for(int i=0; i < v.size(); i++)
        cout << v[i] << endl;
}

#endif // STACK_H
