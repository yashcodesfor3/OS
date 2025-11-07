#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5

int buf[N], in=0, out=0;
sem_t emptySlots, fullSlots;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* producer(void* arg){
    for(int i=1;i<=10;i++){
        sem_wait(&emptySlots);
        pthread_mutex_lock(&mtx);
        buf[in]=i; in=(in+1)%N;
        printf("Produced %d\n", i);
        pthread_mutex_unlock(&mtx);
        sem_post(&fullSlots);
    }
    return NULL;
}
void* consumer(void* arg){
    for(int k=1;k<=10;k++){
        sem_wait(&fullSlots);
        pthread_mutex_lock(&mtx);
        int x=buf[out]; out=(out+1)%N;
        printf("  Consumed %d\n", x);
        pthread_mutex_unlock(&mtx);
        sem_post(&emptySlots);
    }
    return NULL;
}
int main(){
    pthread_t p,c;
    sem_init(&emptySlots,0,N);
    sem_init(&fullSlots,0,0);
    pthread_create(&p,NULL,producer,NULL);
    pthread_create(&c,NULL,consumer,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    sem_destroy(&emptySlots); sem_destroy(&fullSlots);
    return 0;
}
