// User function template in C++

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {// time - O(mlogm + nlogn)
        // code here

        sort(a.begin() , a.end());
        sort(b.begin() , b.end());
        vector<int> c;
        c.push_back(-1);
        int a_n = a.size() , b_n = b.size();
        int i = 0 , j = 0;
        while(i < a_n && j < b_n){
            int val = 0;
            if (a[i] > b[j]){
                val = b[j];
                j++;
            } else {
                val = a[i];
                i++;
            }
            if (val != c.back()){
                c.push_back(val);
            }
        }
        
        while(i < a_n){
            if (c.back() != a[i]) c.push_back(a[i]);
            i++;
        }
        while(j < b_n){
            if (c.back() != b[j]) c.push_back(b[j]);
            j++;
        }
        return c.size()-1;
    }
};