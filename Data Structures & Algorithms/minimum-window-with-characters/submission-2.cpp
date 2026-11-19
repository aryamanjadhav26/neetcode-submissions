/*class Solution {
public:
    //we have the audit vecotor
    //window spec: std::min(min_window, right - left +1)
    // t stays in the audit vector 
    //keep checking if t.at(i) indexes all are 0 --> save min
    //CheckT is the ineffeciency
    bool checkT(std::vector<int>& audit, string& t, int left, int right)
    {
        for(auto& ch : t)//checking t audit to be 0
        {
            if(audit[ch] > 0) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        std::vector<int> audit(128, 0);
        int left = 0;
        int right = 0;
        std::pair<int, int> minWindow(0,0);//left right
        int minWindowSize = s.length() +1;
        if(s.length()<t.length()) return "";
        for(auto& ch : t)//adding t
        {
            audit[(int)ch]++;
        }
        for(auto& ch: s)
        {
            audit[(int)ch]--;//auditing for s characters
            while(checkT(audit, t, left, right))
            {  
                if(minWindowSize > (right - left +1))
                {
                    minWindowSize = right - left +1;
                    minWindow = {left, right};
                }
                audit[(int)s.at(left)]++; 
                left++;  
            }
            right++;
        }
        if(minWindowSize > s.length()) return "";
        return s.substr(minWindow.first, minWindowSize);

    }
};
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> audit(128, 0);
        int left = 0;
        int right = 0;
        pair<int, int> minWindow(0, 0);
        int minWindowSize = s.length() + 1;
        int missing = t.length();

        if (s.length() < t.length()) return "";

        for (auto& ch : t)
            audit[ch]++;

        for (auto& ch : s)
        {
            if (audit[ch] > 0) missing--;
            audit[ch]--;

            while (missing == 0)
            {
                if (minWindowSize > right - left + 1)
                {
                    minWindowSize = right - left + 1;
                    minWindow = {left, right};
                }

                audit[s[left]]++;
                if (audit[s[left]] > 0) missing++;
                left++;
            }

            right++;
        }

        if (minWindowSize > s.length()) return "";

        return s.substr(minWindow.first, minWindowSize);
    }
};
