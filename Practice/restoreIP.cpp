class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size()<4 || s.size()>16)
            return vector<string>();
        vector<string> ret;
        helper(ret,s,0,-1,"");
        return ret;
    }
    void helper(vector<string> & ret, string s, int ptr, int round, string curr){
        if(ptr==s.size() && round==3){
            ret.push_back(curr.substr(1));
        }
        else if(ptr>s.size())
            return;
        else{
            
            for(int i=0;i<3;i++){
                if(ptr+i>=s.size())
                    return;
                string temp="";
                for(int j=0;j<=i;j++){
                    temp+=s[ptr+j];
                }
                if(temp.size()==1 || (temp[0]!='0' && stoi(temp)<256))
                    helper(ret,s,ptr+i+1,round+1,curr+'.'+temp);
            }
        }
    }
};
