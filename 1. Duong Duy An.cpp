#include<iostream>

using namespace std;
long long n, m;

long long tcs(long long n)
{
    long long t = 0;
    for (int i = 1; i <= n - 1; i++)
        if (n % i == 0) t = t + i;
    return(t);
}

int main()
{
    cout << "Nhap N: ";
    cin >> n;
    cout << "Nhap M: ";
    cin >> m;
    if ((tcs(n) == m) and (tcs(m) == n)) cout << n<<" va "<<m<<" M va N la cap so ban be!!";
    else 
	cout << n << " va " << m << "M va N khong la cap so ban be!!";
}
