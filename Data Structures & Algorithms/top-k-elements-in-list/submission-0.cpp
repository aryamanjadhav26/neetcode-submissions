class Solution {
public:
    //idea: find top k frequent elements
    //map key is freq, val is element not possible as freq can repeat
    //
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::map<int, int> countRegister;//value, freq
        vector<vector<int>> topk(nums.size() + 1);
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            countRegister[nums[i]]+=1;
        }
        for(auto& pr : countRegister)
        {
            topk[pr.second].push_back(pr.first);
        }
        for(int i = nums.size(); i >= 1; i--)
{
    for(int num : topk[i])
    {
        ans.push_back(num);

        if(ans.size() == k)
            return ans;
    }
}
    }
};
