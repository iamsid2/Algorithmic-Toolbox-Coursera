#include <iostream>
#include<algorithm>
#include<climits>

using namespace std;

int get_change(int money)
{
    int coins[3] = {1,3,4};
    int i,j,MinCoins[money],NCoins;
    MinCoins[0] = 0;
    for(i=1;i<=money;i++)
    {
        MinCoins[i] = INT_MAX;
    }

    for(i=1;i<=money;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i >= coins[j])
            {
                NCoins = MinCoins[i-coins[j]] + 1;
                if(NCoins < MinCoins[i])
                    MinCoins[i] = NCoins;
            }
        }
    }
    return MinCoins[money];

}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
