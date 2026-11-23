*This project has been created as part
of the 42 curriculum by majnaou.*

# Get next line

This project implements a function called get_next_line() that reads and returns one line at a time from a file descriptor. Each call retrieves the next line until the end of the file is reached. The function must handle different buffer sizes and manage the data that remains between calls, While this my sound simple, there are several complexities tha make this a challenging and engaging project.

## Instructions

```bash 
- git clone git@vogsphere-v2.1337.ma:vogsphere/intra-uuid-0f541aaf-5736-4566-95aa-15c327cc64ed-7817493-majnaou get_next_line
- cd git_next_line
for mendatory part :


    - add this to your main.c file : #include "get_next_line.h"
    - cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -o program
    - ./program
for bonus part :
    - add this to your main.c file : #include "get_next_line_bonus.h"
    - cc -Wall -Wextra -Werror main.c get_next_line_bonus.c get_next_line_utils_bonus -o program
    - ./program 
```

## Resources

- [Handling a File by its Descriptor in C](https://www.codequoi.com/en/handling-a-file-by-its-descriptor-in-c/)
- [Local, Global and Static Variables in C](https://www.codequoi.com/en/local-global-static-variables-in-c/)
- [Medium article about gnl](https://medium.com/@ayogun/master-file-i-o-operations-with-42s-get-next-line-project-5fb001d1fff5)

## AI usage
- I use AI to find information quickly, but understanding the concepts and debugging the code are my own responsibilities.

## chosen algorithm

I use a buffered reading algorithm. I read the file by chunks of BUFFER_SIZE, store the data in a saved stash, search for the newline delimiter, return one line, and keep the remaining data for the next call.

#### example
``` c
Suppose BUFFER_SIZE = 10 and the file contains: "hello\nworld\n"
first call
read() → "Hello\nWorl"
             ↓
           stash
             ↓
        return "Hello\n"

    teh stash still contains "wordl"
    when you call get_next_line() again :
        stash = "Worl"
             ↓
        read() → "d\n"
            ↓
         stash = "World\n"
             ↓
        return "World\n"

So the iportandt idea is :
The stash remembers the data that belongs to the next line.
```
## Bonus

The bonus version allows get_next_line() to handle multiple file descriptors at the same time.

Each file descriptor keeps its own remaining data, so reading from one file descriptor does not affect the others