// https://leetcode.com/problems/increment-submatrices-by-one/

class Solution
{
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>> &queries)
    {

        vector<vector<int>> ans(n, vector<int>(n, 0));

        for (int i = 0; i < queries.size(); ++i)
        {
            int sRow = queries[i][0];
            int sCol = queries[i][1];
            int eRow = queries[i][2];
            int eCol = queries[i][3];

            for (int j = sRow; j <= eRow; ++j)
                ans[j][sCol]++;

            if (eCol + 1 < n)
            {
                for (int j = sRow; j <= eRow; ++j)
                    ans[j][eCol + 1]--;
            }
        }

        // prefix sum
        for (int x = 0; x < n; ++x)
        {
            for (int y = 1; y < n; ++y)
            {
                ans[x][y] += ans[x][y - 1];
            }
        }

        return ans;
    }
};