class Solution {
public:
  // time - O(n) space - O(1)
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int r = n%4;
        if (r == 0) ans = n;
        else if (r == 1) ans = 1;
        else if (r == 2) ans = n+1;
        else ans = 0;

        for(int i = 0 ; i < n ; i++) ans = ans ^ nums[i];
        return ans;

        
    }
};