# URL : https://atcoder.jp/contests/abc259/tasks/abc259_c

from itertools import groupby

s = list(input())
t = list(input())

s = [(k, len(list(v))) for k, v in groupby(s)]
t = [(k, len(list(v))) for k, v in groupby(t)]

if len(s) != len(t):
    print('No')
    exit(0)

for (s1, s2), (t1, t2) in zip(s, t):
    if (s1 != t1) or (s2 > t2) or (s2 == 1 and t2 != 1):
        print('No')
        exit(0)

print('Yes')
