#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[]) {

    // Open a file using the stdio.h library
    FILE *file = fopen("./2.txt", "w+");

    int child_proc = fork();

    /* 
    For the child process, the return value of fork() is either -1 (fail) or 0 (success)
    For the parent process, the return value of fork() is the PID of the child process.
    */


    if (child_proc < 0 ) { // Handle the case where there is a child process (fork) failure
        printf("Failure to create child process with return code: %d", child_proc);
        exit(1);
    } else if (child_proc == 0) { // Successfully created a child process
        fprintf(file, "This is the child process writing: %d. \n", (int) getpid());
        printf("Successfully wrote to the file from the child process: %d. \n", (int) getpid());
    } else { // The parent process will return here
        int child_proc_wait = wait(NULL);
        printf("Return of the child process wait command: %d. \n", child_proc_wait);
        fprintf(file, "This is the parent process writing: %d. \n", (int) getpid());
    }

    return 0;
}