class Solution
{
public:
    long long putMarbles(vector<int> &weights, int k)
    {

        int n = weights.size();
        long long MaxScore, MinScore;
        MaxScore = MinScore = weights[0] + weights[n - 1]; // 1st and last will always be present

        vector<long long> w;

        for (int i = 1; i < n; ++i)
        {
            w.push_back(weights[i] + weights[i - 1]); // if you divide at i, i+1 will be start of next so generate all pairs of i and i+1
        }

        sort(w.begin(), w.end());

        // for first k maximum and minimum values

        for (int i = 0; i < k - 1; ++i)
            MinScore += w[i];

        reverse(w.begin(), w.end());

        for (int i = 0; i < k - 1; ++i)
            MaxScore += w[i];

        return MaxScore - MinScore;
    }
};