#include <stdio.h>

int main() {
    int n, tq, bt[20], rem_bt[20], wt[20], tat[20];
    int time = 0, completed = 0;
    float avgwt = 0, avgtat = 0;

    // --- Input Section ---
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];   // Copy burst to remaining burst
        wt[i] = 0;           // Initialize waiting time
    }

    // --- Round Robin Logic ---
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (rem_bt[i] > 0) {               // Process not finished
                if (rem_bt[i] > tq) {          // Needs more than 1 quantum
                    time += tq;
                    rem_bt[i] -= tq;
                } else {                       // Will finish in this round
                    time += rem_bt[i];
                    wt[i] = time - bt[i];      // Waiting time once, on completion
                    rem_bt[i] = 0;
                    completed++;
                }
            }
        }
    }

    // --- Calculate Turnaround & Averages ---
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];   // Turnaround time = Burst + Waiting
        avgwt += wt[i];
        avgtat += tat[i];
    }

    avgwt /= n;
    avgtat /= n;

    // --- Output ---
    printf("\nProcess\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);

    return 0;
}
