# URL : https://atcoder.jp/contests/abc259/tasks/abc259_a
n, m, x, t, d = map(int, input().split())
if m >= x:
    print(t)
else:
    print(t - (x - m) * d)
