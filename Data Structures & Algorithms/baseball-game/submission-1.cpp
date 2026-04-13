class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int n1 = st.top(); st.pop();
                int n2 = st.top(); st.pop();

                st.push(n2);
                st.push(n1);
                st.push(n1 + n2);
            } 
            else if (operations[i] == "D") {
                st.push(st.top() * 2);
            } 
            else if (operations[i] == "C") {
                st.pop();
            } 
            else {
                st.push(stoi(operations[i]));
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};