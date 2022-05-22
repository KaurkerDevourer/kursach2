mod = 1000000007
a, n = map(int, input().split())
res = 0
pw = 1
for i in range(n + 1):
    res += pw // (a + 1)
    pw *= a
print(res % mod)
