class Solution {
  public:
  // time - O(n) , space - O(1)
    int getSecondLargest(vector<int> &arr) {
        return *max_element(arr.begin() , arr.end());
    }
};

// an iterator is an object that allows you to traverse and access elements in a container 
// (like vector, list, set, etc.) in a sequence