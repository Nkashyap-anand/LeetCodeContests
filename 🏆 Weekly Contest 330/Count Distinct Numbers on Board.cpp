// my solution
class Solution
{
public:
    int distinctIntegers(int n)
    {

        queue<int> q;
        q.push(n);
        set<int> s;

        while (!q.empty())
        {
            int elm = q.front();
            s.insert(elm);
            q.pop();

            for (int i = 1; i < elm; ++i)
            {
                if (elm % i == 1)
                    q.push(i);
            }
        }
        return s.size();
    }
};

// it was stupid but actual solution be like
// for n > 1: Eventually you get all numbers except 1
// for n == 1 : 1 get 1 on the board at the beginning

int distinctIntegers(int n)
{
    return max(n - 1, 1);
}