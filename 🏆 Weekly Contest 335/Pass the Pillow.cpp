class Solution
{
public:
    int passThePillow(int n, int time)
    {

        if (time < n)
            return time + 1;

        int curr = 1;
        int direction = 1;

        for (int i = 0; i < time; i++)
        {
            if (curr == n || (curr == 1 && i != 0))
            {
                direction *= -1;
            }

            curr += direction;
        }
        return curr;
    }
};