class Solution {
public:// O((n/2)*(n-1)) O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n1 = n;
        int i = 0;
        int j = n-1;
        while(n1 > 1){
            int n2 = n1;
            int i1 = i , i2 = i , i3 = j , i4 = j;
            n2--;
            while(n2--){
                cout << matrix[i][i1] << matrix[i4][i] << matrix[j][i3] << matrix[i2][j] << endl;
                int temp = matrix[i][i1];
                matrix[i][i1] = matrix[i4][i];
                matrix[i4][i] = matrix[j][i3];
                matrix[j][i3] = matrix[i2][j];
                matrix[i2][j] = temp;
                i1++;
                i2++;
                i3--;
                i4--;
            } cout << endl;
            n1 -= 2;
            i++;
            j--;
        }
    }
};