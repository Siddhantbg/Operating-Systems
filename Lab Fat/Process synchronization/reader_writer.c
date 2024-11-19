#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t rw_mutex, mutex;
int read_count = 0;

void *reader(void *arg) {
    sem_wait(&mutex);
    read_count++;
    if (read_count == 1) sem_wait(&rw_mutex);
    sem_post(&mutex);
    printf("Reader is reading\n");
    sem_wait(&mutex);
    read_count--;
    if (read_count == 0) sem_post(&rw_mutex);
    sem_post(&mutex);
    return NULL;
}

void *writer(void *arg) {
    sem_wait(&rw_mutex);
    printf("Writer is writing\n");
    sem_post(&rw_mutex);
    return NULL;
}

int main() {
    pthread_t r[3], w[2];
    sem_init(&rw_mutex, 0, 1);
    sem_init(&mutex, 0, 1);
    for (int i = 0; i < 3; i++) pthread_create(&r[i], NULL, reader, NULL);
    for (int i = 0; i < 2; i++) pthread_create(&w[i], NULL, writer, NULL);
    for (int i = 0; i < 3; i++) pthread_join(r[i], NULL);
    for (int i = 0; i < 2; i++) pthread_join(w[i], NULL);
    sem_destroy(&rw_mutex);
    sem_destroy(&mutex);
    return 0;
}
