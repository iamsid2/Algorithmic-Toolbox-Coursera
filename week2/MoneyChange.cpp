#include<iostream>
using namespace std;

int MoneyChange (int m)
{
    int cnt;
    if(m<5)
        cnt=m;
    else if(m<10 && m>=5)
           cnt=(m-5)+1;
    else
    {
     int a,b,c;
     a=m/10;
     int t=m-(a*10);
     b=t/5;
     c=t%5;
     cnt=a+b+c;
    }
    return cnt;
}

int main()
{
    int m;
    cin>>m;
    cout<<MoneyChange(m);
}
