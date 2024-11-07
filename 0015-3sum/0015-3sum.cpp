#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        int n = nums.size();
        
       
        std::sort(nums.begin(), nums.end());

        
        for (int i = 0; i < n - 2; ++i) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            for (int j = i + 1; j < n - 1; ++j) {
               
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                
                int target = -(nums[i] + nums[j]);
                
                
                int left = j + 1, right = n - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    
                    if (nums[mid] == target) {
                        result.push_back({nums[i], nums[j], nums[mid]});
                        break; 
                    } else if (nums[mid] < target) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
            }
        }
        
        return result;
    }
};
