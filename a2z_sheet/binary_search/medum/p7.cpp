class Solution {
public:// O(n*2001) O(1)
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int i = 1 ; i < 2001 ; i++){
            bool flag = false;
            for(int j = 0 ; j < n ; j++){
                if (arr[j] == i){
                    flag = true;
                    break;
                } 
            }
            if (!flag){
                k--;
            }
            if (k == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};