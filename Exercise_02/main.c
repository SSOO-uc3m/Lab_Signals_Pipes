#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void captureSignal(int segnal){
    printf("An error occurred due to an attempt to improperly occupy memory\n");
    signal(SIGSEGV,SIG_DFL);
}

int main(void){
    int *p;
	
	if (signal(SIGSEGV, captureSignal) == SIG_ERR) {
		perror("Error while installing a SIGSEGV handler.\n");
		exit(-1);	
	}
    printf ("I have already placed the handler\n");
    p=0;
    printf ("I am going to put a value in a pointer to which I have not reserved memory\n");
    *p=5; 
}