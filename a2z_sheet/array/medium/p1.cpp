class Solution {
public:
// brute force time - O(n) space - O(1)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        bool f = false;
        for(int i = 0 ; i < n ; i++){

            for(int j = i+1 ; j < n ; j++){
                if (nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    f = true;
                    break;
                }
            }
            if (f) break;
        }

        return ans;
    }
};

class Solution {
public: // optimal time - O(2n) space - O(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int , int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = i;
        }
        for(int i = 0 ; i < n ; i++){
            int find_val = target-nums[i];
            if (mp.find(find_val) != mp.end()){
                if (mp[find_val] == i) continue;
                ans.push_back(i);
                ans.push_back(mp[find_val]);
                break;
            }
        }

        return ans;
    }
};