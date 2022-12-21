#include <iostream>
 
class Solution {
public:
    int climbStairs(int n) {
        switch (n) {
            case 0:
                return 0;
                break;
            case 1:
                return 1;
                break;
            case 2:
                return 2;
                break;
            default:
                return climbStairs(n-1) + climbStairs(n-2);

        }
    }
};

int main() {
    Solution s;
    std::cout << s.climbStairs(3) << std::endl;
    return 0;
}