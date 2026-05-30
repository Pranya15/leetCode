class MinStack {
public:
    stack<long long> s;
    long long minVal;

    MinStack() {

    }

    void push(int val) {
        if (s.empty()) {
            s.push(val);
            minVal = val;
        }
        else {
            if (val < minVal) {
                s.push(2LL * val - minVal);
                minVal = val;
            }
            else {
                s.push(val);
            }
        }
    }

    void pop() {
        if (s.top() < minVal) {
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            return minVal;
        }
        return s.top();
    }

    int getMin() {
        return minVal;
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