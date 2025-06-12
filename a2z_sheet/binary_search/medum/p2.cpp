class Solution {
  public:// O(mn) // O(1)
    int nthRoot(int n, int m) {
        // Code here.
        int prev = -1;
        for (int i = 0 ; i <= m ; i++){
            int n2 = n;
            int v = 1;
            while(n2--){
                v *= i;
            }
            if (v > m){
                break;
            } else if (v == m) {
                prev = i;
            }
        }
        return prev;
    }
};

class Solution {
  public:// O(nlogm) O(1)
  int check (int i , int m , int n){
      int v = 1;
    while(n--){
        v *= i;
    }
    if (v <= m){
        return true;
    } else {
        return false;
    }
  }
    int nthRoot(int n, int m) {
        // Code here.
        int s = 0 , e = m;
        while(s <= e){
            int mid =( s+e)/2;
            if (check(mid , m , n)){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        int v = 1;
        while(n--){
            v *= e;
        }
        if (v != m){
            return -1;
        }
        return e;
    }
};

class Solution {
  public:// binary exponentiation // O(logn*logm) O(1)
  int expo(int i , int n){
      if (n == 1){
          return i;
      }
      
      if (n%2 == 0){
          int v = expo(i , n/2);
          return v*v;
      } else {
          int v = expo(i , n/2);
          return i*v*v;
      }
  }
  int check (int i , int m , int n){
    int v = expo(i , n);
    if (v <= m){
        return true;
    } else {
        return false;
    }
  }
    int nthRoot(int n, int m) {
        // Code here.
        int s = 0 , e = m;
        while(s <= e){
            int mid =( s+e)/2;
            if (check(mid , m , n)){
                s = mid+1;
            } else {
                e = mid-1;
            }
        }
        int v = 1;
        while(n--){
            v *= e;
        }
        if (v != m){
            return -1;
        }
        return e;
    }
};