class Solution {
public:

    bool isValidSudoku(vector<vector<char>>& board) {
        std::unordered_set<char> boxes[9];
        std::unordered_set<char> rows[9];
        std::unordered_set<char> columns[9];

        for(int i=0; i<board.size();i++)
        {
            for(int j=0; j<board.size(); j++)
            {
                char c= board[i][j];
                if(c=='.') continue;
                if(rows[i].insert(c).second == false) return false;
                if(columns[j].insert(c).second == false) return false;
                int sb= (i / 3) * 3 + j / 3;
                if(boxes[sb].insert(c).second == false) return false;
            }
        }
        return true;
        
    }
};
