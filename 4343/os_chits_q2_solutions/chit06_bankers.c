#include <stdio.h>

int main(){
    int n,m; printf("Enter processes and resources: "); if(scanf("%d%d",&n,&m)!=2) return 0;
    int max[n][m], alloc[n][m], need[n][m], avail[m];
    for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ scanf("%d",&max[i][j]); } }
    for(int i=0;i<n;i++){ for(int j=0;j<m;j++){ scanf("%d",&alloc[i][j]); } }
    for(int j=0;j<m;j++) scanf("%d",&avail[j]);
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
    int finished[n]; for(int i=0;i<n;i++) finished[i]=0;
    int seq[n], k=0, progress=1;
    while(progress){
        progress=0;
        for(int i=0;i<n;i++) if(!finished[i]){
            int ok=1; for(int j=0;j<m;j++) if(need[i][j]>avail[j]){ ok=0; break; }
            if(ok){
                for(int j=0;j<m;j++) avail[j]+=alloc[i][j];
                finished[i]=1; seq[k++]=i; progress=1;
            }
        }
    }
    if(k==n){ printf("Safe sequence: "); for(int i=0;i<n;i++) printf("P%d ", seq[i]); printf("\n"); }
    else printf("No safe sequence (unsafe state)\n");
    return 0;
}
