template <class T>
struct SWAG {
    SWAG() {}
    stack<pair<T, T>> frontst, backst;
    void push(const T &x) {
        if (backst.empty()) {
            backst.emplace(x, x);
        } else {
            backst.emplace(x, T::f(backst.top().second, x));
        }
    }
    void pop() {
        if (frontst.empty()) {
            while (!backst.empty()) {
                if (frontst.empty()) {
                    frontst.emplace(backst.top().first, backst.top().first);
                } else {
                    frontst.emplace(backst.top().first, T::f(backst.top().first, frontst.top().second));
                }
                backst.pop();
            }
        }
        frontst.pop();
    }
    T fold() {
        if (frontst.empty() && backst.empty()) {
            return T::e;
        }
        if (frontst.empty()) {
            return backst.top().second;
        } else if (backst.empty()) {
            return frontst.top().second;
        }
        return T::f(frontst.top().second, backst.top().second);
    }
};