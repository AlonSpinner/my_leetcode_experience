#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
 public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map <int, int> x;
        std::vector<int> ans;
        int z;
        for (int i = 0; i < nums.size(); ++i) {
            int z = target - nums[i];
                if (x.find(z) != x.end()) {
                    ans.push_back(x[z]);
                    ans.push_back(i);
                } else {
                    x[nums[i]] = i;
                }
        }
        return ans;       
        }
};

int main() {
    Solution s;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> ans = s.twoSum(nums, target);
    for (int i = 0; i < ans.size(); ++i) {
        std::cout << ans[i] << std::endl;
    }
    std::cout << "done" << std::endl;
    return 0;
}