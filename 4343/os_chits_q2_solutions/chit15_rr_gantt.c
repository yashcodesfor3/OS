#include <stdio.h>

typedef struct{int id, at, bt, rt, ct, wt, tat;} P;

int main(){
    int n, q; printf("Enter processes and quantum: "); if(scanf("%d%d",&n,&q)!=2) return 0;
    P a[n]; for(int i=0;i<n;i++){ a[i].id=i+1; printf("AT BT for P%d: ",i+1); scanf("%d%d",&a[i].at,&a[i].bt); a[i].rt=a[i].bt; a[i].ct=a[i].wt=a[i].tat=0; }
    int t=0, done=0; int qidx=-1;
    printf("\nGantt: ");
    while(done<n){
        int progressed=0;
        for(int i=0;i<n;i++){
            if(a[i].rt>0 && a[i].at<=t){
                int slice = a[i].rt<q? a[i].rt:q;
                printf("| t=%d P%d ",t,a[i].id);
                a[i].rt -= slice; t += slice; progressed=1;
                if(a[i].rt==0){ a[i].ct=t; a[i].tat=a[i].ct-a[i].at; a[i].wt=a[i].tat-a[i].bt; done++; printf("-> t=%d ",t); }
            }
        }
        if(!progressed) t++;
    }
    printf("|\n");
    double aw=0, atat=0; printf("\nID AT BT CT TAT WT\n");
    for(int i=0;i<n;i++){ printf("%2d %2d %2d %2d %3d %2d\n",a[i].id,a[i].at,a[i].bt,a[i].ct,a[i].tat,a[i].wt); aw+=a[i].wt; atat+=a[i].tat; }
    printf("Avg WT=%.2f Avg TAT=%.2f\n", aw/n, atat/n);
    return 0;
}
