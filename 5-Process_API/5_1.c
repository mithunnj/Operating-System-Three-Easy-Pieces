#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> /* Module that contains the sleep function */

int main(int arfc, char *argv[]) {
    printf("hello world (pid:%d)\n", (int) getpid()); /* Cast pid as int because the return type of getpid() is type: pid_t*/

    int rc = fork();

    /* At the fork call, the parent process gets a return > 0, and so it goes directly to the else statement.
    The child process, continues on from the fork function call in it's own process, and it recieves a return of 0,
    which refers to the else if call. However, this behavious is not deterministic, and it is possible that the CPU handles the order
    of the parent and child processes running in a different order with this implementation. */

    if (rc < 0) { /* Failure to create a process */
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc ==0) { /* Successfully created a process. */
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        printf("hello, I am parent of %d (pid:%d)\n", rc, (int) getpid());
    }
    return 0;
}