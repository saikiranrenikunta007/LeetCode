class MinStack {
public:
    stack<long long>st;
    long long int mini = INT_MAX;
    MinStack() {
         while (st.empty() == false) st.pop();
         mini = LONG_MAX;
    }
    void push(int val) {
        long long value = val;
        if(st.empty()) {
            st.push(val);
            mini = val;
        }
        else if(val < mini) {
            st.push(2*1LL*val - mini);
            mini = val;
        }
        else {
            st.push(val);
        }
        return;
    }
    
    void pop() {
       
        if(st.empty()) return;
        if(st.top() < mini) {
           mini = 2*mini - st.top();
        }
        st.pop();
        return;
    }
    
    int top() {
        if(st.empty()) return -1;
        if (st.top() < mini) return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */