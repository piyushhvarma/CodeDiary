#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) return 1;
    write(fd, "Hello OS\n", 9);
    lseek(fd, 0, SEEK_SET);
    close(fd);
    return 0;
}
