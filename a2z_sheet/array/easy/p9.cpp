class Solution {
public:
  // time - O(n) space - O(1)
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = 0;
        int n = nums.size();
        int max_len = 0;
        for(int i = 0 ; i < n ; i++){
            if (nums[i] == 1){
                len++;
                max_len = max(max_len , len);
            } else {
                len = 0;
            }
        }
        return max_len;
    }
};