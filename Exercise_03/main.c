#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

struct timeval  start;

#define SECONDS_WAIT_1 10
#define SECONDS_WAIT_2 3

// add function to capture the signal SIGUSR1

// print time passed

// add function to capture the signal SIGCHLD

// print time passed



int main (){
	
	// create two mask of signals add a custom handler

	// create a child process

	// child wait SECONDS_WAIT_1
	
	// child send SIGUSR1 signal to his parent
	
	// child wait SECONDS_WAIT_2

	// parent create a mask of signals to capture SIGUSR1 during the handler and an empty set of signals


	// parent create a mask of signals to capture SIGCHLD during the handler and an empty set of signals

	// parent blocked until a signal is received (SIGUSR1)

	// parent blocked until the signal is received (SIGCHLD)


}