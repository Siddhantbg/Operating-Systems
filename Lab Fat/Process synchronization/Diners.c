#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t chopstick[N];

void *philosopher(void *num) {
    int id = *(int *)num;
    sem_wait(&chopstick[id]);
    sem_wait(&chopstick[(id + 1) % N]);
    printf("Philosopher %d is eating\n", id);
    sem_post(&chopstick[id]);
    sem_post(&chopstick[(id + 1) % N]);
    printf("Philosopher %d is thinking\n", id);
    return NULL;
}

int main() {
    pthread_t phil[N];
    int id[N];
    for (int i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
        id[i] = i;
    }
    for (int i = 0; i < N; i++)
        pthread_create(&phil[i], NULL, philosopher, &id[i]);
    for (int i = 0; i < N; i++)
        pthread_join(phil[i], NULL);
    for (int i = 0; i < N; i++)
        sem_destroy(&chopstick[i]);
    return 0;
}
