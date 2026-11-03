// first commit:采用暴力枚举，时间复杂度为O(n^2)，空间复杂度为O(1)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//second commit:采用哈希表，时间复杂度为O(n)，空间复杂度为O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(target-nums[i])!= mp.end())
            {
                return{mp[target-nums[i]],i};
            }
            mp.emplace(nums[i],i);
        return {};
    }
};