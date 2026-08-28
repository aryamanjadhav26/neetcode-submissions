class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right=heights.size()-1;
        int size=0;
        int max_size=0;
        while(left < right)
        {
            size = (right-left) * std::min(heights[left], heights[right]);
            if(size > max_size) max_size = size;
            if(heights[right] > heights[left])
            {
                left++;
            }
            else right--;
        }
        return max_size;
    }
};
