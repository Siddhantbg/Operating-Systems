#include <stdio.h>
int main() {
    int n, frames;
    printf("Enter number of references and frames: ");
    scanf("%d %d", &n, &frames);

    int ref[n], f[frames], faults = 0, hits = 0;

    printf("Enter reference string: ");
    for (int i = 0; i < n; i++) scanf("%d", &ref[i]);

    for (int i = 0; i < frames; i++) f[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (f[j] == ref[i]) { 
                hits++; 
                found = 1; 
                break; 
            }
        }
        if (!found) {
            faults++;
            if (i < frames) {
                f[i] = ref[i];
            } else {
                int pos = -1, farthest = i;
                for (int j = 0; j < frames; j++) {
                    int k;
                    for (k = i + 1; k < n && f[j] != ref[k]; k++);
                    if (k > farthest) {
                        farthest = k;
                        pos = j;
                    }
                }
                f[pos == -1 ? 0 : pos] = ref[i];
            }
        }
    }

    printf("Faults: %d Hits: %d Fault Ratio: %.2f Hit Ratio: %.2f\n", 
           faults, hits, (float)faults / n, (float)hits / n);

    return 0;
}
