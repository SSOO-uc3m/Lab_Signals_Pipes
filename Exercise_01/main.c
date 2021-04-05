#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define SECONDS 5

void captureSignal (int s){
	  printf ("Singal %d recibed\n",s);
}

int main (){
    int pid;
    
    // We create a mask of signals to block during the handler
    struct sigaction act;
    act.sa_handler=captureSignal;
    act.sa_flags=0;
    sigemptyset(&(act.sa_mask)); // we create an empty set of signals

	
    pid = fork();
    if (pid != 0){
         sleep (SECONDS);
         kill (pid, SIGUSR1);
         exit(0);  
    }
    else { //child
         
         sigaction (SIGUSR1, &act,NULL); // we specify the action to perform for SIGUSR1
		 // we could also use 
		 // if (signal(SIGUSR1, captureSignal) == SIG_ERR) exit(-1);			
         pause(); // Blocks the child process until the signal is received, sleep (99999)
         exit(0);
    }
    
}