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

struct Pref2D {
    vt <vt <ll>> pref;
    Pref2D(vt <vt<int>>& grid) {
        size_t n = grid.size(), m = grid[0].size();
        pref.resize(n + 1);
        for (int i = 0; i <= n; ++i) {
            pref[i].assign(m + 1, 0);
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pref[i][j] = pref[i][j - 1] + pref[i - 1][j] + grid[i - 1][j - 1] - pref[i - 1][j - 1];
            }
        }
    }
    ll get(int x0, int y0, int x1, int y1) {
        return pref[x1][y1] - pref[x0][y1] + pref[x0][y0] - pref[x1][y0];
    }
};
