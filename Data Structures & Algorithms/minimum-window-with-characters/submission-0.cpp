class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()){
            return "";
        }
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        for(int i = 0; i < t.length(); i++){
            m1[t[i]]++;
        }
        int need = m1.size();
        int formed = 0;
        int ans = INT_MAX;
        int start = 0;
        int l = 0, r = 0;
        for(r; r < s.length(); r++){
            if(m1.count(s[r])){
                m2[s[r]]++;
                if(m2[s[r]] == m1[s[r]]){
                    formed++;
                }
            }
            
            while(formed == need){
                int win_len = r - l + 1;
                if (win_len < ans) {
                    ans = win_len;
                    start = l;
                }

                if(!m1.count(s[l])){
                    l++;
                }else{
                    m2[s[l]]--;
                    if(m1[s[l]] > m2[s[l]]){
                        formed--;
                    }
                    l++;
                }
            }
        }

        if (ans == INT_MAX) {
            return "";
        }

        return s.substr(start, ans);
        
    }
};
