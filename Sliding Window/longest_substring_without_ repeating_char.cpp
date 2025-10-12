class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // IMP POINTS TO REM : 

        // whenever longest or shortest substirng like that use two pointer + sliding win

        // you could use hasharr[256] or unordered map , hasharr is generally better 

        // Always use max(left, ...) to prevent backward movement. 
        // (left should always be moving forward)
        // EX : cadbzabcd

        // Update max every iteration , CAUSE : once dry run for all unique char, you will know
        


        int n = s.size();

        int left = 0;
        int right = 0;

        vector<int>hasharr(256,-1);

        int maxcnt = 0;

        while(right < n)
        {
            if(hasharr[s[right]] != -1) //if already present in hasharr
            {
                left = max(left , hasharr[s[right]] + 1);
            }

            maxcnt = max(maxcnt , right - left + 1);
            hasharr[s[right]] = right;
            right ++;
        }

        return maxcnt;



    }
};
