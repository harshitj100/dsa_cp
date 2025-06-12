class Solution {
public:// O(n) O(1)
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // next_permutation(nums.begin() , nums.end());
        bool f = false;
        for(int i = n-1 ; i > 0 ; i--){
            if (nums[i] > nums[i-1]){
                f = true;
                int j = i;
                while(j < n && nums[j] > nums[i-1]){
                    j++;
                }
                j--;
                swap(nums[i-1] , nums[j]);
                reverse(nums.begin()+i , nums.end());
                break;
            }
        }
        if (!f){
            reverse(nums.begin() , nums.end());
        }
    }
};