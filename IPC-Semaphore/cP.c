#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/ipc.h>


int main(void){
	
	printf("ДЕТАЛИ C\n");
	int c=0;
	struct sembuf arr[1];
	
	key_t key=ftok("abc",'s');
	int semid=semget(key,4,0666| IPC_CREAT);
	
	arr[0].sem_num=2;
	arr[0].sem_flg=0;
	
	while(1){
		
		arr[0].sem_op=1;
		semop(semid,arr,1);
		printf("\r%d",++c);
		fflush(stdout);
		sleep(4);
		
	}
	
	return 0;
}
