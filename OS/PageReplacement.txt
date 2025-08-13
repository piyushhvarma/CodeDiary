#include <stdio.h>

int main() {
    int ref[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(ref) / sizeof(ref[0]);
    int frames[3], front = 0, count = 0;

    for (int i = 0; i < 3; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < 3; j++) {
            if (frames[j] == ref[i]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            frames[front] = ref[i];
            front = (front + 1) % 3;
            count++;
        }

        printf("Step %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }

    printf("Total page faults = %d\n", count);
    return 0;
}
