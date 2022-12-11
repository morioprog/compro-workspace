def solve():
    n, k = map(int, input().split())
    s = list(map(int, input().split()))

    if k * 2 < n:
        print('NO')
        return

    dct = {}
    for i in s:
        if i in dct:
            dct[i] += 1
        else:
            dct[i] = 1
    for v in dct.values():
        if v >= 3:
            print('NO')
            return

    print('YES')


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        print(f'Case #{i + 1}: ', end="")
        solve()
