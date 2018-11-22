class Solution {
public:
    string convertToTitle(int n) {
        if(n<1)
            return "";
        string str="";
        while(n>0){
            if(n%26==0){
                str='Z'+str;
                n=n/26-1;
                continue;
            }
            char temp='A'+(n%26-1);
            str=temp+str;
            if(n==26)
                break;
            n/=26;
            
        }
        return str;
    }
};
