#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>  

int main ()
{
    
    int myPipe[2]; 
    pid_t childLs, childWc;

     // establish the pipe 
		
	// create the child process	childLs    
	
    // childLs process  changed the standard outlet for the pipe 
	
	// childLs execute ls command    

    // parent process  changed the standard input for the pipe 

	// create the child process	childWc

	// childWc execute wc command    
	
	// parent process wait for both childs to finish
    
	
    return 0 ;
}