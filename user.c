#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <getopt.h>


void childProcess(FILE *filePointer,int segmentId,time_t time, pid_t myPid){
	int pid=fork();
	if (pid==0){
			fprintf(filePointer,"Child Process Starts At: %ld\n", time);
			myPid=getpid();
			char *shmADDRESSS=shmat(segmentId,NULL,0);
				if (!shmADDRESSS){
					perror("shmat");
					exit(1);
				}
			sleep(2);
			fprintf(filePointer,"Child Process Terminates At: %ld\n",time);
			exit(1);
		}
}