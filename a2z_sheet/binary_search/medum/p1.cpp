class Solution {
public:// O(logn) O(1)
    int bs(int x , int s , int e){
        if (s > e) return e;

        int m = s + (e - s) / 2;
        long long sq = 1LL * m * m;

        if (sq == x) return m;
        else if (sq < x) return bs(x, m + 1, e);
        else return bs(x, s, m - 1);
    }

    int mySqrt(int x) {
        return bs(x, 0, x);
    }
};
// why do we returned e
class Solution {
public: // iterative 
    int mySqrt(int x) {
        int s = 0;
        int e = x;
        int ans = 0;
        while(s <= e){
            long long m = s + (e-s)/2;
            if ((long long)(m*m) <= x){
                ans = m;
                s = m+1;
            } else {
                e = m-1;
            }
        }

        return ans;
    }
};
