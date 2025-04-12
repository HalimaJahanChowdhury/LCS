#include <iostream>
#include <algorithm>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    // for storing LCS values
    int dp[100][100];


    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            }
            // if characters match,
            else if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            // else
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // print the table
    cout << "\nLCS Table:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    // finding the actual LCS string
    string lcs = "";
    int i = n, j = m;

    while (i > 0 && j > 0) {
        // if characters match
        if (s1[i - 1] == s2[j - 1]) {
            lcs += s1[i - 1];
            i--;
            j--;
        }
        // else
        else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // reverse the LCS
    reverse(lcs.begin(), lcs.end());

    cout << "\nLCS is: " << lcs << endl;
    return dp[n][m];
}

int main() {
    string s1 = "AZERBAIJAN";
    string s2 = "AFGHANISTAN";

    cout << "String 1: " << s1 << endl;
    cout << "String 2: " << s2 << endl;

    int length = lcs(s1, s2);
    cout << "\nLength of LCS: " << length << endl;

    return 0;
}
