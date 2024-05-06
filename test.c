#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING  0
#define LEFT (phnum+4)%N
#define RIGHT (phnum+1)%N

int state[N];
int philosophers[] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

int check_availability(int phnum) {
    if (state[phnum] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        state[phnum] = EATING;
        sleep(2);

        printf("Philosopher %d picks up chopstick %d and %d and starts eating.\n", phnum+1, LEFT+1, phnum+1);

        sem_post(&S[phnum]);
    }
}

void take_chopstick(int phnum) {
    sem_wait(&mutex);
    state[phnum] = HUNGRY;

    printf("Philosopher %d is hungry.", phnum+1);
    check_availability(phnum);

    sem_post(&mutex);
    sem_wait(&S[phnum]);
    sleep(1);
}

void drop_chopstick(int phnum) {
    sem_wait(&mutex);
    state[phnum] = THINKING;

    printf("Philosopher %d is putting chopsticks %d and %d down and is now thinking.\n", phnum+1, LEFT+1, phnum+1);

    check_availability(LEFT);
    check_availability(RIGHT);

    sem_post(&mutex);
}

void *init(void *num) {
    printf("hello2");
    while(1) {
        int *i = num;
        sleep(1);
        take_chopstick(*i);
        sleep(0);
        drop_chopstick(*i);
    }
}

int main(void) {
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);

    for (int i = 0; i < N; i++) {
        sem_init(&S[i], 0, 0);
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, init, &philosophers[i]);
    }

	for (i = 0; i < N; i++)
 		pthread_join(thread_id[i], NULL);
}
