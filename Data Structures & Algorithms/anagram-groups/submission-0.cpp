class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> answer;
       std::unordered_map<string, vector<string>> table;
       for(auto i:strs)
       {
        string sorted_copy = i;
        std::sort(sorted_copy.begin(), sorted_copy.end());
        table[sorted_copy].push_back(i); 
       } 
       for(auto i: table)
       {
        answer.push_back(i.second);
       }
       return answer;
    }
};
