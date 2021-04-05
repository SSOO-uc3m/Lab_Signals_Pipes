#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


// add function to capture the signal SIGSEGV

// execute de the dafault action of SIGSEGV


int main(void){
    int *p;
	
	// custom handler for SIGSEGV
	
	// check if there is an error installing the handler 
	
    printf ("I have already placed the handler\n");
    p=0;
    printf ("I am going to put a value in a pointer to which I have not reserved memory\n");
    *p=5; 
}