class Solution {
public:
    int minimumEffort(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [&](vector<int> &a, vector<int> &b){
            return max(a[0]+b[1], a[1]) < max(b[0]+a[1], b[1]);
        });

        int sm = 0;
        for(int i=0; i<arr.size(); i++){
            sm += arr[i][0];
        }

        if(arr[0][1]>sm){
            sm = arr[0][1];
        }

        int act = sm; //sm will be cur now
        for(int i=0; i<arr.size(); i++){
            if(sm>=arr[i][1]){
                sm -= arr[i][0];
            }else{
                act += (arr[i][1]-sm);
                sm = arr[i][1] - arr[i][0];
            }
        }

        return act;
    }
};