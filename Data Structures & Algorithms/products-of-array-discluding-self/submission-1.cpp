class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> products(nums.size());
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        int prefix_prod=1;
        int suffix_prod=1;
        for(int i=0; i<nums.size();i++)
        {
            suffix[nums.size()-i-1] = suffix_prod;
            prefix[i] = prefix_prod;
            prefix_prod *= nums[i];
            suffix_prod *= nums[nums.size()-i-1];
        }
        for(int i=0; i<nums.size();i++)
        {
            products[i] = prefix[i] * suffix[i];
        }
        return products;
    }
};
