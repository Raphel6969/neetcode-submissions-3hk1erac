class MinStack {
public:
        stack<int> st;
        stack<int> min_st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty() && min_st.empty()){
            st.push(val);
            min_st.push(val);
            return;
        }
        int min_val = min_st.top();
        st.push(val);
        if(val < min_val){
            min_st.push(val);
        }else{
            min_st.push(min_val);
        }
    }
    
    void pop() {
        st.pop();
        min_st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
