#include <iostream>
#include <Stack.h>


using namespace std;

int main()
{
    Stack<int> x1;
    Stack<int> x2;

    x1.Push(1);
    x1.Push(2);
    x2.Push(3);
    x2.Push(4);
    Stack<int> x3 = x1+x2;
    x1.printStack();
    x2.printStack();
    x3.printStack();
}
