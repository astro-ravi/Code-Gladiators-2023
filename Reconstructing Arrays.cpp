/*
Reconstructing Arrays

Jack is a programmer who is working on a new feature for his company's website. The feature involves displaying a list
of products with their corresponding prices in an array on the website.

One day, Jack noticed that the array of prices was printed on the website as a string (size N) of digits without any spaces.
Jack needs to retrieve the original array from the printed string, but he only knows that all integers in the array were in
the range [1, K] and there were no leading zeros in the array.

To retrieve the original array, Jack needs to figure out all the possible arrays that could have been printed as the given
string S. He wants to automate this process, and so he needs to write a program that can calculate the number of possible arrays
based on the given string and the range K.

Example 1:
If the given string is "123" and K is 3, there is a single possible array: [1, 2, 3]. Note that [2, 3, 1] is not a valid array
because the integers are out of order.

Example 2:
If the given string is "123" and K is 1000, there are four possible arrays: [1, 2, 3], [12, 3], [1, 23], [123]

Since, the number of possible arrays may be very large, Jack needs to return the answer modulo 10^9 + 7. Can you help Jack by writing a program to calculate the number of possible arrays?


Input Format
The first line of the input contains two space-separated integers, N and K.
The second line of the input contains a string S, consisting of only digits (0-9) and does not contain leading zeros.

Constraints
1 <= N <= 10^5
1 <= K <= 10^9

Output Format
A single positive integer representing the number of possible arrays.

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int m = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    string str;
    cin >> str;

    vector<int> dp(n + 1, 0);
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        if (str[i] == '0')
            continue;

        long long num = 0;
        for (int j = i; j < n; ++j) {
            num = num * 10 + (str[j] - '0');
            if (num > k)
                break;
            dp[i] = (dp[i] + dp[j + 1]) % m;
        }
    }

    cout << dp[0] << endl;

    return 0;
}