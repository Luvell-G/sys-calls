#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    int fd = open("dup2_out.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    if (dup2(fd, STDOUT_FILENO) < 0) {
        perror("dup2");
        close(fd);
        return 1;
    }

    // fd no longer needed after dup2 (stdout now points to file)
    close(fd);

    printf("This text should be inside dup2_out.txt\n");
    printf("Another line redirected to file.\n");

    return 0;
}
