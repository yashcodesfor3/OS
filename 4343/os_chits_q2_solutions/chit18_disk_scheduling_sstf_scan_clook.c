#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){ return *(int*)a-*(int*)b; }
int sstf(int r[], int n, int head){
    int used[256]={0}, cur=head, total=0;
    for(int step=0; step<n; step++){
        int idx=-1, best=1e9;
        for(int i=0;i<n;i++) if(!used[i]){
            int d=abs(r[i]-cur);
            if(d<best){best=d; idx=i;}
        }
        used[idx]=1; total+=abs(r[idx]-cur); cur=r[idx];
    }
    return total;
}
int scan(int r[], int n, int head, int maxcyl){
    qsort(r,n,sizeof(int),cmp);
    int pos=0; while(pos<n && r[pos]<head) pos++;
    int total=0, cur=head;
    for(int i=pos;i<n;i++){ total+=abs(r[i]-cur); cur=r[i]; }
    for(int i=pos-1;i>=0;i--){ total+=abs(r[i]-cur); cur=r[i]; }
    return total;
}
int clook(int r[], int n, int head){
    qsort(r,n,sizeof(int),cmp);
    int pos=0; while(pos<n && r[pos]<head) pos++;
    int total=0, cur=head;
    for(int i=pos;i<n;i++){ total+=abs(r[i]-cur); cur=r[i]; }
    if(pos>0){ total+=abs(cur - r[0]); cur=r[0]; for(int i=1;i<pos;i++){ total+=abs(r[i]-cur); cur=r[i]; } }
    return total;
}
int main(){
    int n, head, maxcyl; printf("Enter requests, head, maxCylinder: "); if(scanf("%d%d%d",&n,&head,&maxcyl)!=3) return 0;
    int r[n]; for(int i=0;i<n;i++) scanf("%d",&r[i]);
    printf("SSTF movement=%d\n", sstf(r,n,head));
    printf("SCAN movement=%d\n", scan(r,n,head,maxcyl));
    printf("C-LOOK movement=%d\n", clook(r,n,head));
    return 0;
}
