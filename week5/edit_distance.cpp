#include <iostream>
#include <string>

using namespace std;
int editDistance(string s1,string s2)
{
    int D[101][101];
    int a = s1.size();
    int b = s2.size();
    for(int i=0;i <= b;i++)
    {
        D[0][i] = i;
    }
    for(int i=0;i <= a;i++)
    {
        D[i][0] = i;
    }

    for(int i=1;i<=a;i++)
    {
        for(int j=1;j<=b;j++){
            if(s1[i-1] == s2[j-1])
                D[i][j] = D[i-1][j-1];
            else
                D[i][j] = 1 + min( D[i][j-1] , min(D[i-1][j] , D[i-1][j-1]));
        }
    }
    return D[a][b];
}
int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<editDistance(s1,s2)<<endl;
    return 0;
}
