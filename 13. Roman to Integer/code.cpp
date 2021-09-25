//https://leetcode.com/problems/roman-to-integer/

#include <iostream>

 int romanToInt(std::string s) {
    int sum = 0;
    for (int i = 0; i <= s.length(); i++) {
        if(s[i] == 'M') {
            sum += 1000;
        }
        if (s[i] == 'D') {
            sum += 500;
        }
        if (s[i] == 'C') {
            if (s[i+1] == 'M') {
                i++;
                sum += 900;
            }   else if(s[i+1] == 'D') {
                i++;
                sum += 400;
            }   else {
                sum += 100;
            }
        }
        if (s[i] == 'L') {
            sum += 50;
        }
        if (s[i] == 'X') {
            if (s[i+1] == 'C') {
                i++;
                sum += 90;
            }   else if (s[i+1] == 'L') {
                    i++;
                    sum += 40;
                }   else sum += 10;
        }
        if (s[i] == 'V') {
            sum += 5;
        }
        if (s[i] == 'I') {
            if (s[i+1] == 'X') {
                i++;
                sum += 9;
            }   else if (s[i+1] == 'V') {
                    i++;
                    sum += 4;
                }
                else sum += 1;
        }
    }
    return sum;
}

void test(std::string str, int correctAnswer) {
    int result = romanToInt(str);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passe" << std::endl;
    }
}

int main () {
    test("LVIII", 58);
    test("MCMXCIV", 1994);
}