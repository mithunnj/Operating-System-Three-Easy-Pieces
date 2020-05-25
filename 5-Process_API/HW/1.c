#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h> // Includes process wait functionality.
#include <unistd.h> // Includes function definition for fork()

/* In this excercise it is apparent that the child process is a copy of this program, and gets access
to it's own instances of the variables from this program.

The results: 
- Child process: x = 101
- Parent process: x = 102

I expected:
- Child process: x = 101
- Parent process: x = 103
*/

int main(int argc, char *argv[]) {

    int x = 100; // Initialize initial variable for manipulation

    int child_proc = fork();
    /* On success, the PID of the child process is returned in the parent, and
   0 is returned in the child.  On failure, -1 is returned in the  parent,
   no child process is created, and errno is set appropriately. */

    if (child_proc < 0) { // Failure to create child process event.
        printf("Failed to create child process. \n");
        exit(1);
    } else if (child_proc == 0) { // Succesfully created a child process
        ++x; // Increment the variable
        printf("The value of x is: %d, for the child process: %d, with return code: %d. \n", x, (int) getpid(), child_proc);
    } else { // Handle the parent process
        int child_proc_wait = wait(NULL); // This will return the PID of the child process. 
        x = x + 2;
        printf("The value of x is: %d, for the parent process: %d. Return of wait() was: %d. \n", x, (int) getpid(), child_proc_wait);
    }

    return 0;
}