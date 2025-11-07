#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, head; printf("Enter requests count and head: "); if(scanf("%d%d",&n,&head)!=2) return 0;
    int r[n]; for(int i=0;i<n;i++){ scanf("%d",&r[i]); }
    int used[n]; for(int i=0;i<n;i++) used[i]=0;
    int cur=head, total=0;
    printf("Order: %d", cur);
    for(int step=0; step<n; step++){
        int idx=-1, best=1e9;
        for(int i=0;i<n;i++) if(!used[i]){
            int d=abs(r[i]-cur);
            if(d<best){best=d; idx=i;}
        }
        used[idx]=1; total+=abs(r[idx]-cur); cur=r[idx];
        printf(" -> %d", cur);
    }
    printf("\nTotal head movement=%d\n", total);
    return 0;
}
