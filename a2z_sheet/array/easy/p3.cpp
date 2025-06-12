class Solution {
public:
  // time - O(n) space - O(1)
    bool check(vector<int>& nums) {
        int s = nums[0];
        bool found = false;
        bool ans = true;
        for(int i = 1 ; i < nums.size() ; i++){
            if (!found && nums[i] < nums[i-1]){
                if (s < nums[i]){
                    ans = false;
                    break;
                }
                found = true;
                continue;
            } 
            if (nums[i] < nums[i-1]){
                ans = false;
                break;
            }
            if (found && s < nums[i]){
                ans = false;
                break;
            }
        }
        return ans;
    }
};