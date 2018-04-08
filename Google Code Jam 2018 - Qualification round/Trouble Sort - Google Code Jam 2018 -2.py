t=int(input())
for j in range(t):
    n=int(input())
    a=list(map(int,input().split()))
    print("Case #",end="",sep="")
    print(j+1,end="",sep="")
    print(": ",end="",sep="")
    b=a[:]
    b.sort()
    st=0
    while(1):
        c=a[:]
        if(a==b):
            st=1
            print("OK")
            break
        for i in range(n-2):
            if(a[i]>a[i+2]):
                a[i],a[i+2]=a[i+2],a[i]
        if(a==b):
            st=1
            print("OK")
            break
        if(a==c):
            for i in range(n):
                if(a[i]>a[i+1]):
                    #print(a)
                    print(i)
                    break
            st=1
            break