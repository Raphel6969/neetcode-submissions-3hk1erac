class Solution {
public:
    bool isValid(string s) {
        map<char, char> m = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;

        for(int i = 0; i < s.length(); i++){
            if(!st.empty() && m.count(st.top()) && m[st.top()] == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        return st.empty();
    }
};
