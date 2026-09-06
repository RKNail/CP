struct PrefSum {
    vt <ll> pref;
    PrefSum(vt<int>& arr) {
        int n = arr.size();
        pref.resize(n + 1);
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + arr[i];
        }
    }

    ll query(int l, int r) {
        return pref[r] - pref[l-1];
    }
};

struct PrefXor {
    vt <int> pref;
    PrefXor(vt<int>& arr) {
        int n = arr.size();
        pref.resize(n + 1);
        pref[0] = 0;
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] ^ arr[i];
        }
    }

    int query(int l, int r) {
        return pref[r] ^ pref[l-1];
    }
};
