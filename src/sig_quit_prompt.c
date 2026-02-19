#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile sig_atomic_t got_sigint = 0;

void handle_sigint(int sig) {
    (void)sig;
    got_sigint = 1;  // set a flag, handle prompt in main loop
}

int main(void) {
    signal(SIGINT, handle_sigint);

    printf("Press Ctrl+C to trigger quit prompt.\n");

    while (1) {
        if (got_sigint) {
            got_sigint = 0;

            printf("\nReally quit? (y/n): ");
            fflush(stdout);

            int c = getchar();
            // consume rest of line
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) { }

            if (c == 'y' || c == 'Y') {
                printf("Exiting.\n");
                exit(0);
            } else {
                printf("Continuing...\n");
            }
        }

        // do “work”
        printf(".");
        fflush(stdout);
        sleep(1);
    }

    return 0;
}
