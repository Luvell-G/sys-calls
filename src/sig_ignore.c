#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    signal(SIGINT, SIG_IGN);   // ignore Ctrl+C
    printf("SIGINT ignored. Press Ctrl+C and I will NOT exit.\n");
    printf("Stop me using Ctrl+Z then kill, or from another terminal.\n");

    while (1) {
        pause(); // wait for signals (keeps CPU low)
    }
    return 0;
}
