class Solution {
public:
  // time - O(n) space - O(n)
    int removeDuplicates(vector<int>& nums) {
        int i = -1; 
        int j = 0;
        for(j ; j < nums.size() ; j++){
            if (i != -1 && nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            } else if (i == -1) {
                nums[++i] = nums[j];
            }
            // cout << i << ' ' << j << endl;
        }
        
        return i+1;
    }
};