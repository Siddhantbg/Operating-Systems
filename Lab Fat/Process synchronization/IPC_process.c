#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <unistd.h>   // For fork()
#include <sys/wait.h> // For wait()

int main() {
    key_t key = 1234; // Unique key for shared memory
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT); // Get shared memory ID
    char *str = (char *)shmat(shmid, (void *)0, 0);  // Attach shared memory

    if (fork() == 0) {  // Child Process
        strcpy(str, "Hello from child!"); // Write to shared memory
        printf("Child wrote: %s\n", str); // Print what was written
    } else {            // Parent Process
        wait(NULL);      // Wait for child process to finish
        printf("Parent read: %s\n", str); // Read from shared memory
        shmctl(shmid, IPC_RMID, NULL);    // Remove shared memory
    }
    return 0;
}
