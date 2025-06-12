class Solution {
public:// O(2n) O(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }
        int i = 0;
        for(i ; i < n ; i++){
            if (mp[nums[i]] > n/2) break;
        }
        return nums[i];
    }
};

class Solution {
public:// O(n) O(1)
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int n = nums.size();
        int ele = nums[0];
        for(int i = 1 ; i < n ; i++){
            if (ele == nums[i]) count++;
            else count--;

            if (count == 0){
                ele = nums[i];
                count = 1;
            }

        }
        return ele;
    }
};