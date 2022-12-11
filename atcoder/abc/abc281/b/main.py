# URL : https://atcoder.jp/contests/abc281/tasks/abc281_b
s = input()
if len(s) != 8:
    print('No')
    exit(0)

alps = []
for i in range(26):
    alps.append(chr(ord('A') + i))
nums = '0123456789'

if s[0] not in alps:
    print('No')
    exit(0)

if s[-1] not in alps:
    print('No')
    exit(0)

x = s[1:-1]
if all(i in nums for i in x):
    x = int(x)
    if 100000 <= x <= 999999:
        print('Yes')
    else:
        print('No')
else:
    print('No')
