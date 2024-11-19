#include <stdio.h>

int main() {
    int n, frames;
    printf("Enter number of references and frames: ");
    scanf("%d %d", &n, &frames);

    int ref[n], f[frames], time[frames], faults = 0, hits = 0, counter = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);

    for (int i = 0; i < frames; i++) f[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (f[j] == ref[i]) {
                hits++;
                time[j] = ++counter; // Update access time
                found = 1;
                break;
            }
        }
        if (!found) {
            faults++;
            int pos = 0, min = time[0];
            for (int j = 1; j < frames; j++) {
                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }
            f[pos] = ref[i];
            time[pos] = ++counter; // Update access time
        }
    }

    printf("Faults: %d Hits: %d Fault Ratio: %.2f Hit Ratio: %.2f\n", 
           faults, hits, (float)faults / n, (float)hits / n);

    return 0;
}
