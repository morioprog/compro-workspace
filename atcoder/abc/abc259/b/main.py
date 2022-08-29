# URL : https://atcoder.jp/contests/abc259/tasks/abc259_b

from math import radians, cos, sin

# （xcosθ-ysinθ、xsinθ+ycosθ）
a, b, d = map(int, input().split())
c1 = a * cos(radians(d)) - b * sin(radians(d))
c2 = a * sin(radians(d)) + b * cos(radians(d))
print(c1, c2)
