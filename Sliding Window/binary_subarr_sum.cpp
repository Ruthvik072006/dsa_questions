class Solution {
public:
    // NOTE :LEETCODE 1248 IS SAME AS THIS , DO THAT ALSO
    // NOTE : DRY RUN IS VIP FOR EVERYPROBLEM , DO DRY RUNS FOR DIFF TEST CASES AND FIGURE OUT EDGE CASES, REM TO FOLLOW FOR EVERY QUES
    
    
    // if i use the general two pointer sliding window app , i get wrong ans cause
    // they asked to find or linked max sum or max len sub arr etc etc 

    // but here they are asking to find the subarr with sum exactly equal to something
    // say goal , in this case if you use prev two pointer sliding win , we miss some of
    // the internal subarr which contributes to the answer , how you know ?

    // so as we cant find it for sum == goal , i try to find for lets say like prev approaches
    // teh subarr with sum <= k , as we did in prev topics / problems

    // after finding that , you obsevere one thing and that is the main / core algo for these type
    // of ques is mentioned below
    
    
    
    // //the main intution is count the no of subarr which the sum <=goal
    //     //cause for finding subarr, sum == goal , i couldnt figure it out the algo
    //     //so if i do findsubarrr(goal) - findsubarr(goal - 1)

    //     findsubarrr(goal) finds subarr's <= goal 
    //     findsubarrr(goal-1) finds subarr's <= goal -1 
    //     so if i remove subarr < goal i.e findsubarrr(goal-1) from findsubarrr(goal)
    //     then the remaining subarr's is for condition sum == goal , thats the point

    int findsubarr(vector<int>nums,int goal)
    {
        if(goal < 0)
        {
            return 0;
        }
        
        
        int n = nums.size();
        int cnt = 0;

        int l = 0;
        int r = 0;

        int sum = 0;

        while(r < n)
        {
            sum = sum + nums[r];

            while(sum > goal)
            {
                sum = sum - nums[l];
                l++;
            }

            cnt = cnt + (r - l + 1);
            r++;

        }

        return cnt;
    }
    
    
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return findsubarr(nums,goal) - findsubarr(nums,goal - 1);
        

    }
};
