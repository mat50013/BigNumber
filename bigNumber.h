#ifndef BIGNUMBER_H_INCLUDED
#define BIGNUMBER_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

struct BigNumber
{
private:
    int Xmax(int a, int b)
    {
        if(a >= b)
            return a;
        else return b;
    }

    BigNumber addSum(BigNumber nr1, int nr2[10000])
    {
        BigNumber sum;
        int maxx = Xmax(nr1.data[0], nr2[0]);
        int t = 0;
        for(int i = 1; i <= maxx; ++i)
        {
            sum.data[i] = nr1.data[i] + nr2[i] + t;
            t = sum.data[i] / 10;
            sum.data[i] %= 10;
        }

        sum.data[0] = maxx;
        if(t)
            sum.data[++sum.data[0]] = t;
        return sum;
    }

    BigNumber dif(BigNumber nr1, int nr2[10000]){
        BigNumber aux = nr1;
        for(int i = 1; i <= nr1.data[0]; ++i)
            nr1.data[i] = 0;
        for(int i = 1; i <= nr2[0]; ++i)
            nr1.data[i] = nr2[i];
        nr1.data[0] = nr2[0];
        for(int i = 1; i <= nr2[0]; ++i)
            nr2[i] = 0;
        for(int i = 1; i <= aux.data[0]; ++i)
            nr2[i] = aux.data[i];
        nr2[0] = aux.data[0];

        int t = 0;
        for(int i = 1; i <= nr1.data[0]; ++i)
            nr1.data[i] += (t = (nr1.data[i] -= nr2[i] + t) < 0) ? 10 : 0;

        while(!nr1.data[nr1.data[0]])
            nr1.data[0]--;
        return nr1;
    }
    BigNumber inmultire(BigNumber a, BigNumber b){
        BigNumber rez;
        rez.data[0] = a.data[0] + b.data[0] - 1;
        for(int i = 1; i <= a.data[0] + b.data[0]; ++i)
            rez.data[i] = 0;
        for(int i = 1; i <= a.data[0]; ++i)
            for(int j = 1; j <= b.data[0]; ++j)
                rez.data[i + j - 1] += a.data[i] * b.data[j];
        int t = 0;
        for(int i = 1; i <= rez.data[0]; ++i)
        {
            t = (rez.data[i] += t) / 10;
            rez.data[i] %= 10;
        }
        if(t)
            rez.data[++rez.data[0]] = t;

        return rez;
    }
    BigNumber divide(int a[10005], long long b){
        int r = 0;
        for(int i = a[0]; i >= 1; --i){
            a[i] = (r = 10 * r + a[i]) / b;
            r %= b;
        }
        while(!a[a[0]] && a[0] > 1)
            a[0]--;

        BigNumber rez;

        for(int i = 1; i <= a[0]; ++i)
            rez.data[i] = a[i];
        rez.data[0] = a[0];

        return rez;
    }

public:
    int data[10000];
    BigNumber operator+(const BigNumber& a)
    {
        BigNumber rez = addSum(a, this->data);
        return rez;
    }
    BigNumber operator-(const BigNumber& a){
        BigNumber rez;
        rez = dif(a, this->data);
        return rez;
    }
    BigNumber& operator=(int a){
        while(a){
            data[++data[0]] = a % 10;
            a /= 10;
        }
        return *this;
    }
    BigNumber& operator=(long long a){
        while(a){
            data[++data[0]] = a % 10;
            a /= 10;
        }
        return *this;
    }
    BigNumber operator^(long long a){
        BigNumber rez;
        for(int i = 1; i <= this->data[0]; ++i)
            rez.data[i] = this->data[i];
        rez.data[0] = this->data[0];

        BigNumber copie = rez;
        for(int i = 2; i <= a; ++i)
            rez = inmultire(rez, copie);
        return rez;
    }
    BigNumber operator/(long long a){
        BigNumber rez = divide(this->data, a);
        return rez;
    }
};


void read(BigNumber &x)
{
    char c[10005];
    cin >> c;

    int lg = strlen(c);

    int pas = 0;
    for(int i = lg - 1; i >= 0; --i)
        x.data[++pas] = c[i] - '0';
    x.data[0] = lg;
}

void print(BigNumber x){
    for(int i = x.data[0]; i >= 1; --i)
        cout << x.data[i];
}

#endif
