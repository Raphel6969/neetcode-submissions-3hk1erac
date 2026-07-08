class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        vector<int> a(26, 0);
        int res = 0;

        for (int r = 0; r < s.size(); r++) {
            a[s[r] - 'A']++;

            int win_len = r - l + 1;
            int exch = win_len - *max_element(a.begin(), a.end());

            while (exch > k) {
                a[s[l] - 'A']--;
                l++;

                win_len = r - l + 1;
                exch = win_len - *max_element(a.begin(), a.end());
            }

            res = max(res, win_len);
        }

        return res;
    }
};