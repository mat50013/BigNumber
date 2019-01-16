#include <iostream>
#include <bigNumber.h>

using namespace std;

BigNumber a, b, Div, Sum, dif, power;

int main(){
    a.setSize(10000);
    b.setSize(10000);
    Div.setSize(10000);
    Sum.setSize(10000);
    dif.setSize(10000);
    power.setSize(10000);
    read(a);
    read(b);
    Div = a / 4;
    Sum = a + b;
    if(a > b)
        dif = a - b;
    power = a ^ 10;
    print(Div);
    cout << '\n';
    print(Sum);
    cout << '\n';
    print(dif);
    cout << '\n';
    print(power);
    cout << '\n';
	return 0;
}

