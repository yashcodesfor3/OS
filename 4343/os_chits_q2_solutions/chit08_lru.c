#include <stdio.h>
#define MAXF 10
#define MAXP 100

int main(){
    int f,pn; printf("Frames and pages: "); if(scanf("%d%d",&f,&pn)!=2) return 0;
    int pages[pn]; for(int i=0;i<pn;i++) scanf("%d",&pages[i]);
    int frame[MAXF], age[MAXF]; for(int i=0;i<f;i++){ frame[i]=-1; age[i]=0; }
    int faults=0;
    for(int t=0;t<pn;t++){
        int x=pages[t], hit=-1;
        for(int i=0;i<f;i++) if(frame[i]==x){ hit=i; break; }
        for(int i=0;i<f;i++) if(frame[i]!=-1) age[i]++;
        if(hit!=-1){ age[hit]=0; }
        else{
            faults++;
            int idx=-1, oldest=-1;
            for(int i=0;i<f;i++){
                if(frame[i]==-1){ idx=i; break; }
                if(age[i]>oldest){oldest=age[i]; idx=i;}
            }
            frame[idx]=x; age[idx]=0;
        }
    }
    printf("LRU faults=%d\n", faults);
    return 0;
}
