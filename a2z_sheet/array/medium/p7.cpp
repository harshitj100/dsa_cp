class Solution {
public:// O(n+n/2) O(n)
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        vector<int> b;
        for(int i = 0 ; i < n ; i++){
            if (nums[i] < 0) b.push_back(nums[i]);
            else a.push_back(nums[i]);
        }
        n = n/2;
        int i = 0;
        int j = 0;
        while(n--){
            nums[i] = a[j];
            nums[i+1] = b[j];
            i += 2;
            j++;
        }
        return nums;
    }
};

