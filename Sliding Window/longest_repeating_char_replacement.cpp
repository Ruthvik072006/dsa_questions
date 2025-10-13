class Solution {
public:
    int characterReplacement(string s, int k) {
// Your Logic:

// To beat current max length, we need: new_length - new_maxfreq ≤ k
// Since we want bigger length, we need bigger maxfreq too
// So decreasing maxfreq is useless - it won't help us find a longer window
// Therefore: never reduce maxfreq


// In practice:

// Keep maxfreq at its historical maximum (even if it's "stale")
// Only update it when we see a higher frequency
// This makes finding new maximum lengths easier, not harder

// That's it. Don't recalculate because lower maxfreq values are useless for finding max length.


// //why iF instead of while ?
// Why if instead of while?Same logic as your comment:
// We only care about growing window size, not shrinking it
// Shrinking window below current max is useless for finding max length
// Therefore: never shrink below current max
// In practice:while: Shrinks window multiple times (makes it smaller than current max)

// ❌ Useless - we already found bigger windows
// if: Slides window by 1 (keeps size same or grows)

// ✅ Useful - maintains max size and looks for bigger
// Bottom line:Just like we never reduce maxfreq, we never reduce window size below current maximum. Use if to slide, not shrink.

        
        
        
        
        
        int n = s.size();

        int l = 0;
        int r = 0;

        vector<int>hasharr(26,0);
        int maxfreq = 0;
        int maxlen = 0;

        while(r<n)
        {
            hasharr[s[r] - 'A']++;

            maxfreq = max(maxfreq,hasharr[s[r] - 'A']);

            int change = (r - l + 1) - maxfreq;

                while((r-l+1) - maxfreq > k)
                {
                    hasharr[s[l] - 'A'] --;
                    l++;
                }

            maxlen = max(maxlen,r-l+1);
            r++;

        }

        return maxlen;
    }
};
