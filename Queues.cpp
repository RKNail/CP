struct MinQueue {
    stack <pll> st1, st2;
    void add(ll val) {
        if (!st2.empty()) {
            st2.push(make_pair(val, min(val, st2.top().second)));
        } else {
            st2.push(make_pair(val, val));
        }
    }
    ll get() {
        if (st2.empty()) {
            if (st1.empty()) return 0;
            return st1.top().second;
        }
        if (st1.empty()) return st2.top().second;
        return min(st1.top().second, st2.top().second);
    }

    void pop() {
        if (st1.empty()) {
            st1.push(make_pair(st2.top().first, st2.top().first));
            st2.pop();
            while (!st2.empty()) {
                st1.push(make_pair(st2.top().first, min(st2.top().first, st1.top().second)));
                st2.pop();
            }
        }
        st1.pop();
    }
};

struct MaxQueue {
    stack <pll> st1, st2;
    void add(ll val) {
        if (!st2.empty()) {
            st2.push(make_pair(val, max(val, st2.top().second)));
        } else {
            st2.push(make_pair(val, val));
        }
    }
    ll get() {
        if (st2.empty()) {
            if (st1.empty()) return 2e18;
            return st1.top().second;
        }
        if (st1.empty()) {
            return st2.top().second;
        }
        return max(st1.top().second, st2.top().second);
    }

    void pop() {
        if (st1.empty()) {
            st1.push(make_pair(st2.top().first, st2.top().first));
            st2.pop();
            while (!st2.empty()) {
                st1.push(make_pair(st2.top().first, max(st2.top().first, st1.top().second)));
                st2.pop();
            }
        }
        st1.pop();
    }
};

struct GCDQueue {
    stack <pll> st1, st2;
    void add(ll val) {
        if (!st2.empty()) {
            st2.push(make_pair(val, __gcd(val, st2.top().second)));
        } else {
            st2.push(make_pair(val, val));
        }
    }
    ll get() {
        if (st2.empty()) {
            if (st1.empty()) return 0;
            return st1.top().second;
        }
        if (st1.empty()) {
            return st2.top().second;
        }
        return __gcd(st1.top().second, st2.top().second);
    }

    void pop() {
        if (st1.empty()) {
            if (st2.empty()) return;
            st1.push(make_pair(st2.top().first, st2.top().first));
            st2.pop();
            while (!st2.empty()) {
                st1.push(make_pair(st2.top().first, __gcd(st2.top().first, st1.top().second)));
                st2.pop();
            }
        }
        st1.pop();
    }
};
