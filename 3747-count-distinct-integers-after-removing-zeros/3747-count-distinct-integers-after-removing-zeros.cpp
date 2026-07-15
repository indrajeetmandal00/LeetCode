class Solution {
public:
    long long countDistinct(long long n) {
        string s=to_string(n);
        int len=s.size();
        long long ans=0;
        vector<long long> p(len+1,1);
        for(int i=1;i<=len;i++){
            p[i]=p[i-1]*9;
        }
        for(int l=1;l<len;l++){
            ans+=p[l];
        }
        for(int i=0;i<len;i++){
            int d=s[i]-'0';
            if(d==0){
                return ans;
            }
            ans+=(long long)(d-1)* p[len-i-1];
        }
        long long res=ans+1;
        return res;
    }
};
