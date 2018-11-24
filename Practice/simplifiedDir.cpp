class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string> drN;
        for(int i=0;i<path.size();++i){
            if(path[i]=='/')
                continue;
            string dr="";
            while(i<path.size() && path[i]!='/'){
                dr+=path[i++];
            }
            if(!drN.empty() && dr=="..")
                drN.pop();
            else if(dr=="." || dr=="..")
                continue;
            else
                drN.push(dr);
        }
        string ret="";
        while(!drN.empty()){
            ret='/'+drN.top()+ret;
            drN.pop();
        }
        return (ret=="")? "/" :ret;
    }
};
