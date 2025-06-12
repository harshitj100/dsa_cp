class Solution {
public: // O(nlogn) O(1)
    void sortColors(vector<int>& nums) {
        sort(nums.begin() , nums.end());
    }
};

class Solution {
public:// O(2n) O(1)
    void sortColors(vector<int>& nums) {
        int a = 0 , b = 0 , c = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if (nums[i] == 0) a++;
            else if (nums[i] == 1) b++;
            else c++;
        }
        int i = 0;
        while(a--){
            nums[i] = 0;
            i++;
        }
        while(b--){
            nums[i] = 1;
            i++;
        }
        while(c--){
            nums[i] = 2;
            i++;
        }
    }
};

class Solution {
public:// two pointers time - O(n) space - O(1)
    void sortColors(vector<int>& nums) {
        int a = 0 , b = nums.size()-1;
        for(int i = a ; i <= b ; i++){
            if (nums[i] == 0){
                swap(nums[a] , nums[i]);
                a++;
            } else if (nums[i] == 2){
                swap(nums[b] , nums[i]);
                b--;
                i--;
            }
        }
    }
};