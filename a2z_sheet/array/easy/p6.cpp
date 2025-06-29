class Solution {
public:
// time - O(n) space - O(1)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 0 ; i < n ; i++){
            if (nums[i] != 0){
                nums[j] = nums[i];
                if (i != j) nums[i] = 0;
                j++;
            } 
        }
    }
};