class Solution {
  public:
  // time - O(n) , space - O(1)
    int getSecondLargest(vector<int> &arr) {
        // code here
        int m1 = -1;
        int m2 = -1;
        int n = arr.size();
        for(int i = 0 ; i < n ; i++){
            if (arr[i] == m1) continue;
            if (arr[i] > m1){
                m2 = m1;
                m1 = arr[i];
            } else if (arr[i] > m2){
                m2 = arr[i];
            }
            // cout << m1 << ' ' << m2 << endl;
        }
        return m2;
    }
};

