#include <vector>

class Solution {
public:
    std::vector<int> findPeaks(std::vector<int>& mountain) {
        std::vector<int> ans;
        for (size_t i = 1; i < mountain.size() - 1; ++i) {
            (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1])
                ? ans.push_back(i)
                : (void)0;
        }
        return ans;
    }
};