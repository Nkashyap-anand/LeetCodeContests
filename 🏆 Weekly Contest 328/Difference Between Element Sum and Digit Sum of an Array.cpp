// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution
{
public:
    int differenceOfSum(vector<int> &nums)
    {

        int eSum = 0, dSum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            eSum += nums[i];
            while (nums[i] > 0)
            {
                int temp = nums[i] % 10;
                dSum += temp;
                nums[i] = nums[i] / 10;
            }
        }

        return abs(eSum - dSum);
    }
};