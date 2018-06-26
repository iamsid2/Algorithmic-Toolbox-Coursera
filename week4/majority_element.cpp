#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int BSearch(int a[], int low, int high, int x)
{
    if(low > high)
        return -1;
    int middle = (high+low)/2;
    if(a[middle] == x)
    {
        return middle;
    }
    else if(x < a[middle])
    {
        return BSearch(a, low, middle-1, x);
    }
    else
    {
        return BSearch(a, middle+1, high, x);
    }
}

int get_majority_element(int a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right)
    return a[left];




  return -1;
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (size_t i = 0; i < a.size(); ++i)
  {
    cin >> a[i];
  }
  sort(a.begin,a.end);
  cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
