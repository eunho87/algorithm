#include <bits/stdc++.h>
using namespace std;

char str[300003];
queue<int> v;
queue<int> z;
int main(){
    int i,l;
    long long S=0;
    scanf("%s",str);

    l=strlen(str);
    for(i=0;i<l;i++){
        str[i]-=64;
    }
    for(i=l-1;i>=0;i--){
        if(str[i]==2)   v.push(i);
        if(v.empty()!= 1){
            if(str[i]==1){
                S+=1;
                str[v.front()]=0;
                str[i]=0;
                v.pop();
            }
        }
    }

    for(i=l-1;i>=0;i--){
        if(str[i]==3)   z.push(i);
        if(z.empty()!=1){
            if(str[i]==2){
                S+=1;
                str[z.front()]=0;
                str[i]=0;
                z.pop();
            }
        }
    }
    printf("%lld",S);
}
