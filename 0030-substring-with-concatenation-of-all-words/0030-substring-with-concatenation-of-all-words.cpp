#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLength = words[0].size();
        int wordCount = words.size();
        int substringLength = wordLength * wordCount;
        int sLength = s.size();

        if (sLength < substringLength) return result;

        unordered_map<string, int> wordFrequency;
        for (const string& word : words) {
            wordFrequency[word]++;
        }

        
        for (int i = 0; i < wordLength; i++) {
            int left = i, right = i;
            unordered_map<string, int> windowMap;
            int count = 0;

            while (right + wordLength <= sLength) {
                string word = s.substr(right, wordLength);
                right += wordLength;

                if (wordFrequency.find(word) != wordFrequency.end()) {
                    windowMap[word]++;
                    count++;

                    
                    while (windowMap[word] > wordFrequency[word]) {
                        string leftWord = s.substr(left, wordLength);
                        windowMap[leftWord]--;
                        left += wordLength;
                        count--;
                    }

                    
                    if (count == wordCount) {
                        result.push_back(left);
                    }
                } 
                else {
                   
                    windowMap.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};
