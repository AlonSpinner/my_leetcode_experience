#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 1) {
            std::vector<int> result{1};
            return result;
        }
        std::vector<int> prev = getRow(rowIndex - 1);
        std::vector<int> result(rowIndex,1);
        for (int i = 1; i < rowIndex - 1; i++) {
            result[i] = prev[i-1] + prev[i];
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> result = s.getRow(4);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i] << " ";
    std::cout << std::endl;
}