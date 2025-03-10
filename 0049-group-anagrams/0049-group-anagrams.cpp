#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        
        for (string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            anagramMap[sortedWord].push_back(word);
        }
        
      
        vector<vector<string>> result;
        for (auto& pair : anagramMap) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
