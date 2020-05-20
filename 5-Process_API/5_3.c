#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h> /* Contains string manipulation functions like strcpy */
#include <sys/wait.h> /* Contains functionality for the waitpid()/wait() process functionality */

int main(int argc, char *argv[]) {
    printf("hello world (pid:%d\n)", (int) getpid());
    int rc = fork();
    
    if (rc < 0) { // failed to create a child process (fork)
        fprintf(stderr, "Fork Failed\n");
        exit(1);
    } else if (rc==0) { // successfully created a child process
        printf("hello, I am child (pid:%d\n)", (int) getpid());
        char *myargs[3]; // Declare an array of character vector (string) called myargs.
        // C string is a one dimensional character array and an array of C strings is a two dimensional character array
        myargs[0] = strdup("wc"); // The function strdup() is used to duplicate a string. It returns a pointer to null-terminated byte string.
        // wc - This is the wordcount program that we want to execute
        myargs[1] = strdup("5_3.c"); 
        myargs[2] = NULL; // NULL terminator - marks end of array

        execvp(myargs[0], myargs); // Execute a file (in this case wc)
        // myargs parameter = An array of character pointers to NULL-terminated strings. Your application must ensure that the last member of this array is a NULL pointer. These strings constitute the argument list available to the new process image. The value in argv[0] must point to a filename that's associated with the process being started. Neither argv nor the value in argv[0] can be NULL.
        printf("This shouldn't print out.");
    } else { // This is the flow for the parent process
        int rc_wait = wait(NULL);
        printf("Hello, I am parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0; // Common practice to return 0 from main, as the main function is defined to expect an int return.
}