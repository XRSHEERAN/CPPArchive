class Solution {
public:
    int myAtoi(string str) {
        long int ret=0;
        int sign=1;
        bool strt=false;
        for(int i=0;i<str.size();i++){
            int curr=str[i]-'0';
            if(str[i]==' '){
                if(strt)
                    break;
                continue;
            }
            else if(!ret && str[i]=='-'){
                if(strt||(i>0 && (str[i-1]=='+' || str[i-1]=='-')))
                    break;
                sign=-1;
            }
            else if(str[i]=='+'){
                if(strt||(i>0 && (str[i-1]=='+' || str[i-1]=='-')))
                    break;
            }
            else if(curr>=0 && curr<=9)
                ret=ret*10+curr;
            else
                break;
            if(ret>=2147483648){
                if(sign==1)
                    return 2147483647;
                return 2147483648*sign;
            }
            strt=true;
        }
        
        return sign*ret;
    }
};
