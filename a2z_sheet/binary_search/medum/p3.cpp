class Solution {
public:// O(nlog(max(piles))) O(1)
    bool check(vector<int>& piles , int m , int h){
        if (m == 0) return false;
        long long val = 0;
        for(int i = 0 ; i < piles.size() ; i++){
            val += (long long)((piles[i]+m-1)/m);
        }
        // cout << h << ' ' << m << ' ' << val << endl;
        if (val <= h){
            return true;
        } else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        if (n > h){
            return -1;
        }
        int s = 0;
        int e = *max_element(piles.begin() , piles.end());
        int ans = -1;
        while(s <= e){
            int m = s+(e-s)/2;
            if (check(piles , m , h)){
                ans = m;
                e = m-1;
            } else {
                s = m+1;
            }
        }
        return ans;
    }
};