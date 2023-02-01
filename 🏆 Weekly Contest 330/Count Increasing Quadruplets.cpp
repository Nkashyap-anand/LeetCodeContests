/*
smallerThan represents count of elements towards the left of index i who are less than no

greaterThan represents count of elements towards the right of index i who are greater than no

Since values in array are from 1 to n only where n is size of array.

We can do above precomputation easily in O(n^2)

Now using two points fix j and k, and using smallerThan and greaterThan, get the count of quadraples.
*/

class Solution
{
public:
    long long countQuadruplets(vector<int> &nums)
    {
        int n = nums.size();

        vector<vector<int>> greaterThan(n, vector<int>(n, 0)), smallerThan(n, vector<int>(n, 0));

        // all possible greater elms from l
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1, greater = 0; j < n; j++)
            {
                greater += (nums[j] > nums[i]);
                greaterThan[i][j] = greater;
            }
        }

        // all possible greater elms from i
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1, smaller = 0; j >= 0; j--)
            {
                smaller += (nums[j] < nums[i]);
                smallerThan[j][i] = smaller;
            }
        }

        long long res = 0;

        for (int j = 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                if (nums[k] < nums[j])
                {
                    int poss_i = (smallerThan[0][k] - smallerThan[j][k]);     // remove overlapping elms in possible i's
                    int poss_l = (greaterThan[j][n - 1] - greaterThan[j][k]); // remove overlapping elms in possible l's
                    res += 1ll * poss_i * poss_l;
                }
            }
        }
        return res;
    }
};