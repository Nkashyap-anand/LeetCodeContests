class Solution
{
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors)
    {

        int count_till_now = 0, ans = 0;

        for (int i = 0; i < divisors.size(); i++)
        {
            int count = 0;

            for (int j = 0; j < nums.size(); j++)
            {
                if (nums[j] % divisors[i] == 0)
                    count++;
            }

            if (count > count_till_now)
            {
                count_till_now = count;
                ans = divisors[i];
            }

            if (count == count_till_now)
            {

                ans = min(ans, divisors[i]);
            }
        }
        int mini = *min_element(divisors.begin(), divisors.end());
        return ans = (ans == 0) ? mini : ans;
    }
};