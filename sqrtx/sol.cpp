#include <iostream>
 
class Solution {
public:
    int mySqrt(int x) {
        for (int i = 0; i < x; i++) {
            if (i*i > x) {return i-1;}
        }
        return 0;
    }
};

int main() {
    Solution s;
    std::cout << s.mySqrt(100) << std::endl;
    return 0;
}