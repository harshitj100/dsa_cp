// User function template for C++
class Solution {
  public:// O(2n) O(n)
    vector<int> findSubarray(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n = arr.size();
        int sum = 0;
        int maxi = 0;
        int start = -1;
        int end = -1;
        int st = -1;
        for(int i = 0 ; i < n ; i++){
            if (arr[i] < 0){
                sum = 0;
                continue;
            }
            sum += arr[i];
            if (arr[i] >= sum){
                start = i;
                sum = arr[i];
            }
            
            if (maxi <= sum){
                st = start;
                end = i;
                maxi = sum;
            }
        }
        if (st == -1 || end == -1) {
            ans.push_back(-1);
            return ans;
        }
        for(int i = st ; i <= end ; i++){
            ans.push_back(arr[i]);
        }
        return ans;
    }
};