# URL : https://atcoder.jp/contests/abc281/tasks/abc281_c
n, t = map(int, input().split())
a = list(map(int, input().split()))
t %= sum(a)
pos = 0
for i, j in enumerate(a):
    pos += j
    if t < pos:
        print(i + 1, j - pos + t)
        exit(0)
