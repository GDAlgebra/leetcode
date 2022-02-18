/**
 * Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:
 *
 * '.' Matches any single character.​​​​
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 */
bool matches(char s[], char p[], int i, int j) {
    return p[j - 1] == '.' || s[i - 1] == p[j - 1];
}

bool isMatch(char * s, char * p){
    int m=0,n=0;
    // calculate length
    while(*(s+m)!=0)m++;
    while(*(p+n)!=0)n++;

    bool f[m + 1][n + 1];
    // initialize the query table
    memset(f, 0, (m+1)*(n+1));
    f[0][0] = true;
    // initialize the data if S is null
    for (int i = 1; i <= n; i++) {
        if (p[i - 1] == '*') {
            f[0][i] = f[0][i - 2];
        } else {
            f[0][i] = false;
        }
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                f[i][j] = f[i][j - 2] || matches(s, p, i, j - 1) && f[i - 1][j];
            } else {
                f[i][j] = matches(s, p, i, j) && f[i - 1][j - 1];
            }
        }
    }
    return f[m][n];
}
