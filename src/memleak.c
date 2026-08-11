#define _DEFAULT_SOURCE   /* expose usleep() prototype */
/*
 * 1-4 MM : a deliberate memory leak that will be killed by the OOM Killer.
 *
 * It keeps calling malloc() without free(), so memory is drained until the
 * kernel steps in with SIGKILL. Watch the resident size climb in `top`.
 *
 * WARNING: this process WILL be killed by the kernel. Run it on a machine
 * where that is acceptable (e.g. a lab VM), not a shared production host.
 *
 *   ./memleak
 *   top -p <pid>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define CHUNK 100           /* KiB allocated (and touched) each iteration */
#define CHUNK_BYTES (CHUNK * 1024)

int main(void)
{
    int loop_count = 0;

    while (1) {
        char *ptr = (char *)malloc(CHUNK_BYTES);
        for (int i = 0; i < CHUNK_BYTES; i++) {
            ptr[i] = 'A';
        }
        loop_count++;
        if (loop_count % 1024 == 0) {
            printf("Leaked: %d00 MB total\n", loop_count / 1024);
            fflush(stdout);
        }
        usleep(1000);
    }

    return 0;   /* never reached */
}
