class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        std::vector<int> res;
        while(left < right)
        {
            if(numbers[left]+numbers[right] < target) left++;
            else if(numbers[left]+numbers[right] > target) right--;
            else {
                res= {left+1, right+1};
                return res;
            }
        }
    }
};
