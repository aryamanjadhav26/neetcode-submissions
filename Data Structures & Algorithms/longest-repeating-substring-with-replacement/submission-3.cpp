class Solution {
public:
    int characterReplacement(string s, int k) {
        std::vector<int> count(26, 0);
        int right = 0;
        int left = 0;
        int max_streak =0 ;
        for(int i =0; i< s.length(); i++)
        {
            right = i;
            int window_size = right - left+1;
            max_streak = std::max(max_streak, ++count[(int)s.at(i) - 'A']);
            if((window_size - max_streak) > k)
            {
                count[(int)s.at(left) - 'A'] --;
                left++;
            }
        }
        return right - left + 1;
    }
};
