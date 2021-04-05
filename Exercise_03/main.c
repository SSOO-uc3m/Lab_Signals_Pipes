#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

struct timeval  start;

#define SECONDS_WAIT_1 10
#define SECONDS_WAIT_2 3
#define MICROSECONDS 1000.0

void captureSignal (int s){
	  struct timeval  end;
	  gettimeofday(&end, NULL);
	  printf ("The signal %d recibed\n",s);
	  printf ("Total time = %f seconds\n",
         (double) (end.tv_usec - start.tv_usec) / 1000000 +
         (double) (end.tv_sec - start.tv_sec));
}
void childDeath (int s){
	  struct timeval  end;
	  gettimeofday(&end, NULL);
	  printf ("The son has finished: %d\n",s);
	  printf ("Total time = %f seconds\n",
         (double) (end.tv_usec - start.tv_usec) / 1000000 +
         (double) (end.tv_sec - start.tv_sec));
}
int main (){
	struct sigaction sa1,sa2;
	gettimeofday(&start, NULL);

	if (fork() == 0){    // child	  
      sleep (SECONDS_WAIT_1);
      kill ( getppid(), SIGUSR1);	
      sleep(SECONDS_WAIT_2);
	}
	else { // father
		sa1.sa_handler=captureSignal;
		sa1.sa_flags=0;
		sigemptyset(&(sa1.sa_mask));
		sigaction (SIGUSR1, &sa1,NULL);

		sa2.sa_handler=childDeath;
		sa2.sa_flags=0;
		sigemptyset(&(sa2.sa_mask));
		sigaction (SIGCHLD, &sa2,NULL);


		pause(); // == sleep(999999)
		pause(); // == sleep(999999)
  }
}