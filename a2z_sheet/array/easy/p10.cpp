class Solution {
public:
// time - O(n)  space - O(1)
    int singleNumber(vector<int>& nums) {
        int ans = 0; for(int i = 0 ; i < nums.size() ; i++) ans ^= nums[i]; return ans;
    }
};