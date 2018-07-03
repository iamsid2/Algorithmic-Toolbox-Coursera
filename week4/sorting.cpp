
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> partition3(vector<int> &a, int l, int r)
{
    int x = a[l];
    int j = l;
    int i = l;
    int k = r;
    vector<int> m(2);
    while (i <= k)
    {
        if (a[i] < x)
        {
            swap(a[j], a[i]);
            j++;
            i++;
        }
        else if (a[i] == x)
        {
            i++;
        }
        else
        {
            swap(a[i], a[k]);
            k -= 1;
        }
        m[0] = j;
        m[1] = k;
    }
    return m;
}


void randomized_quick_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    vector<int> m = partition3(a, l, r);

    randomized_quick_sort(a, l, m[0] - 1);
    randomized_quick_sort(a, m[1] + 1, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i)
    {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i)
    {
        cout << a[i] << ' ';
    }
}
