#include<iostream>
using namespace std;

int FibonacciNaive(int n)
{
    if(n<=1)
        return n;
    else{
    int f1=0,f2=1,f;
        for(int i=2;i<=n;i++)
          {
            f=f1+f2;
            f1=f2;
            f2=f;
        }
        return f;
}
}

int main()
{
    int n,lf;
    cin>>n;
    lf= FibonacciNaive(n);
    cout<<lf;
    return 0;
}
