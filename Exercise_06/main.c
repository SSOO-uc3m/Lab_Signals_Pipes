#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>  

int main (void)
{
    //char *file= "redirectionFile.txt";
    int myPipe[2]; 
    pid_t childLs, childWc;

    if (pipe(myPipe)< 0){
        perror("error pipe");
        exit(-1);
    }
	
    childLs = fork();
    
    if (childLs < 0){
        exit(-1);
    }
	
    if (childLs == 0 ) { // childLs process
    
		close(STDOUT_FILENO); 
		dup(myPipe[STDOUT_FILENO]); 
		close(myPipe[STDOUT_FILENO]); 
		close(myPipe[STDIN_FILENO]);
		
		execlp("ls", "ls",  NULL);
		exit(-1);
	}

    close(STDIN_FILENO); 
    dup(myPipe[STDIN_FILENO]); 
    close(myPipe[STDIN_FILENO]);
    close(myPipe[STDOUT_FILENO]);
    	
    childWc = fork();
	 
    if (childWc == 0) { 

        // redirection 
        // close(STDOUT_FILENO);
        //open(file,O_RDWR|O_CREAT,0660);
        //creat(file,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    	execlp("wc", "wc", NULL);
    	exit(-1);
     }
	 
    wait(NULL);
    wait(NULL);
	
    return 0 ;
}