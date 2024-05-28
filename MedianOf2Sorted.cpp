#include <bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
    int i = 0, j = 0;
    vector<int> merge;

    // Merge 2 arrays
    while (i < nums1.size() || j < nums2.size())
    {
        if (i >= nums1.size())
        {
            merge.push_back(nums2[j]);
            ++j;
        }
        else if (j >= nums2.size())
        {
            merge.push_back(nums1[i]);
            ++i;
        }
        else
        {
            if (nums1[i] <= nums2[j])
            {
                merge.push_back(nums1[i]);
                ++i;
            }
            else 
            {
                merge.push_back(nums2[j]);
                ++j;
            }
        }
    }
    
    
    if ((i + j) % 2 == 0) // even --> 2 median
    {
        return (double)(merge[(i + j) / 2] + merge[(i + j) / 2 - 1]) / 2;
    }
    else // odd --> 1 median
        return merge[(i + j) / 2];
}

int main()
{
    vector<int> array1 = {1, 2};
    vector<int> array2 = {3, 4};
    cout << findMedianSortedArrays(array1, array2);
    return 0;
}