class Solution {
public:
    #define ll long long
    long long minCost(string s, int enc, int flat) {
        int n = s.size();
        ll c = 0;
        vector<ll> pref(n+1);
        for(int i=0;i<n;i++){
            if(s[i]=='1')c++;
            pref[i+1] = c;
        }
        if(n%2){
            if(c==0) return flat;
            else return (n*c*enc);
        }
        
        function<ll(int,int)> f =[&](int l,int r)->ll{
            ll len = r-l+1;  
            ll sensi = pref[r+1]-pref[l];
            if(len%2){
                if(!sensi) return flat;
                return (len*sensi*enc);
            }
            ll ans = 1;
            if(sensi==0){
                ans = flat;
            }
            else{
                ans = len*sensi*enc;
            }
            ll mid = (l+r)>>1;
            return min(ans,f(l,mid)+f(mid+1,r));
        };
        return f(0,n-1);
        
    }
};