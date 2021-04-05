#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main () {
        int             fd[2];
        pid_t           pid_hijo;
        // We establish the pipe
 
        pipe (fd);
        if ((pid_hijo = fork ())== -1) {
                perror ("fork");   exit (1);
        }
        if (pid_hijo == 0 ) { /* el hijo */
        //  I change the standard outlet for the pipe 
			dup2 (fd[1],1);
			close (fd[0]);
        // writer writes over the standard output, which will be the pipe 
			execlp ("../Exercise_07_writer/writer", "../Exercise_07_writer/writer", NULL);
			exit(-1);
        }
        else { /* father*/
        //  I change the standard input for the pipe 
                dup2 ( fd[0],0);
                close (fd[1]);
        // reader reads from standard input, which will be the pipe 
                execlp ("../Exercise_07_reader/reader", "../Exercise_07_reader/reader", NULL);
				exit(-1);
        }
}
