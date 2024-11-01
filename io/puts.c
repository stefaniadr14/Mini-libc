#include <stdio.h>
#include <unistd.h>
#include <string.h>

int puts(const char *str) {
    if (str) {
        write(1, str, strlen(str));  // Write the string to standard output
        write(1, "\n", 1);  // Write a newline character
        return 1;  // Indicates successful execution
    } else {
        return -1;  // Indicates an error
    }
}
