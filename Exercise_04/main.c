#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* this program waits 3 seconds for the user to press a number and if they don't, it stops waiting */

const int TIME=3;
const int nMax = 10;
const int nMin = 1;

bool endTime = false;

// add function to capture the signal SIGALRM
// endTime flag put to true



int main (){
    int n;   

	
	// create a mask of signals to block during the handler
    
    // create an empty set of signals
	
	// set ALARM for TIME seconds
	
	//if (signal(SIGALRM, alarmGoesOff) == SIG_ERR) exit(-1);

	// ask a number to the user
	
	// if endTime is true, n will have a random value
	
	// print the number read
	
	exit(0);
}
