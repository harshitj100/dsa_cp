class Solution {
public: // O(nlog(max(bloomDay))) O(1) // dont confuse the e with max or size check carefully 
    int check(vector<int>& bloomDay , int d , int m , int k){
        int n = bloomDay.size();
        int c = 0;
        long long val = 0;
        for(int i = 0 ; i < n ; i++){
            if (val >= m) return true;
            if (bloomDay[i] <= d){
                c++;
            } else {
                c = 0;
            }
            if (c == k){
                c = 0;
                val++;
            }
        }
        if (val >= m) return true;
        else return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long v = (long long)m*(long long)k; 
        if (v > n) return -1;
        int s = 1 , e = *max_element(bloomDay.begin() , bloomDay.end());
        while(s <= e){
            int mid = (s+e)/2;
            if (check(bloomDay , mid , m , k)){
                e = mid-1;
            } else {
                s = mid+1;
            }
        }
        return s;
    }
};