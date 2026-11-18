class Solution {
public:
    bool checkPermutation(vector<int>& tally) {
        for(int i : tally)
            if(i != 0) return false;
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> tally(26, 0);
        int window_size = s1.length();

        if(s1.length() > s2.length()) return false;

        for(char c : s1)
            tally[c - 'a']++;

        for(int right = 0; right < s2.length(); right++) {
            // Entering character
            tally[s2[right] - 'a']--;

            // Exiting character
            if(right >= window_size)
                tally[s2[right - window_size] - 'a']++;

            if(right >= window_size - 1 && checkPermutation(tally))
                return true;
        }

        return false;
    }
};