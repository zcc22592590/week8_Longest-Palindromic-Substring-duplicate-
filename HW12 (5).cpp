#include <iostream>
#include <string>
using namespace std;
int main()
{
    string x;
    size_t y[100000];
    size_t i, j, max, count, a;
    
    while (cin >> x)
    {
        max = 1;
        count = 0;
        int L = x.size();
        int maxlen = 1, max_even = 0;
        for (i = 0; i < L - max / 2; i++)
        {
            if (i - maxlen < 0 || i + maxlen >= L)
                continue;
            for (j = 1; i - j >= 0 && i + j < L && x[i + j] == x[i - j]; j++)
            {
            }
            if (2 * j - 1 > max)
            {
                max = 2 * j - 1;
                y[0] = i - j + 1;
                count = 1;
                maxlen = j - 1;
            }
            else if (2 * j - 1 == max)
            {
                y[count] = i - j + 1;
                count++;
            }
            if (max_even + i >= L || i - max_even < 0)
                continue;
            for (j = 0; j < L - i && j <= i  && x[i + j + 1] == x[i - j]; j++)
            {
            }
            if (2 * j > max)
            {
                max = 2 * j;
                y[0] = i - j + 1;
                count = 1;
                max_even = j;
            }
            else if (2 * j == max)
            {
                y[count] = i - j + 1;
                count++;
            }
        }
        string t = to_string(max);
        // cout << max;
        if (max > 1)
        {
            for (i = 0; i < count; i++)
            {
                if (i != 0)
                    t += ",";
                t += " ";
                a = y[i];
                for (j = 0; j < max; j++)
                {
                    t.push_back(x[a + j]);
                }
            }
            cout << t << "\n";
        }
        else
            cout << "0\n";
    }
}
