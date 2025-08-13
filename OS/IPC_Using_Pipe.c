#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], "Hi", 3);
        close(fd[1]);
    } else {
        close(fd[1]);
        char buffer[10];
        read(fd[0], buffer, 10);
        printf("Parent got: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}
