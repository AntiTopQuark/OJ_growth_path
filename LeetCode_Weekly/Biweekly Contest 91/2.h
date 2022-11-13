#ifndef F2B38DA6_D5D4_456B_811A_E7A98E64EC4D
#define F2B38DA6_D5D4_456B_811A_E7A98E64EC4D
#include <math.h>
class Solution {
public:
    void dfs(int low, int high, int zero, int one, int postion, int& count){
        if (postion > high ) {
            return;
        } else {
            if (postion >= low && postion <= high) {
                count++;
            }
            dfs(low,high, zero, one, postion +zero, count);
            dfs(low,high, zero, one, postion +one, count);
        }
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        if (zero == 1 && one == 1) {
            int res = 0;
            for (int i = low; i<= high; i++) {
                res = res + pow(2,i);
            }
            return res;
        }
        int res = 0;
        dfs(low,high, zero, one, 0, res);
        return res;
    }
};

#define aaa 1000000007
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[100000+5];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[zero] = dp[zero] + 1;
        dp[one] = dp[one] + 1;
        int res = 0;
        for (int i = 0; i<= high; i++) {
            if (i >= zero && i>= one) {
                dp[i] = dp[i] + ((dp[i - zero] % aaa) + (dp[i - one]%aaa)) % aaa;
                if (i >= low) {
                    res = (res + dp[i]) % aaa;
                }
            } else if (i >= zero) {
                dp[i] = dp[i] + ((dp[i - zero] % aaa)) % aaa;
                if (i >= low) {
                    res = (res + dp[i]) % aaa;
                }
            } else if (i >= one) {
                dp[i] = dp[i] + ((dp[i - one] % aaa)) % aaa;
                if (i >= low) {
                    res = (res + dp[i]) % aaa;
                }
            } else {
                dp[i] = 0;
            }
        }
        return res;
    }
};
#endif /* F2B38DA6_D5D4_456B_811A_E7A98E64EC4D */
