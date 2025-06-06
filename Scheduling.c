#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
    int visited;
};

void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[i].arrival > p[j].arrival) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

void fcfs(struct Process p[], int n) {
    int time = 0;
    float totalWT = 0, totalTAT = 0;

    sortByArrival(p, n);

    for (int i = 0; i < n; i++) {
        if (time < p[i].arrival)
            time = p[i].arrival;

        p[i].completion = time + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        time = p[i].completion;

        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;
    }

    printf("\n--- FCFS Scheduling ---\n");
    printf("PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

void sjf(struct Process p[], int n) {
    int completed = 0, time = 0, min_index;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) p[i].visited = 0;

    printf("\n--- SJF (Non-Preemptive) Scheduling ---\n");

    while (completed < n) {
        int min_burst = 1e9;
        min_index = -1;

        for (int i = 0; i < n; i++) {
            if (!p[i].visited && p[i].arrival <= time && p[i].burst < min_burst) {
                min_burst = p[i].burst;
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
        } else {
            p[min_index].completion = time + p[min_index].burst;
            p[min_index].turnaround = p[min_index].completion - p[min_index].arrival;
            p[min_index].waiting = p[min_index].turnaround - p[min_index].burst;
            p[min_index].visited = 1;
            time = p[min_index].completion;

            totalWT += p[min_index].waiting;
            totalTAT += p[min_index].turnaround;
            completed++;
        }
    }

    printf("PID\tArrival\tBurst\tCompletion\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].arrival, p[i].burst,
               p[i].completion, p[i].waiting, p[i].turnaround);
    }

    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
    printf("Average Turnaround Time: %.2f\n", totalTAT / n);
}

int main() {
    struct Process p[10];
    int n, choice;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Process %d Arrival Time: ", i + 1);
        scanf("%d", &p[i].arrival);
        printf("Process %d Burst Time: ", i + 1);
        scanf("%d", &p[i].burst);
    }

    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First Come First Serve (FCFS)\n");
    printf("2. Shortest Job First (SJF - Non Preemptive)\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
        fcfs(p, n);
    else if (choice == 2)
        sjf(p, n);
    else
        printf("Invalid choice.\n");

    return 0;
}