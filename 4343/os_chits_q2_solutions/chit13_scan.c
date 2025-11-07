#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){ return *(int*)a-*(int*)b; }

int main(){
    int n, head, maxcyl; printf("Enter requests, head, maxCylinder: ");
    if(scanf("%d%d%d",&n,&head,&maxcyl)!=3) return 0;
    int r[n]; for(int i=0;i<n;i++) scanf("%d",&r[i]);
    qsort(r,n,sizeof(int),cmp);
    int pos=0; while(pos<n && r[pos]<head) pos++;
    int total=0, cur=head;
    printf("Order: %d", cur);
    // moving away from spindle -> assume towards higher cylinders
    for(int i=pos;i<n;i++){ total+=abs(r[i]-cur); cur=r[i]; printf(" -> %d",cur); }
    // reverse
    for(int i=pos-1;i>=0;i--){ total+=abs(r[i]-cur); cur=r[i]; printf(" -> %d",cur); }
    printf("\nTotal head movement=%d\n", total);
    return 0;
}
