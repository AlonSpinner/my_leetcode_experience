#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
 
class Solution {
public:
    int romanToInt(std::string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case 'I':
                    result += 1;
                    break;
                case 'V':
                    if (i > 0 && s[i-1] == 'I') {
                        result += 5 -2*1;
                    } else {
                        result += 5;
                    }
                    break;
                case 'X':
                    if (i > 0 && s[i-1] == 'I') {
                        result += 10 -2*1;
                    } else {
                        result += 10;
                    }

                    break;
                case 'L':
                    if (i > 0 && s[i-1] == 'X') {
                        result += 50 -2*10;
                    } else {
                        result += 50;
                    }
                    break;
                case 'C':
                    if (i > 0 && s[i-1] == 'X') {
                        result += 100 -2*10;
                    } else {
                        result += 100;
                    }
                    break;
                case 'D':
                    if (i > 0 && s[i-1] == 'C') {
                        result += 500 -2*100;
                    } else {
                        result += 500;
                    }
                    break;
                case 'M':
                    if (i > 0 && s[i-1] == 'C') {
                        result += 1000 -2*100;
                    } else {
                        result += 1000;
                    }
                    break;
                default:
                    char buffer[256];
                    std::sprintf(buffer, "letter %s is not allowed", &s[i]);
                    std::cout << buffer << std::endl;
                    // throw std::invalid_argument(buffer);
                    // throw std::invalid_argument(std::sprintf("letter %s is not allowed"), s[i]);
                    return -1;

            }        
        }
        return result;
    }
};

int main() {
    Solution s;
    std::string roman = "MCMXCIVS";
    int result = s.romanToInt(roman);
    std::cout << result << std::endl;
    return 0;
}