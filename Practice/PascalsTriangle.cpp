class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        if(rowIndex==0)
            return {1};
        else if (rowIndex==1)
            return {1,1};
        
        vector<int> ret(rowIndex+1,1);
        for(int i=2;i<=rowIndex;i++){
            int next(1);
            for(int j=1;j<i;j++){
                int temp=next+ret[j];
                next=ret[j];
                ret[j]=temp;
            }
        }
        return ret;
    }
};
