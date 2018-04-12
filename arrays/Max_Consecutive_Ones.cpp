/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
*/

class SolutionCrude {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int temp = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                temp++;
            }
            else if(temp != 0)
            {
                if(count < temp)
                {
                    count = temp;
                }
                temp = 0;
            }
        }
        
        if(count < temp)
        {
            count = temp;
        }
        
        return count;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int ret = 0;
        
        for(auto i : nums)
        {
            if(i == 1)
            {
                ret = max(++count, ret);
            }
            else
            {
                count = 0;
            }
        }
        
        return ret;
    }
};