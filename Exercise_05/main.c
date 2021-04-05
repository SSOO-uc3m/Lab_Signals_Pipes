#include <signal.h>
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h> 

#define ALARM_TIME 3

void alarmGoesOff(int signal) {

	printf("Alarm %d \n", signal);
 
} 
 
 int main() {

 for(;;){
	if (signal(SIGALRM, alarmGoesOff) == SIG_ERR) {
		perror("Error while installing a SIGALRM handler.\n");
		exit(-1);	
	}
	alarm(ALARM_TIME);           /* start the timer */ 
	pause();            /* next caught signal wakes us up */ 
	} 
 }