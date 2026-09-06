vt <ll> fact(1e7 + 1, 1);
vt <ll> invfact(1e7 + 1, 1);

ll bp(ll base, ll pow) {
    if (base == 1) return 1;
    if (base == 0) return 0;
    ll res = 1;
    while (pow > 0) {
        if (pow & 1) {
            --pow;
            (res *= base) %= MOD;
        }
        (base *= base) %= MOD;
        pow >>= 1;
    }
    return res;
}

ll modInverse(ll base) {
    return bp(base, MOD - 2);
}

void precomp() {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i <= 1e7; ++i) {
        fact[i] = (fact[i - 1] * 1ll* i) % MOD;
    }
    invfact[1e7] = modInverse(fact[1e7]);
    for (int i = 1e7 - 1; i >= 1; --i) {
        invfact[i] = (invfact[i+1] * 1ll * (i + 1)) % MOD;
    }
}

ll nCk(ll n, ll k) {
    return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

