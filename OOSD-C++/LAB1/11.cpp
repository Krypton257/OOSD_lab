#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void sol() {
    string a, b;
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();
    int k;
    cin >> k;

    int da = 0, db = 0;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] == '.')
            break;
        da++;
    }
    for (int i = m-1; i >= 0; i--) {
        if (b[i] == '.')
            break;
        db++;
    }
    int cmp = abs(da - db);
    if (da < db) {
        for (int i = 0; i < cmp; i++)
            a += '0';
    }
    else {
        for (int i = 0; i < cmp; i++)
            b += '0';
    }

    int carry = 0;
    n = (int)a.size();
    m = (int)b.size();
    int i = n-1, j = m-1;
    string res;
    while (i >= 0 and j >= 0) {
        if (a[i] == '.') {
            res += a[i];
            i--;
            j--;
            continue;
        }
        int d1 = a[i]-'0';
        int d2 = b[j]-'0';
        int add = (d1 + d2 + carry) % 10;
        carry = (d1 + d2 + carry) / 10;
        res += to_string(add);
        i--;
        j--;
    }
    while (i >= 0) {
        int d1 = a[i]-'0';
        int add = (d1 + carry) % 10;
        carry = (d1 + carry) / 10;
        res += to_string(add);
        i--;
    }
    while (j >= 0) {
        int d1 = b[j]-'0';
        int add = (d1 + carry) % 10;
        carry = (d1 + carry) / 10;
        res += to_string(add);
        j--;
    }
    if (carry) {
        res += to_string(carry);
    }
    reverse(res.begin(), res.end());

    int curr = max(da, db);
    if (curr <= k) {
        for (int t = 0; t < k-curr; t++)
            res += '0';
    }
    else {
        while (curr > k) {
            res.pop_back();
            curr--;
        }
    }
    cout << res << endl;

}

int main()
{
    sol();
    return 0;
}