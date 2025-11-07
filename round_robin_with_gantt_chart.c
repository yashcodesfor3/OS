#include <stdio.h>

int main() {
    int n, tq, bt[20], rem_bt[20], wt[20], tat[20];
    int time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    printf("\nGantt Chart:\n%d", time);

    // ----- Round Robin logic with Gantt chart -----
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {
                if (rem_bt[i] > tq) {
                    printf(" | P%d |", i + 1);
                    time += tq;
                    rem_bt[i] -= tq;
                    printf(" %d", time);
                } else {
                    printf(" | P%d |", i + 1);
                    time += rem_bt[i];
                    printf(" %d", time);
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    printf("\n");

    // ----- Turnaround + averages -----
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    // ----- Output table -----
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}
	
