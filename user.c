#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <getopt.h>


void childProcess(FILE *filePointer,int segmentId,pid_t myPid){

	
		time_t seconds;
		int pid=fork();
		if (pid==0){
				time(&seconds);
				myPid=getpid();
				fprintf(filePointer,"Master: Starting Child Process\n");				
				fprintf(filePointer,"Master: Child PID: %jd Starting At: %s\n", (_intmax_t)myPid,ctime(&seconds));
				char *shmADDRESSS=shmat(segmentId,NULL,0);
					if (!shmADDRESSS){
						perror("shmat");
						exit(1);
					}
				sleep(2);
				time(&seconds);
				fprintf(filePointer,"Master: Child PID: %jd Terminates At: %s\n\n\n\n", (_intmax_t)myPid,ctime(&seconds));
				exit(1);
			}
		
}
