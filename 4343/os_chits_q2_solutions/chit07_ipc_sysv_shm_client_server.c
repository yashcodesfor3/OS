#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

#define SHMSZ 1024

int main(){
    key_t key = ftok(".", 'S');
    int shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
    if(shmid<0){ perror("shmget"); return 1; }
    char *data = (char*) shmat(shmid, NULL, 0);
    if(data==(char*)-1){ perror("shmat"); return 1; }
    pid_t pid=fork();
    if(pid==0){
        // Client
        sleep(1);
        printf("Client read: %s\n", data);
        strcpy(data, "ACK from client");
        _exit(0);
    }else{
        // Server
        strcpy(data, "Hello from server via SHM");
        wait(NULL);
        printf("Server sees: %s\n", data);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
