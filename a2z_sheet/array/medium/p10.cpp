class Solution {
public:// O(n^2)  O(1)
    bool ls(vector<int>& nums , int ele){
        for(int i = 0 ; i < nums.size() ; i++){
            if (ele == nums[i]) return true;
        }
        return false;
    }
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        for(int i = 0 ; i < n ; i++){
            int x = nums[i];
            int cnt = 1; 
            while(ls(nums , x+1)){
                x++;
                cnt++;
            }
            ans = max(ans , cnt);
        }
        return ans;
    }
};

class Solution {
public:// O(nlogn + n) O(1)
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        sort(nums.begin() , nums.end());
        int ans = 1;
        int cnt = 1;
        for(int i = 1 ; i < n ; i++){
            if (nums[i]-nums[i-1] == 0) continue;
            if (nums[i]-nums[i-1] == 1){
                cnt++;
                ans = max(ans , cnt);
            } else {
                cnt = 1;
            }
        }
        return ans;
    }
};

class Solution {
public:// O(n) O(n)
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , pair<int , int>> mp;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            mp[nums[i]] = {1 , 1};
        }
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int curr = nums[i];
            int nxt = curr;
            while(true && mp[curr].second == 1){
                nxt = nxt+1;
                if(mp.find(nxt) != mp.end() && mp[nxt].second == 1){
                    mp[curr].first += mp[nxt].first;
                    mp[nxt].second = 0;
                } else {
                    ans = max(ans , mp[curr].first);
                    break;
                }
                ans = max(ans , mp[curr].first);
            }
            cout << ans <<' ' << nxt << ' ' << curr << endl;
        }
        return ans;
    }
};