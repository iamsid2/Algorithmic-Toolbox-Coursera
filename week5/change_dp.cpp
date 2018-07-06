#include <iostream>

using namespace std;

int get_change(int m)
{
  //write your code here
  return m / 4;
}

int main()
{
  int m;
  cin >> m;
  cout << get_change(m) << '\n';
}
