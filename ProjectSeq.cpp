#include <bits/stdc++.h>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
using namespace std;

void MinimumPenalty(string x, string y, int pxy, int pgap)
{
    int i, j;

    int m = x.length();
    int n = y.length();
    int dp[m+1][n+1] = {0};
    for (i = 0; i <= (n+m); i++)
    {
        dp[i][0] = i * pgap;
        dp[0][i] = i * pgap;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = std::min({dp[i - 1][j - 1] + pxy,
                                dp[i - 1][j] + pgap,
                                dp[i][j - 1] + pgap
                               });
            }
        }
    }
    int l = n + m;

    i = m;
    j = n;

    int xpos = l;
    int ypos = l;
    int xans[l+1], yans[l+1];

    while ( !(i == 0 || j == 0))
    {
        if (x[i - 1] == y[j - 1])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j - 1] + pxy == dp[i][j])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)y[j - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] + pgap == dp[i][j])
        {
            xans[xpos--] = (int)x[i - 1];
            yans[ypos--] = (int)'_';
            i--;
        }
        else if (dp[i][j - 1] + pgap == dp[i][j])
        {
            xans[xpos--] = (int)'_';
            yans[ypos--] = (int)y[j - 1];
            j--;
        }
    }
    while (xpos > 0)
    {
        if (i > 0)
            xans[xpos--] = (int)x[--i];
        else
            xans[xpos--] = (int)'_';
    }
    while (ypos > 0)
    {
        if (j > 0)
            yans[ypos--] = (int)y[--j];
        else
            yans[ypos--] = (int)'_';
    }
    int id = 1;
    for (i = l; i >= 1; i--)
    {
        if ((char)yans[i] == '_' && (char)xans[i] == '_')
        {
            id = i + 1;
            break;
        }
    }
    printf("Minimum Penalty in aligning two problem is = ");
    printf("%d",dp[m][n]);
    printf("\n");
    printf("Aligned as :\n");
    for (i = id; i <= l; i++)
    {
        printf("%c",xans[i]);
    }
    printf("\n");
    for (i = id; i <= l; i++)
    {
        printf("%c",yans[i]);
    }
    return;
}
int main()
{
    char s1[50];
    char s2[50];
    int missMatchPenalty;
    int gapPenalty ;
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%d", &missMatchPenalty);
    scanf("%d", &gapPenalty);
    MinimumPenalty(s1, s2,missMatchPenalty, gapPenalty);
    return 0;
}
