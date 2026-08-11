constexpr int N=1000, mod=1e9+7;
bitset<N+1> sieve;
vector<int> primes;
void Sieve(){
    if (sieve[1]) return;
    sieve[1]=1;
    const int Nsqrt=32;
    for(int p=2; p<=Nsqrt; p+=1+(p>2)){
        if (!sieve[p]){
            primes.push_back(p);
            for(int j=p*p; j<=N; j+=p)
                sieve[j]=1;
        }
    }
    for(int i=33; i<=N; i+=2){
        if (!sieve[i])
            primes.push_back(i);
    }
//    cout<<primes.size();
}
class Solution {
public:
    using ll=long long;
    vector<int> primeDiv;
    void factor(int x){
        if (x<1000 && !sieve[x]) {
            primeDiv.push_back(x);
        }
        vector<int> ans;
        int y=x;
        for(int p: primes){
            if (p*p>x) break;
            int e2=__builtin_ctz(y);
            if(e2>0){
                y>>=e2;
                primeDiv.push_back(2);
            }
            bool flag=0;
            while (y%p==0){
                flag=1;
                y/=p;
            }
            if (flag)
                primeDiv.push_back(p);
        }
        if (y>1){// y must > xsqrt & a prime
            primeDiv.push_back(y);
        }
    }
    ll Kadane(vector<int>& nums, int p){
        int best=INT_MIN, sum=0;
        for(int x : nums){
            int v=(x%p!=0)?-x:x;
            sum=max(v, sum+v);
            best=max(best, sum);
        }
        return best;
    }
    int divisibleGame(vector<int>& nums) {
        Sieve();
        primeDiv.reserve(nums.size()*7);
        for(int x: nums){
            factor(x);
        }
        if (primeDiv.empty()) primeDiv={2};
        sort(primeDiv.begin(), primeDiv.end());
        primeDiv.erase(unique(primeDiv.begin(), primeDiv.end()), primeDiv.end());

        ll maxD=LLONG_MIN;
        int p0=INT_MAX;

        for (int p : primeDiv) {
            ll diff=Kadane(nums, p);
            if (diff>maxD) {
                maxD=diff;
                p0=p;
            }   
        }

        ll ans=maxD*p0%mod;
        return ans<0?ans+mod:ans;
    }
};
auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();