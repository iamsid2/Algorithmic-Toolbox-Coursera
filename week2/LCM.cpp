#include<iostream>
using namespace std;
int GCD(int a,int b)
{
    int divident = a<=b?a:b;
    int divisor  = a>=b?a:b;

    while(divident!=0)
    {
        int remainder = divisor%divident;
        divisor=divident;
        divident=remainder;
    }
    return divisor;

}


int main()
{
    long long a,b;
    cin>>a>>b;
    long long lcm=(a*b)/GCD(a,b);
    cout<<lcm;

}
