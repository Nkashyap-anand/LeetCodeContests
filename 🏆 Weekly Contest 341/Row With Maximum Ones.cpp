class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {

        vector<int> ans(2);

        int count_till_now = 0;

        for (int i = 0; i < mat.size(); i++)
        {
            int count1 = 0;

            for (int j = 0; j < mat[0].size(); j++)
            {
                if (mat[i][j] == 1)
                    count1++;
            }

            if (count1 > count_till_now)
            {
                count_till_now = count1;
                ans[0] = i;
                ans[1] = count_till_now;
            }
        }
    }
};