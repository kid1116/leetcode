// 双指针合并，时间复杂度为O(m+n)，空间复杂度为O(m+n)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> nums3;
        int i = 0;
        int j = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
                nums3.push_back(nums1[i++]);
            else
                nums3.push_back(nums2[j++]);
        }

        while (i < m)
            nums3.push_back(nums1[i++]);
        while (j < n)
            nums3.push_back(nums2[j++]);

        int p = n + m;
        if (p % 2 == 0)
            return (nums3[p / 2 - 1] + nums3[p / 2]) / 2.0;
        else
            return nums3[p / 2];
    }
};

// 二分查找，时间复杂度优化到O(log(min(m,n)))
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int left = 0;
        int right = m;
        int half = (m + n + 1) / 2;

        while (left <= right)
        {
            int i = (left + right) / 2;
            int j = half - i;
            int Aleft = (i == 0) ? INT_MIN : nums1[i - 1];
            int Aright = (i == m) ? INT_MAX : nums1[i];
            int Bleft = (j == 0) ? INT_MIN : nums2[j - 1];
            int Bright = (j == n) ? INT_MAX : nums2[j];

            if (Aleft <= Bright && Bleft <= Aright)
            {
                if ((m + n) % 2 == 0)
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                else
                    return max(Aleft, Bleft);
            }
            else if (Aleft > Bright)
                right = i - 1;
            else
                left = i + 1;
        }
        return 0.0;
    }
};