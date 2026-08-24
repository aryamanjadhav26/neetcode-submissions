class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> lookup;
        std::vector<int> answer;
        int find=0;
        for(int i=0; i<nums.size(); i++)
        {
            lookup[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++)
        {
            find = target - nums[i];
            if(lookup.find(find) != lookup.end() && lookup[find] != i)
            {
                answer.push_back(i);
                answer.push_back(lookup[find]);
                return answer;
            }
        }
        
    }
};
