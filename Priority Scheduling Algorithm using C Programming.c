#include <stdio.h>
int main()
{

    int n, i, j, bt[20], pr[20], p[20], wt[20], tat[20], temp;
    printf("Enter number of process: ");
    scanf("%d", &n);

    // Input burst time and priority
    for(i = 0; i < n; i++) {
        printf("Enter burst time and priority for process %d: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1; // Process number
    }
// Sort by priority (small number = high priority)
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(pr[j] < pr[i]) {
    // Swap priority
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
    // Swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
    // Swap process number
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
// Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = wt[i] + bt[i];
    }

    // Print results
    printf("\nP\tBT\tPR\tWT\tTAT\n");
    for( int i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], pr[i], wt[i], tat[i]);

    getch ();
}

