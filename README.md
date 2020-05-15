# Operating Systems: Three Easy Pieces

## Learning opportunity

These include files on my summer 2020 goal of mastering my C programming skills while learning Operating Systems concepts.

### Learning C notes

- Header files: These are function and macro definitions that are included at the top of C files so that the compiler can import the contents in. These are similar to modules in Python where you can import different predefined functions. 
- Macro: These are string variables that define constants. You can define macros by using: #define identifier string. You can also do macros that expand to functions.
- int main(int argc, char *argv[]): 
    - argc: This is the number of arguments that are passed into your program from the command line
    - argv: is the array of arguments (string form).
- stdin, stdout, stderr: File handle in software engineering is where programs data is stored and fetched. By default these std files are displayed to the terminal, but they can be re-routed to other files. 
    - stdin: File handle that you process reads information from you
    - stdout: Your process writes information to the file
    - stderr: Process writes error information to this file
- Declaring a pointer: You don’t have to specify a type for a pointer (can be declared as a void* and then recast later), because to the machine all pointers occupy the same amount of memory. But it is standard to define the pointer type because it is useful to humans and to the compiler (which will perform error checking to ensure that the values that are defined match the pointer variable type).
- Memory allocation in C: They both return a pointer of the start of the memory allocation.
    - malloc: Stands for memory allocation, and it takes one argument which is the size of the variable type.
    - calloc: Stands for contiguous memory allocation, and it takes two arguments, one is the number of elements of that variable type, and the variable type. Compared to malloc, calloc will initialize this block of memory to zero first.
- Strings in C: Strings are considered an array of characters, which means that the characters are stored in memory contiguously. So we can refer to the string with a character pointer. Strings always contain a final nul character, to represent that the string has ended.
- volatile: This keyword will tell the compiler to ignore that variable from optimizations. For example, a possible optimization we might want to avoid the compiler storing the value of the variable and reusing that value throughout the program, but in reality the value of that variable might change (read up more on what I mean here: https://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/)
- Thread: A function running within the same memory space as other functions, with more than one active at a time.