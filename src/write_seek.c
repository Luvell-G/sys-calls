#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    const char *filename = "output_seek.txt";

    int fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    const char *msg1 = "ABCDEFGH\n";
    if (write(fd, msg1, strlen(msg1)) < 0) {
        perror("write msg1");
        close(fd);
        return 1;
    }

    // seek to position 3 (0-based): A=0, B=1, C=2, D=3
    if (lseek(fd, 3, SEEK_SET) < 0) {
        perror("lseek");
        close(fd);
        return 1;
    }

    const char *msg2 = "XXX";
    if (write(fd, msg2, strlen(msg2)) < 0) {
        perror("write msg2");
        close(fd);
        return 1;
    }

    close(fd);

    printf("Wrote file: %s\n", filename);
    printf("Now run: cat %s\n", filename);
    return 0;
}
