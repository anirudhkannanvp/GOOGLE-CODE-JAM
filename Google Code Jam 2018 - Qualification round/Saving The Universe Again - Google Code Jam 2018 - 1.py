t=int(input())
for j in range(t):
    d,p=input().split()
    d=int(d)
    p=list(p)
    print("Case #",end="",sep="")
    print(j+1,end="",sep="")
    print(": ",end="",sep="")
    val=0
    cur=1
    n=len(p)
    carr=[0]*n
    for i in range(n):
        if(p[i]=='C'):
            cur*=2
            carr[i]=cur
        if(p[i]=='S'):
            val+=cur
    ans=0
    st2=0
    #print([val])
    while(val>d):
        st=0
        for i in range(n-1,0,-1):
            if(p[i]=='S' and p[i-1]=='C'):
                p[i],p[i-1]=p[i-1],p[i]
                #print("HE")
                ans+=1
                val=0
                cur=1
                carr=[0]*n
                for i in range(n):
                    if(p[i]=='C'):
                        cur*=2
                        carr[i]=cur
                    if(p[i]=='S'):
                        val+=cur
                st=1
                break
        if(st==0):
            print("IMPOSSIBLE",end="",sep="")
            st2=1
            break
    if(st2==0):
        print(ans,end="",sep="")
    print()