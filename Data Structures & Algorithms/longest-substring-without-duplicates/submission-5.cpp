class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        int right = 0;
        int left = 0;
        std::unordered_map<char, int> unique;
        if(s.length() == 0) return 0;
        for(int i=0; i< s.length(); i++)
        {
            if(unique.insert({s.at(i), i}).second == false)
            {
                //already exists in substring
                if(max_len < right - left) max_len = right - left;

                left = max(left, unique[s.at(i)] + 1);
                unique[s.at(i)] = i;

            }
            right = i+1;
        }
        return max_len > right - left ? max_len : right -left;
    }
};
