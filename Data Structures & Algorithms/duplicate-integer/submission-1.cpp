class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto& it : nums)
        {
            if(seen.find(it) == seen.end())
            {
                seen.insert(it);
            }
            else return true;
        }
        return false;
    }
};