#include <stdio.h>

int main() {
    int n, tq, bt[20], at[20], rem_bt[20], wt[20], tat[20];
    int time = 0, completed = 0, i;
    float avgwt = 0, avgtat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rem_bt[i] = bt[i];
        wt[i] = 0;
    }

    printf("\nGantt Chart:\n%d", time);

    // Process execution tracking
    while (completed < n) {
        int done = 1;

        for (i = 0; i < n; i++) {
            // Process must have arrived and not yet finished
            if (at[i] <= time && rem_bt[i] > 0) {
                done = 0;

                if (rem_bt[i] > tq) {
                    printf(" | P%d |", i + 1);
                    time += tq;
                    rem_bt[i] -= tq;
                    printf(" %d", time);
                } else {
                    printf(" | P%d |", i + 1);
                    time += rem_bt[i];
                    wt[i] = time - at[i] - bt[i];
                    tat[i] = time - at[i];
                    rem_bt[i] = 0;
                    completed++;
                    printf(" %d", time);
                }
            }
        }

        // If no process is ready, move time forward
        if (done == 1)
            time++;
    }

    printf("\n");

    // Calculate averages
    for (i = 0; i < n; i++) {
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    // Output table
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}
