# URL : https://atcoder.jp/contests/abc248/tasks/abc248_e
N, K = map(int, input().split())
if K == 1:
    print("Infinity")
    exit(0)

ps = [list(map(int, input().split())) for _ in range(N)]
cnt = [0 for _ in range(N + 1)]
for i in range(N):
    for j in range(i + 1, N):
        s = 0
        for k in range(N):
            # 3点が一直線上か
            if (ps[i][1] - ps[j][1]) * (ps[i][0] - ps[k][0]) == \
                    (ps[i][0] - ps[j][0]) * (ps[i][1] - ps[k][1]):
                s += 1
        cnt[s] += 1

res = 0
for i in range(K, N + 1):
    ic2 = i * (i - 1) // 2
    res += cnt[i] // ic2
print(res)
