#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
/* this program waits 3 seconds for the user to press a number and if they don't, it stops waiting */

const int TIME=3;
const int nMax = 10;
const int nMin = 1;

int endTime = 0;

void alarmGoesOff (int s){
	  printf ("The alarm signal %d has arrived: \n",s);
	  endTime=1;
}

int main (){
    int n;   
    struct sigaction sa;
	sa.sa_handler = alarmGoesOff;
	sa.sa_flags=0;
	sigemptyset (&(sa.sa_mask));
	sigaction (SIGALRM, &sa, NULL);
	//if (signal(SIGALRM, alarmGoesOff) == SIG_ERR) exit(-1);

	alarm(TIME);
		printf ("Write  a number (you have got %d seconds) \n",TIME );
		scanf ("%d",&n);
		if (endTime){
			srand(time(0));
			n = rand()%((nMax+1)-nMin) + nMin;
			printf ("Time is up, the number will be %d\n",n );
		}		
		else {
			printf ("number %d has been read\n",n );
		}
	exit(0);
}
