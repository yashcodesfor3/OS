#include <stdio.h>

void printFrames(int frame[], int f){
    for(int i=0;i<f;i++){
        if(frame[i]==-1) printf("- ");
        else printf("%d ",frame[i]);
    }
    printf("\n");
}

int main(){
    int pages[50], frame[10], used[10]={0};
    int pn, f, i, j, pos, time=0, faults=0;

    printf("Enter number of pages: ");
    scanf("%d",&pn);

    printf("Enter page reference string: ");
    for(i=0;i<pn;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames (minimum 3): ");
    scanf("%d",&f);

    for(i=0;i<f;i++)
        frame[i] = -1;

    printf("\nLRU PAGE REPLACEMENT:\n");

    for(i=0;i<pn;i++){
        int page = pages[i];
        int found = 0;

        // check hit
        for(j=0;j<f;j++){
            if(frame[j] == page){
                found = 1;
                used[j] = time++;
                break;
            }
        }

        // if miss
        if(found == 0){
            pos = 0;
            for(j=1;j<f;j++)
                if(used[j] < used[pos]) pos=j;

            frame[pos] = page;
            used[pos] = time++;
            faults++;
        }

        printf("Page %d -> ",page);
        printFrames(frame,f);
    }

    printf("\nTotal Page Faults = %d\n",faults);
    return 0;
}
