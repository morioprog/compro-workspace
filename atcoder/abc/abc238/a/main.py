# URL : https://atcoder.jp/contests/abc238/tasks/abc238_a
n = int(input())

if n > 100:
    print('Yes')
    exit(0)

if 2 ** n > n ** 2:
    print('Yes')
else:
    print('No')
