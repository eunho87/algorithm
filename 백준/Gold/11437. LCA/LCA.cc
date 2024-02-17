#include <bits/stdc++.h>
using namespace std;

vector<vector<int > > vi;
int dep[50003],d[50003][25],chk[50003];

void dfs (int p){
    for(int i=0;i<vi[p].size(); i++){
        int t=vi[p][i];
        if(!chk[t]){
            chk[t]=1;
            dep[t]=dep[p]+1;
            d[t][0]=t;
            d[t][1]=p;
            dfs(t);
        }
    }
}

int main(){
    int n,i,a,b,j,m,cnt;

    cin >> n;
    vi.resize(n+1);

    for(i=1; i<n; i++){
        cin >>a >>b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }

    chk[1]=1;
    dfs(1);

    for(i=2; i<=20; i++){
        for(j=1; j<=n; j++){
            d[j][i]=d[d[j][i-1]][i-1];
        }
    }
    cin >>m;
    for(i=1; i<=m;i++){
        cin >>a>>b;
        if(dep[a]<dep[b]) swap(a,b);
        if(b==1){cout << 1 <<endl; continue;}

        while(dep[a]!=dep[b]){
            cnt=1;
            while(dep[d[a][cnt]]>=dep[b])cnt++;
            a=d[a][cnt-1];
        }

        while(1){
            cnt=0;
            while(d[a][cnt]!=d[b][cnt])cnt++;
            if(cnt<=1)break;
            a=d[a][cnt-1];
            b=d[b][cnt-1];
        }
        cout << d[a][cnt] << '\n';
    }
    return 0;
}
