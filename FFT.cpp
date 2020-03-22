#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;
typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
    int n = (int) a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = (inv ? 1 : -1) * M_PI / i;
        base w = {cos(x), sin(x)};
        for (int j = 0; j < n; j += i << 1) {
            base th = {1, 0};
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) {
            a[i] /= n;
        }
    }
}
vector<int> multiply(vector<int> &A, vector<int> &B) {
    vector<base> a(A.begin(), A.end());
    vector<base> b(B.begin(), B.end());
    int t=max(a.size(), b.size());
    int n=1;
    while (t > n) n <<= 1;
    n*=2;

    a.resize(n);	b.resize(n);
    fft(a, false);	fft(b, false);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];
    fft(a, true);

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = (int)round(a[i].real());
    return ret;
}
int main(){
    string a,b;
    cin>>a>>b;

    vector<int> A(a.size()),B(b.size());
    for(int i=0;i<a.length();i++)
        A[i]=a[i]-'0';
    for(int i=0;i<b.length();i++)
        B[i]=b[i]-'0';
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<int> ret = multiply(A, B);

    int i = 0;
    while (i < ret.size()) {
        if (ret[i] >= 10) {
            if (i == ret.size() - 1)
                ret.push_back(ret[i] / 10);
            else
                ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }
        i++;
    }

    reverse(ret.begin(), ret.end());

    bool start = false;
    for (auto elem : ret) {
        if (elem)start = true;
        if (start)cout << elem;
    }
    if (!start)cout << '0';

    return 0;
}
