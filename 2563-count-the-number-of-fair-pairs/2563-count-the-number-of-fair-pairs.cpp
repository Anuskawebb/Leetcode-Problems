#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array
        sort(nums.begin(), nums.end());
        
        long long count = 0;
        int n = nums.size();
        
       
        for (int i = 0; i < n; ++i) {
            // For each nums[i], find the valid range for nums[j]
            int left = lower - nums[i];  
            int right = upper - nums[i]; 
            
            
            int left_idx = lower_bound(nums.begin() + i + 1, nums.end(), left) - nums.begin();
            
            
            int right_idx = upper_bound(nums.begin() + i + 1, nums.end(), right) - nums.begin();
            
           
            count += right_idx - left_idx;
        }
        
        return count;
    }
};
