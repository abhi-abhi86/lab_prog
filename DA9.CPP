#include <stdio.h>
#include <stdlib.h>

struct job {
    char id;
    int deadline;
    int profit;
};

// Comparison function for qsort to sort jobs by profit in descending order
int compare(const void *a, const void *b) {
    struct job *jobA = (struct job *)a;
    struct job *jobB = (struct job *)b;
    return (jobB->profit - jobA->profit);
}

void jobseq(struct job jobs[], int n) {
    // Sort jobs in descending order of profit
    qsort(jobs, n, sizeof(struct job), compare);

    int i, k, max_deadline = 0;
    // Find the maximum deadline to determine the size of the timeline
    for (i = 0; i < n; i++) {
        if (jobs[i].deadline > max_deadline)
            max_deadline = jobs[i].deadline;
    }

    // Dynamically allocate arrays for the timeline
    char *result = (char *)malloc(max_deadline * sizeof(char));
    int *slot = (int *)malloc(max_deadline * sizeof(int)); // Use int for bool
    for (i = 0; i < max_deadline; i++) {
        slot[i] = 0; // 0 represents a free slot (false)
    }

    int total_profit = 0;

    // Iterate through all given jobs
    for (i = 0; i < n; i++) {
        // Find a free slot for this job (starting from the last possible slot)
        for (k = jobs[i].deadline - 1; k >= 0; k--) {
            if (slot[k] == 0) {
                result[k] = jobs[i].id;
                slot[k] = 1; // 1 represents an occupied slot (true)
                total_profit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nSelected jobs in sequence: ");
    for (i = 0; i < max_deadline; i++) {
        if (slot[i])
            printf("%c ", result[i]);
    }

    printf("\nMaximum profit: %d\n", total_profit);

    // Free dynamically allocated memory
    free(result);
    free(slot);
}

int main(void) {
    int n, i;
    struct job *j;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of jobs.\n");
        return 1;
    }

    j = (struct job *)malloc(n * sizeof(struct job));
    for (i = 0; i < n; i++) {
        printf("Enter Job %d (ID Deadline Profit): ", i + 1);
        scanf(" %c %d %d", &j[i].id, &j[i].deadline, &j[i].profit);
    }

    jobseq(j, n);
    free(j);
    return 0;
}
