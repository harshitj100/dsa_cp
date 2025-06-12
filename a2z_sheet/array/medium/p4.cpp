class Solution {
public:// O(n^3) O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxi_sum_subarray = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                long long sum = 0;
                for(int k = i ; k <= j ; k++){
                    sum += (long long)nums[k];
                }
                maxi_sum_subarray = max(sum , maxi_sum_subarray);
            }
        }
        return maxi_sum_subarray;
    }
};

class Solution {
public:// prefix sum O(N^2) O(n)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxi_sum_subarray = 0;
        vector<long long> pf(n+1 , 0);
        long long sum = 0;
        for(int i = 0; i < n ; i++){
            sum += (long long)nums[i];
            pf[i+1] = sum;
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = i ; j < n ; j++){
                maxi_sum_subarray = max(pf[j+1]-pf[i] , maxi_sum_subarray);
            }
        }
        return maxi_sum_subarray;
    }
};

class Solution {
public:// optimal O(n) O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1 ; i < n ; i++){
            sum += nums[i];
            sum = max(sum , nums[i]);
            maxi = max(maxi , sum);
        }
        return maxi;
    }
};

class Solution {
public:// optimal 2 O(n) O(1)
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1 ; i < n ; i++){
            if (sum < 0) sum = 0;
            sum += nums[i];
            maxi = max(sum , maxi);
        }
        return maxi;
    }
};