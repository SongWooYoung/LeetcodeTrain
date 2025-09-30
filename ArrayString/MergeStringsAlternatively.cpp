/*
Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

*/

#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        string merged = "";
        int index = 0;
        while (index < len1 && index < len2) {
            merged += word1[index];
            merged += word2[index];
            index++;
        }
        if (index < len1) {
            merged += word1.substr(index);
        }
        if (index < len2) {
            merged += word2.substr(index);  
        }
        return merged;
    }
};


/* GPT Solution

#include <string>
using std::string;

class Solution {
public:
    string mergeAlternately(const string& word1, const string& word2) {
        const size_t n1 = word1.size();
        const size_t n2 = word2.size();
        string merged;
        merged.reserve(n1 + n2);  // 재할당 방지

        size_t i = 0, j = 0;
        while (i < n1 || j < n2) {
            if (i < n1) merged.push_back(word1[i++]);
            if (j < n2) merged.push_back(word2[j++]);
        }
        return merged;
    }
};


*/
