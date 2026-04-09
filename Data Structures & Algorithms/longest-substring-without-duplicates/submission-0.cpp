class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        int max_val = 0;

        set<char> st;
        for(r; r < s.length(); r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            int w = r - l + 1;
            max_val = max(max_val, w);
        }

        return max_val;

    }
};
