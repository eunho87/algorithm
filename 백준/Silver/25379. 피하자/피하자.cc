#include <bits/stdc++.h>
using namespace std;

int  arr[1000003],v[1000003];

int main(){
    int i,j,n,l=1,r;
    long long L=0,R=0,p=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)   scanf("%d",&arr[i]);

    for(i=1;i<=n;i++){
        if(arr[i]%2==0){
            v[p]=i;
            p++;
        }
    }
    r=n;
    for(i=1;i<=n;i++){
        if(v[i]==0) break;
        L+=abs(v[i]-l);
        l++;
    }

    for(i=n;i>=1;i--){
        if(v[i]!=0){
            R+=abs(v[i]-r);
            r--;
        }
    }
    printf("%lld",min(R,L));
}
