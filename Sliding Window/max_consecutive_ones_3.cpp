class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //LEETCODE 904 : FRUITS IN BASKET AND THIS ARE SAME QUES
        //LEARN BOTH BETTER AND OPTIMAL TO UNDERSTAND THE SLIDING WIN , TWO POINTERS
        
        //i could change this qeusn into 
        //longesst subarr with at most of k zeros 

        int l = 0;
        int r = 0;

        int n = nums.size();

        int zerocnt = 0;

        int maxlen = 0;

        while(r < n)
        {
            if(nums[r] == 0) zerocnt ++; // 3

            while(zerocnt > k) //not for every iteration , overall o(n)
            {
                if(nums[l] == 0) zerocnt --;
                l++; 
            }

            if(zerocnt <= k)
            {
                maxlen = max(maxlen , r - l + 1);
            }

            r++;
        }

        return maxlen;

        
    }
};
