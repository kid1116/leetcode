// 运用滑动窗口的思想，使用unordered_set来存储当前窗口内的字符，维护一个左右指针来表示当前窗口的范围。右指针不断向右移动，当遇到重复字符时，左指针向右移动直到不再有重复字符。每次更新窗口大小时，记录最大长度。
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> st;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size())
        {
            while (st.count(s[right]))
            {
                st.erase(s[left]);
                left++;
            }
            ans = max(ans, right - left + 1);
            st.insert(s[right++]);
        }
        return ans;
    }
};

//进阶解法：使用last数组,记录字符最后出现位置，直接更新左边界。