#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int data=0, readcount=0;
pthread_mutex_t rc_mtx = PTHREAD_MUTEX_INITIALIZER; // protects readcount
sem_t rw_mutex; // writers lock, also blocks readers when a writer active

void* reader(void* arg){
    long id=(long)arg;
    for(int k=0;k<3;k++){
        pthread_mutex_lock(&rc_mtx);
        readcount++;
        if(readcount==1) sem_wait(&rw_mutex); // first reader locks writers
        pthread_mutex_unlock(&rc_mtx);

        printf("Reader %ld reads %d\n", id, data);
        usleep(10000);

        pthread_mutex_lock(&rc_mtx);
        readcount--;
        if(readcount==0) sem_post(&rw_mutex); // last reader unlocks
        pthread_mutex_unlock(&rc_mtx);
    }
    return NULL;
}
void* writer(void* arg){
    long id=(long)arg;
    for(int k=0;k<3;k++){
        sem_wait(&rw_mutex);
        data++;
        printf("  Writer %ld writes %d\n", id, data);
        usleep(12000);
        sem_post(&rw_mutex);
    }
    return NULL;
}
int main(){
    sem_init(&rw_mutex,0,1);
    pthread_t r[3], w[2];
    for(long i=0;i<3;i++) pthread_create(&r[i],NULL,reader,(void*)(i+1));
    for(long j=0;j<2;j++) pthread_create(&w[j],NULL,writer,(void*)(j+1));
    for(int i=0;i<3;i++) pthread_join(r[i],NULL);
    for(int j=0;j<2;j++) pthread_join(w[j],NULL);
    sem_destroy(&rw_mutex);
    return 0;
}
