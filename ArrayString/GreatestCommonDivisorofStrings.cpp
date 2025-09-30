/*
For two strings s and t, we say "t divides s" if and only if s = t + t + t + ... + t + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""
*/

#include <string>

using namespace std;

class Solution { 
    // -> largest.length() % smallest.length() == 0 인경우 갱신되지 않아 무한루프
    // 한 substr를 반복 생성해 **O(n²)**까지 느려질 수 있음.
    public:
    string gcdOfStrings(string str1, string str2) {
        string largest = str1.length() >= str2.length() ? str1 : str2;
        string smallest = str1.length() < str2.length() ? str1 : str2;
        while(largest != "") {
            if (largest.substr(0, smallest.length()) != smallest) {
                return "";
            }
            if (largest == smallest) {
                return largest;
            }
            if (largest.length() % smallest.length() != 0) {
                largest = largest.substr(0, largest.length() - smallest.length());
                if (largest.length() < smallest.length()) {
                    swap(largest, smallest);
                }
                continue;
            }
        }
        return smallest;
    }
};

/* gpt Solution

#include <string>
#include <numeric> // std::gcd
using namespace std;

class Solution {
public:
    string gcdOfStrings(const string& str1, const string& str2) {
        // 공약 문자열이 존재하려면 두 방향으로 이어붙인 결과가 같아야 함
        if (str1 + str2 != str2 + str1) return "";
        size_t g = std::gcd(str1.size(), str2.size());
        return str1.substr(0, g);
    }
};


*/