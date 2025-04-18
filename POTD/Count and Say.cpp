class Solution 
{
public:
    string helper(string s, int n)
    {
        if(n == 0)
        {
            return s;
        }
        string result = "";
        int count = 1;
        char curr = s[0];
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == curr)
            {
                count++;
            }
            else
            {
                result += to_string(count);
                result += curr;
                count = 1;
                curr = s[i];
            }
        }
        result += to_string(count);
        result += curr;
        return helper(result, n - 1);
    }

    string countAndSay(int n) 
    {
        return helper("1", n - 1);
    }
};