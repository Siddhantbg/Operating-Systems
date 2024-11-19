#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("Enter Size:\n");
    int size;
    scanf("%d", &size);

    int arr[size];
    for (int i = 0; i < size; i++) {
        printf("Enter Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Creating child process....\n");
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child Started\n");
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        printf("Sum of array elements: %d\n", sum);
        printf("Child process exiting.\n");
        _exit(0); // Terminate child process
    } else {
        // Parent process
        printf("Parent waiting for child to complete...\n");
        wait(NULL); // Wait for child process
        printf("Child process finished.\n");
        printf("Parent process resuming execution.\n");
    }

    return 0;
}
