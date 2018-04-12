/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> comb;
        
        if(m == 0)
        {
            comb.insert(end(comb), begin(nums2), end(nums2));
        }
        else if(n == 0)
        {
            comb.insert(end(comb), begin(nums1), end(nums1));
        }
        else if(nums1[m-1] <= nums2[0])
        {
            comb.insert(end(comb), begin(nums1), end(nums1));
            comb.insert(end(comb), begin(nums2), end(nums2));
        }
        else if(nums1[0] >= nums2[n-1])
        {
            comb.insert(end(comb), begin(nums2), end(nums2));
            comb.insert(end(comb), begin(nums1), end(nums1));
        }
        else
        {
            int i, j;
            for(i = 0, j = 0; i < m && j < n;)
            {
                if(nums1[i] <= nums2[j])
                {
                    comb.push_back(nums1[i]);
                    ++i;
                }
                else
                {
                    comb.push_back(nums2[j]);
                    ++j;
                }
            }
            
            while(i < m)
            {
                comb.push_back(nums1[i]);
                ++i;
            }
            
            while(j < n)
            {
                comb.push_back(nums2[j]);
                ++j;
            }
        }
         
        int x = m+n;
        if(x%2 == 0)
        {
            x = x /2;
            return (comb[x] + comb[x-1])/2.0f;
        }
        x = x /2;
        return comb[x];
        
    }
};