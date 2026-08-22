class Solution {
    
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(0);
        int maxi = INT_MIN;
        int n = heights.size();
        for (int i = 1; i < n; i++) {

            while (!st.empty() && heights[st.top()] > heights[i]) {
                int j = st.top();
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi,heights[j]*w);
            }
            st.push(i);
        }

        while (!st.empty()) {
            int j = st.top();
            st.pop();
            int w = st.empty() ? n : n - st.top() - 1;
            maxi = max(maxi, heights[j] * w);
        }

        return maxi;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxArea=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')heights[j]++;
                else heights[j]=0;
            }
            int area= largestRectangleArea(heights);
            maxArea= max(maxArea,area);
        }
        return maxArea;
        
    }
};