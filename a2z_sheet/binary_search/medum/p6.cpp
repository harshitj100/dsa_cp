class Solution {
public:// O(nlog(sum(weights))) O(1)
    int check(vector<int>& weights , int cap , int d){
        int val = 0;
        int n = weights.size();
        long long sum = 0;
        for(int i = 0; i < n ; i++){
            sum += (long long)weights[i];
            if (sum > cap){
                val++;
                sum = 0;
                i--;
            } 
            //cout << sum << ' ';
        }//cout << endl;
        if (sum != 0) val++;
        //cout << cap << ' ' << val << ' ' << d << endl;
        if (val <= d) return true;
        else return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin() , weights.end());
        int e = accumulate(weights.begin() , weights.end() , 0);
        while(s <= e){
            int m = (s+e)/2;
            if (check(weights , m , days)){
                e = m-1;
            } else {
                s = m+1;
            }
        }
        return s;
    }
};