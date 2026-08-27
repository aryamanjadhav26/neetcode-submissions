class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;

        std::sort(nums.begin(), nums.end());
        int left= 0;
        int right= nums.size()-1;
        for(int target=0; target<nums.size(); target++)
        {
            if (target > 0 && nums[target] == nums[target - 1])
            continue;
            int left = target + 1;
            int right = nums.size() - 1;
            while(left<right)
            {
                if(nums[left]+nums[right] < -nums[target]) left++;
                else if(nums[left]+nums[right] > -nums[target]) right--;
                else 
                {
                    res.push_back({nums[left], nums[right], nums[target]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    // Skip duplicate right values
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return res;  
    }
};
