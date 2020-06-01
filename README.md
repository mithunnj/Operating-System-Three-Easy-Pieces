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
- Summary of what an OS is:
    - Takes physical resources, such as CPU, memory or disk, and virtualizes them.
    - It handles multiple tasks through a concept called concurrency.
    - It stores files persistently, thus making them safe over the long-term.
- Brief intro on how OS’s apply protection: A user application typically runs in user mode, where the hardware restricts what the applications can do like: I/O request to the disk, access any physical memory, etc.
    - A great explanation of what happens when the OS raises the hardware privilege level to the user mode process can be found on pg.15
- CPU: This piece of hardware consists of several components including the processor, the memory unit, ALU, etc. These days, a CPU can contain multiple processors.
- Process: A running program. A program is initially in the form of an executable and to turn it into a running program, things have to happen. The OS does the following to start a process:
    - Load the program into memory.
    - Allocate some resources to the program
    - Schedule the process to run on the CPU
        - The OS virtualizes the CPU to allow for many processes to run simultaneously.
- We can describe a process by the following:
    - Contents of memory in the program’s address space, the contents of the CPU’s registers including the program counter and stack pointer.
    - Process API
    - Process state
    - Data structure that contains the information for a specific process called the process control block.
- Handling restricted operations when running processes on the CPU:
    - User mode: Can’t issue I/O requests, very restricted
    - Kernel mode: Higher level access, where the code can do what it likes including I/O, and other restricted requests.
    - System calls allow the kernel to expose specific commands to allow a user process to access more privileged commands.
        - Trap & return-trap calls to jump into and out of kernel mode.
- Mechanisms for handling multiple processes:
    - Trap tables: A store of specific places to jump into the kernel when a user mode process wants to enter privileged kernel mode and access the OS -> ex. when performing I/O operations.
    - Timer interrupts: When the OS gives control of the CPU to a process, this timeout will ensure that the OS doesn’t permanently lose control due to a rebel process.
        - Interesting that the OS actually gives away it’s control to the CPU (for a single processor architecture).
    - Context switch: Switching processes.

