class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ptr1 = 0;
        int ptr2 = 1;
        int n = nums.size();
        int maxLenSubseq = 1;
        while (ptr2 < n) {
            while (ptr2 < n && nums[ptr2] > nums[ptr2 - 1])
                ptr2++;
            maxLenSubseq = max(maxLenSubseq, ptr2 - ptr1);
            ptr1 = ptr2;
            ptr2++;
        }
        return maxLenSubseq;
    }
};