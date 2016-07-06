n, m, q = list(map(int, input().split()))
for i in range(0, q):
    a, b, c, d = list(map(int, input().split()))
    print (((d-c+1)*(c+d)*(b-a+1)*(a+b) // 4) % 1000000007)
