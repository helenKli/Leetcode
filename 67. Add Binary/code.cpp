//https://leetcode.com/problems/add-binary/

#include <iostream>
#include <string>

std::string addBinary(std::string a, std::string b) {
    std::string res = "";
    int step = 0;
    while (!a.empty() && !b.empty()) {
        if ((a.back() == '0' && b.back() == '1') || (a.back() == '1' && b.back() == '0')) {
            if (step == 0) {
                res.insert(0, "1");
            } else {
                res.insert(0, "0");
            }
        } else if (a.back() == '0' && b.back() == '0') {
            if (step == 0) {
                res.insert(0, "0");
            } else {
                res.insert(0, "1");
                step = 0;
            }
        } else {
            if (step == 0) {
                res.insert(0, "0");
                step = 1;
            } else {
                res.insert(0, "1");
            }
        }
        a.erase(a.size() - 1, 1);
        b.erase(b.size() - 1, 1);
    }
    std::string c = "";
    if (!a.empty()) {
        c = a;
    } else {
        c = b;
    }
    while (!c.empty()) {
        if(c.back() == '0') {
            if (step == 0) {
                res.insert(0, "0");
            } else {
                res.insert(0, "1");
                step = 0;
            }
        } else {
            if (step == 0) {
                res.insert(0, "1");
            } else {
                res.insert(0, "0");
                step = 1;
            }
        }
        c.erase(c.size() - 1, 1);
    }
    if (step == 1) {
        res.insert(0, "1");
    }
    return res;
}

void test(const std::string& str1, const std::string& str2, const std::string& correctAnswer) {
    std::string result = addBinary(str1, str2);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    std::string s1 = "10101", s2 = "111";
    std::string s3 = "101", s4 = "";
    test(s1, s2, "11100");
    test(s3, s4, "101");
    return 0;
}
