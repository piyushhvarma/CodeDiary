#include <stdio.h>
#define M 5
#define P 4

void allocate(int blocks[], int m, int process[], int p, char* strategy) {
    int allocation[P], next = 0;
    for (int i = 0; i < p; i++) allocation[i] = -1;

    for (int i = 0; i < p; i++) {
        int best = -1;
        for (int j = 0; j < m; j++) {
            if (blocks[j] >= process[i]) {
                if (strcmp(strategy, "First") == 0) {
                    best = j;
                    break;
                } else if (strcmp(strategy, "Best") == 0) {
                    if (best == -1 || blocks[j] < blocks[best]) best = j;
                } else if (strcmp(strategy, "Worst") == 0) {
                    if (best == -1 || blocks[j] > blocks[best]) best = j;
                } else if (strcmp(strategy, "Next") == 0) {
                    int found = 0;
                    for (int k = next; k < m + next; k++) {
                        int idx = k % m;
                        if (blocks[idx] >= process[i]) {
                            best = idx;
                            next = (idx + 1) % m;
                            found = 1;
                            break;
                        }
                    }
                    if (!found) best = -1;
                    break;
                }
            }
        }
        if (best != -1) {
            allocation[i] = best;
            blocks[best] -= process[i];
        }
    }

    printf("%s Fit:\n", strategy);
    for (int i = 0; i < p; i++) {
        if (allocation[i] != -1)
            printf("P%d -> Block %d\n", i + 1, allocation[i] + 1);
        else
            printf("P%d -> Not Allocated\n", i + 1);
    }
    printf("\n");
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
    allocate(blocks, M, process, P, "First");
    int blocks1[] = {100, 500, 200, 300, 600};
    allocate(blocks1, M, process, P, "Next");
    int blocks2[] = {100, 500, 200, 300, 600};
    allocate(blocks2, M, process, P, "Best");
    int blocks3[] = {100, 500, 200, 300, 600};
    allocate(blocks3, M, process, P, "Worst");
    return 0;
}
