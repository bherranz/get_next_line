# get_next_line
A project that implements a function capable of reading and returning one line at a time from a file descriptor.  
It must handle reading from files, standard input, and other streams, managing internal memory correctly between calls, and working efficiently with multiple file descriptors.

The goal is to practice file reading in C, buffer management, and persistent state handling between function calls.

## ✅ Features

- Reads a file line by line, each time the function is called
- Manages memory efficiently
- Supports multiple file descriptors at the same time (bonus)
- Handles lines of any length
- Complies with the 42 coding standard

## 🔧 Function Prototype

```c
char *get_next_line(int fd);
````

## 📁 Files
  - get_next_line.c – main logic to read and extract lines
  - get_next_line_utils.c – helper functions (string length, join, etc.)
  - get_next_line.h – header file with includes and prototype

Bonus:
  - get_next_line_bonus.c – bonus version with multi-FD support
  - get_next_line_utils_bonus.c – helper functions for bonus version

## 🧪 Usage
### 1. Clone the repo:
````bash
git clone https://github.com/your-username/get_next_line.git
cd get_next_line
````
### 2. Compile:
````bash
make
````
### Example:
````c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
````
## ⚙️ Buffer Size
The behavior of the function depends on the BUFFER_SIZE macro defined at compile time.
You can define it like this:

````bash
gcc -D BUFFER_SIZE=32 main.c get_next_line.c get_next_line_utils.c
````
## 💡 What I Learned
- Reading from file descriptors using read()
- Handling dynamic memory allocation and freeing properly
- Managing persistent static variables
- Working with buffers and custom string manipulation
- Implementing a function that behaves like a state machine

## 🧠 Bonus
- Support for multiple file descriptors simultaneously
- No memory leaks or undefined behavior
- Robust error handling



