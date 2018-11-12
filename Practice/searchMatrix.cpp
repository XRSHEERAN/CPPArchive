class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return false;
        int row(matrix.size()-1),col(0);
        while(col<matrix[0].size() && row >-1){
            int temp=matrix[row][col];
            if(temp==target)
                return true;
            else if(temp>target)
                --row;
            else
                ++col;
        }
        return false;
    }
};
