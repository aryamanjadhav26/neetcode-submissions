class Solution {
public:
    //max means we need max value in the window
    //priority queue of size window but deleting the element when exiting the window is hard
    //set is ordered but unique. do we care? we just need max? but how do we know which element is dropped due to repetition? multiset is new and usable but erasing a value erases all values
    //store a pair with element index. we drop the smaller index right as the window moves. so ascending with find and remove is fair.
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left=0; 
        int right = 0;
        std::priority_queue<std::pair<int, int>> audit;//value we care about, index
        std::vector<int> result;
        int window_index = 0;//i/windowsize
        for(int i = 0; i < nums.size(); i++)
        {
            audit.push({nums[i], i});
            while(audit.top().second < left )//&& audit.top().second >= right no need
            {//keep removing possible max that are outside of window
                audit.pop();
            }
            if(right - left +1 < k)
            {
                right++;
            }
            else {
                result.push_back(audit.top().first);
            left ++;
            right++;

            }
            
        }
        return result;
    }
};
