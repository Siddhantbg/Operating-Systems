#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5
#define ITEMS 10 // Total items to produce and consume

int buffer[SIZE], in = 0, out = 0; // Shared buffer, `in` and `out` indices
sem_t empty, full;                // Semaphores for empty and full slots
pthread_mutex_t mutex;            // Mutex for critical sections

void *producer(void *arg) {
    for (int i = 1; i <= ITEMS; i++) {
        sem_wait(&empty);               // Wait for an empty slot
        pthread_mutex_lock(&mutex);     // Lock the buffer for exclusive access
        buffer[in] = i;                 // Produce an item
        printf("Produced: %d\n", i);
        in = (in + 1) % SIZE;           // Move `in` pointer circularly
        pthread_mutex_unlock(&mutex);   // Unlock the buffer
        sem_post(&full);                // Signal a full slot
    }
    return NULL;
}

void *consumer(void *arg) {
    for (int i = 1; i <= ITEMS; i++) {
        sem_wait(&full);                // Wait for a full slot
        pthread_mutex_lock(&mutex);     // Lock the buffer for exclusive access
        int item = buffer[out];         // Consume an item
        printf("Consumed: %d\n", item);
        out = (out + 1) % SIZE;         // Move `out` pointer circularly
        pthread_mutex_unlock(&mutex);   // Unlock the buffer
        sem_post(&empty);               // Signal an empty slot
    }
    return NULL;
}

int main() {
    pthread_t prod, cons;               // Threads for producer and consumer
    sem_init(&empty, 0, SIZE);          // Initialize empty slots (SIZE)
    sem_init(&full, 0, 0);              // Initialize full slots (0)
    pthread_mutex_init(&mutex, NULL);   // Initialize mutex

    pthread_create(&prod, NULL, producer, NULL); // Create producer thread
    pthread_create(&cons, NULL, consumer, NULL); // Create consumer thread
    pthread_join(prod, NULL);           // Wait for producer to finish
    pthread_join(cons, NULL);           // Wait for consumer to finish

    sem_destroy(&empty);                // Destroy semaphore
    sem_destroy(&full);                 // Destroy semaphore
    pthread_mutex_destroy(&mutex);      // Destroy mutex

    return 0;
}
