#include <stdio.h>
#define MAXF 10
#define MAXP 100

int main(){
    int f,pn; printf("Frames and pages: "); if(scanf("%d%d",&f,&pn)!=2) return 0;
    int pages[pn]; for(int i=0;i<pn;i++) scanf("%d",&pages[i]);
    int frame[MAXF]; for(int i=0;i<f;i++) frame[i]=-1;
    int faults=0;
    for(int i=0;i<pn;i++){
        int x=pages[i], hit=0;
        for(int j=0;j<f;j++) if(frame[j]==x){ hit=1; break; }
        if(hit) continue;
        faults++;
        int idx=-1, farthest=-1;
        for(int j=0;j<f;j++){
            if(frame[j]==-1){ idx=j; break; }
            int next=1e6;
            for(int k=i+1;k<pn;k++) if(pages[k]==frame[j]){ next=k; break; }
            if(next>farthest){ farthest=next; idx=j; }
        }
        frame[idx]=x;
    }
    printf("Optimal faults=%d\n", faults);
    return 0;
}
