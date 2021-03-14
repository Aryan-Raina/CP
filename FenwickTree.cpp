struct FenwickTree {
    vector<int> f;
    int N;

    void init(int n) {
        N = n;
        f.assign(N+5, 0);
    }

    void modify(int i, int v) {
        while (i < N) {
            f[i] += v;
            i = i|(i+1);
        }
    }

    int calc(int x) {
        int res = 0;
        while (x >= 0) {
            res += f[x];
            x = x&(x+1); --x;
        }
        return res;
    }

    void update(int l, int r, int v) {
        modify(l, v); modify(r+1, -v);
        if (r < l) modify(0, v), modify(N, -v);
    }
};