class Solution {
public:
    bool isnum(string s,int start,int end)    //
    {
        if(start>end)return false;
        int i=start;
        int countdot=0;
        while(i<=end)
        {
            if((s[i]=='-'||s[i]=='+')&&i==start)
            {
                if((end-start==1)&&s[i+1]>='0'&&s[i+1]<='9')i++;
                else if(end-start>1)i++;
                else return false;
            }
            else if(s[i]>='0'&&s[i]<='9')i++;
            else if(s[i]=='.'&&(end-start)>0)
            {
                countdot++;
                if(countdot>1)return false;
                i++;
            }
            else return false;
        }
        if(start>0&&countdot>0)return false;     //
        return true;
    }
    
    bool isNumber(string s) {
        for(auto it=s.begin();it!=s.end();)
        {
            if(*it==' ')
            {
                s.erase(it);
                continue;
            }
            else break;
            ++it;
        }
        for(auto it=--s.end();it!=s.begin();--it)
        {
            if(*it==' ')
            {
                s.erase(it);
                continue;
            }
            else break;
        }
        if(s.empty())return false;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='e')
                return isnum(s,0,i-1)&&isnum(s,i+1,n-1);
            else if(s[i]=='.'||(s[i]>='0'&&s[i]<='9')||(s[i]=='-'||s[i]=='+'))continue;
            else return false;
        }
        return isnum(s,0,n-1);
    }
};
