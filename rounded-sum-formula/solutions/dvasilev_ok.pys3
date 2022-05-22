a, n = map(int, input().split())
mod = 1000000007
if a == 1:
    print(0)
    exit(0)


def pw(x, k):
    if k == 0:
        return 1
    if k % 2:
        return (x * pw(x, k - 1)) % mod
    else:
        d = pw(x, k // 2)
        return (d * d) % mod


def inv(x):
    return pw(x, mod - 2)


if n % 2:
    # -n/2 + 1 + a^2 + a^4 + a^6 + ...
    # n = 3: 1 + a + a^2 + a^3 = 1 + a^2 - 2
    # n = 5: 1 + a + a^2 + a^3 + a^4 + a^5 = 1 + a^2 + a^4 - 3 = 1 + b + b^2 - 3
    b = (a * a) % mod
    g = (pw(b, n // 2 + 1) - 1) * inv(b - 1)
    print((g - (n // 2 + 1) + mod) % mod)
else:
    # n = 2: (1 + a + a^2)/(a + 1) = a + a^2 = a - 1
    # n = 4: (1 + a + a^2 + a^3 + a^4)/(a + 1) = a + a^3 - 2 = a(1 + b) - 2
    b = (a * a) % mod
    g = ((pw(b, n // 2) - 1) * inv(b - 1) * a) % mod
    print((g - n // 2 + mod) % mod)
