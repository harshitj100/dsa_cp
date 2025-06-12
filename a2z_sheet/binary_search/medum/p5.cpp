class Solution {
public:// O(nlog(max(nums))) O(1)
    int check(vector<int>& nums , int d , int t){
        int n = nums.size();
        long long val = 0;
        for(int i = 0; i < n ; i++){
            val += (long long)((nums[i]+d-1)/d);
        }
        if (val <= t) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin() , nums.end());
        while(s <= e){
            int m = (s+e)/2;
            if (check(nums, m , threshold)){
                e = m-1;
            } else {
                s = m+1;
            }
        }
        return s;
    }
};