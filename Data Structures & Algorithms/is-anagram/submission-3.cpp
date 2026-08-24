class Solution {
public:
    bool isAnagram(string s, string t) {
        char charS;
        char charT;
        std::map<char, int> sCount;
        std::map<char, int> tCount;
        if(s.length() != t.length())
        {
            return false;
        }
        for(int i=0; i < s.length(); i++)
        {
            charS = s[i];
            charT = t[i];
            sCount[charS]= sCount[charS]+1;
            tCount[charT]= tCount[charT]+1;
        }
        for(int i=0; i<s.length(); i++)
        {
            if(sCount[s[i]] != tCount[s[i]])
            {
                return false;
            }
        }
        return true;
    }
};
