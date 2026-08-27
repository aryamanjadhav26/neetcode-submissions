class Solution {
public:
    bool isPalindrome(string s) 
    {
        int trailing = s.length()-1;
        int leading = 0;
        while(leading < trailing)
        {
            char c= std::tolower(s.at(leading));
            char ctrail = std::tolower(s.at(trailing));
            if(!std::isalnum(c)){
                leading++;
                continue;
            } 
            if(!std::isalnum(ctrail))
            {
                trailing--; 
                continue;
            }
            if(c != ctrail)
            {
                return false;
            }
            leading++;
            trailing--;
        }
        return true;
        
    }
};
