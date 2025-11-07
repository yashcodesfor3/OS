#include <stdio.h>
#define MAXF 10
#define MAXP 1000

int faults_lru(int frame[], int f, int pages[], int pn){
    int age[16]; for(int i=0;i<f;i++){ frame[i]=-1; age[i]=0; }
    int faults=0;
    for(int t=0;t<pn;t++){
        int x=pages[t], hit=-1;
        for(int i=0;i<f;i++) if(frame[i]==x){ hit=i; break; }
        for(int i=0;i<f;i++) if(frame[i]!=-1) age[i]++;
        if(hit!=-1){ age[hit]=0; } else {
            faults++;
            int idx=-1, oldest=-1;
            for(int i=0;i<f;i++){
                if(frame[i]==-1){ idx=i; break; }
                if(age[i]>oldest){oldest=age[i]; idx=i;}
            }
            frame[idx]=x; age[idx]=0;
        }
    }
    return faults;
}
int faults_opt(int frame[], int f, int pages[], int pn){
    for(int i=0;i<f;i++) frame[i]=-1;
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
    return faults;
}
int faults_fcfs(int frame[], int f, int pages[], int pn){
    for(int i=0;i<f;i++) frame[i]=-1;
    int faults=0, front=0;
    for(int i=0;i<pn;i++){
        int x=pages[i], hit=0;
        for(int j=0;j<f;j++) if(frame[j]==x){ hit=1; break; }
        if(hit) continue;
        faults++;
        frame[front]=x; front=(front+1)%f;
    }
    return faults;
}
int main(){
    int f,pn; printf("Frames and pages: "); if(scanf("%d%d",&f,&pn)!=2) return 0;
    int pages[pn]; for(int i=0;i<pn;i++) scanf("%d",&pages[i]);
    int frame[16];
    int f1 = faults_fcfs(frame,f,pages,pn);
    int f2 = faults_lru(frame,f,pages,pn);
    int f3 = faults_opt(frame,f,pages,pn);
    printf("FCFS=%d LRU=%d Optimal=%d\n", f1,f2,f3);
    return 0;
}
