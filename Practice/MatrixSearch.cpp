class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int row=1,col=0;
        while(row<matrix.size()){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]<target)
                ++row;
            else break;
        }
        --row;
        while(col<matrix[0].size()){
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                return false;
            ++col;
        }
        return false;
    }
};
