#include <iostream>

using namespace std;
#define minimo(a,b) (a < b) ? a : b

template <typename T>
 T mini(const T a, const T b){
    if(a < b)
        return a;
    else{
     return b;
    }
 }

int main()
{
    int a;
    a = minimo(4,6.4);
    cout << a << endl;
    //Rectangle *rect;

    //Triangle *rep;
    //rep = rect;

    return 0;
}
