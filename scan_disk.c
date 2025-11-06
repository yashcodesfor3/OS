#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, head, temp, total = 0;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter request sequence: ");
    for (i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter head position: ");
    scanf("%d", &head);

    // sort requests
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (req[j] > req[j+1]) {
                temp = req[j];
                req[j] = req[j+1];
                req[j+1] = temp;
            }

    int index;
    for (i = 0; i < n; i++)
        if (head < req[i]) { index = i; break; }

    printf("\nOrder of head movement: ");
    for (i = index; i < n; i++) {
        printf("%d ", req[i]);
        total += abs(head - req[i]);
        head = req[i];
    }
    for (i = index-1; i >= 0; i--) {
        printf("%d ", req[i]);
        total += abs(head - req[i]);
        head = req[i];
    }

    printf("\nTotal head movement = %d\n", total);
    return 0;
}
