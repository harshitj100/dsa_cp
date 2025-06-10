class Solution {
public:
    // time - O(2n) space- O(n)
    void rotate(vector<int>& nums, int k) {
        vector<int> samp;
        int n = nums.size();
        k = k%n;
        int i = n-1;
        int k2 = k;
        while(k2--){
            samp.push_back(nums[i]);
            i--;
        }
        reverse(samp.begin() , samp.end());
        k2 = n-k;
        i = 0;
        while(k2--){
            samp.push_back(nums[i]);
            i++;
        }
        for(int i = 0 ; i < n ; i++){
            nums[i] = samp[i];
        }
    }
};