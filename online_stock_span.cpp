// there are two versions to solve this :
//BOTH ARE IMP TO SOLVE AND TO UNDERSTAND THE CONCPET
//TRY LEETCODE - 739 after this


// TYPE 1 : using the prev greater ele concept 

// -> what problem says ? , for an ith element i need the consecutive prev days in which those days has
// the stock market price <= to the curr ith element price

// -> so think, for that i'th element if i found out the prev greater element , then the days bw pge of that ele and that element would consist the
//   elements which are <= the curr element,  so by this logic 
  
// -> i just have to find the nge arr of given arr and if i do :
//    i - nge[i] , i.e current index - nge element index then i get the consec days for that ele which satifies the given condition 



// CODE : 
        vector<int> calculateSpan(vector<int>& arr) {
        // code here
        vector<int>pge = findpge(arr);
        
        int n = arr.size();
        
        vector<int>ans;
        
        for(int i = 0;i<n;i++)
        {
            
            ans.push_back(i - pge[i]);
        }
        
        return ans;





  // TYPE 2 (LEETCODE STYLE ) :

  //   first of all do the dry run with the below code , understand the intution by searching on claude

    stack<pair<int,int>>st;
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && st.top().first <= price)
        {
            span = span + st.top().second;
            st.pop();
        }

        st.push({price,span});

        return span;
    }


// How it works:
// Instead of storing indices, we store {price, span} pairs. When a new price comes:

// Pop all smaller/equal prices and accumulate their spans
// Push the current price with its calculated span
// Return the span

// Example trace:
// For prices: [100, 80, 60, 70, 60, 75, 85]

// Time Complexity: O(1) amortized per call
// Space Complexity: O(n) for the stack











  
        
    }
