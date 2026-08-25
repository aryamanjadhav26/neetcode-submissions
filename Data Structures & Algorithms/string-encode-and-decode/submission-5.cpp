class Solution {
public:

    string encode(vector<string>& strs) {
        string encoding;
        for(auto& str:strs)
        {
            encoding.append(std::to_string(str.length()));
            encoding.append("#");
            encoding.append(str);
        }
        return encoding;

    }

    vector<string> decode(string s) {
        vector<string> decoding;
        vector<int> lengths;
        int temp_len=0;
        int i=0;
        while(i<s.length())
        {
            if(isdigit(s.at(i)))
            {
                while(s.at(i)!='#')
                {
                    temp_len=temp_len*10+std::stoi(std::string(1,s.at(i)));
                    if(i+1 < s.length()) i++;
                    else break;
                }
                //loop breaks with i at '#'
                lengths.push_back(temp_len);
                temp_len=0;
                if(i+1 < s.length()) i++;
                else 
                {
                    decoding.push_back("");
                    break;
                }
                decoding.push_back(s.substr(i, lengths.back()));
                if(i+lengths.back() < s.length()) i=i+lengths.back();
                else break;
            }
        }
        return decoding;
    }
};
