class Solution {
public:
    bool isAnagram(string s, string t) {
        //we need to know per character frequency or order and check equal
        //do i need to track both, or since i am comparing, we can work with
        //differences
        //ascii lower case is 97 to 122
        vector<int> freq(26, 0);
        if(s.size() != t.size()) return false;
        for(int i=0; i< s.size(); i++)
        {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }
        for(int i=0; i< 26; i++)
        {
            if(freq[i] != 0) return false;
        }
        return true;
    }
};
