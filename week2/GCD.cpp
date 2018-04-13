#include<iostream>
using namespace std;

int GCD(int a,int b)
{
   int divisor,divident;
   divisor = a>=b ? a:b;
   divident = a<b ? a:b;
   while(divident !=0)
    {
        int remainder = divisor % divident;
        divisor = divident;
        divident = remainder;
    }
        return divisor;
}

int main()
{
    int a,b,c;
    cin>>a>>b;
    c=GCD(a,b);
    cout<<c;
    return 0;
}
