class Solution {
public:
    bool isValid(string s) {
        std::stack<char> audit;
        for(auto& c : s)
        {
            if(c == '(' || c == '{' ||c == '[') audit.push(c);
            else if(c == ')' && !audit.empty() && audit.top() == '(') 
            {
                audit.pop();
            }
            else if(c == '}'&& !audit.empty() && audit.top() == '{') 
            {
                audit.pop();
            }
            else if(c == ']' && !audit.empty() && audit.top() == '[') 
            {
                audit.pop();
            }
            else return false;
        }
        return audit.empty();
    }
};
