struct SparseTable {
    vt <vt<int>> table;
    vt <int> lg;
    explicit SparseTable(const vt<int> array) {
        int n = array.size();
        lg.resize(n + 1);
        lg[0] = lg[1] = 0;
        for (int i = 2; i <= n; ++i) {
            lg[i] = lg[i >> 1] + 1;
        }
        int k = lg[n] + 1;
        table.assign(k, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            table[0][i] = array[i];
        }
        for (int i = 1; i < k; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                table[i][j] = min(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int query(int l, int r) {
        int k = lg[r - l + 1];
        return min(table[k][l - 1], table[k][r - (1 << (k))]);
    }
};