//https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <string>

int lengthOfLastWord(const std::string& s) {
    int l = 0;
    int end = s.length() - 1;
    while (s[end] == ' ') {
        end--;
    }
    while (s[end] != ' ') {
        l++;
        end--;
        if (end == -1) {
            break;
        }
    }
    return l;
}

void test(const std::string& str, int correctAnswer) {
    int result = lengthOfLastWord(str);
    if (result == correctAnswer) {
        std::cout << "Test passed" << std::endl;
    } else {
        std::cout << "Test not passed" << std::endl;
    }
}

int main() {
    test("luffy is still joyboy", 6);
    test("   fly me   to   the moon  ", 4);
    return 0;
}
