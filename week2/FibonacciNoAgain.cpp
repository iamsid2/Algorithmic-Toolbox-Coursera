#include <iostream>

using namespace std;

long long pisano_period(long long m)
 {
    long long F1 = 0, F2 = 1,F;
    for (int i = 0; i < m * m; i++)
    {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
        if (F1 == 0 && F2 == 1)
        return i + 1;
    }
}

long long fibonaccifast(long long n, long long m)
{
    long long r = n % pisano_period(m);

    long long F1 = 0, F2 = 1,F;
    for (int i = 1; i < r; i++)
     {
        F = (F1 + F2) % m;
        F1 = F2;
        F2 = F;
    }
    return F % m;
}

int main()
 {
    long long n, m;

    cin >> n >> m;
    cout << fibonaccifast(n, m);
    return 0;
}
