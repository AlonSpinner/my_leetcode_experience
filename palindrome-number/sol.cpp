#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        int x_original = x;
        int x_reverse = 0;
        while (x > 0) {
            x_reverse *= 10;
            x_reverse += x % 10;
            x = x/10;
        }
        if (x_original == x_reverse) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution s;
    int x = 123321;
    std::cout <<  std::boolalpha << s.isPalindrome(x) << std::endl;
}