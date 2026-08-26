class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> search;
        int size=0;
        int res=0;
        std::vector<int> inits;
        for(auto& i: nums)
        {
            search.insert(i);
        }
        for(auto& i : search)
        {
            if(search.find(i-1) == search.end()) //if no val exists before and successor exists
            {
                inits.push_back(i);
            }
        }
        for(auto& i: inits)//list of start elements
        {
            int current=i;
            size++;
            while(search.find(current+1) != search.end())
            {
                size++;
                current++;
            }
            res=max(size, res);
            size=0;
        }
        return res;
    }
};
