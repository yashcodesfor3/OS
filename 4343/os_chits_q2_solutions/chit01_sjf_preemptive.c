#include <stdio.h>
#include <limits.h>

typedef struct {int id, at, bt, rt, ct, wt, tat;} P;

int main(){
    int n; printf("Enter processes: "); if(scanf("%d",&n)!=1) return 0;
    P a[n]; for(int i=0;i<n;i++){ a[i].id=i+1; printf("AT BT for P%d: ",i+1); scanf("%d%d",&a[i].at,&a[i].bt); a[i].rt=a[i].bt; a[i].ct=a[i].wt=a[i].tat=0; }
    int done=0,t=0,last=-1;
    printf("\nGantt: ");
    while(done<n){
        int idx=-1, best=INT_MAX;
        for(int i=0;i<n;i++) if(a[i].at<=t && a[i].rt>0 && a[i].rt<best){best=a[i].rt; idx=i;}
        if(idx==-1){ t++; continue; }
        if(last!=idx){ printf("| t=%d P%d ",t,a[idx].id); last=idx; }
        a[idx].rt--; t++;
        if(a[idx].rt==0){ a[idx].ct=t; a[idx].tat=a[idx].ct-a[idx].at; a[idx].wt=a[idx].tat-a[idx].bt; done++; printf("-> t=%d ",t); last=-1; }
    }
    double aw=0, atat=0; printf("|\n\nID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){ printf("%2d %2d %2d %2d %3d %2d\n",a[i].id,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt); aw+=a[i].wt; atat+=a[i].tat; }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", aw/n, atat/n);
    return 0;
}
