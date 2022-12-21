#include <iostream>
#include <string>
#include <vector>
 
class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string longest_prefix = "";
        std::string first_word = strs[0];
        
        for (int i = 0; i < first_word.length(); i++) { //iterate on first word chars
            for (int j = 1; j < strs.size(); j++) //iterate on words
                if (strs[j][i] != first_word[i]) {
                    return longest_prefix;
                }
            longest_prefix += first_word[i];
        }
        return longest_prefix;
    }
};

int main() {
    Solution s;
    std::vector<std::string> strs{"flower","flow","flight"};
    std::string longest_prefix = s.longestCommonPrefix(strs);
    for (int i = 0; i < longest_prefix.length(); i++) {
        std::cout << longest_prefix[i];
    }
    std::cout << std::endl;
}