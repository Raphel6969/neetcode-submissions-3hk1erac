class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length()){
            return false;
        }
        int l = 0;
        int r = s1.length() ;   
        vector<int> a(26, 0);
        vector<int> b(26, 0);

        for(int i = 0; i < s1.length(); i++){
            a[s1[i] - 'a']++;
            b[s2[i] - 'a']++;
        }

        while(r < s2.length()){
            if(a == b){
                return true;
            }
            b[s2[l] - 'a']--;
            b[s2[r] - 'a']++;
            l++;
            r++;
        }

        if(a == b){
            return true;
        }

        return false;
    }
};
