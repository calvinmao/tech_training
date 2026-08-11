/*
 * 1-2 GCC : an infinite-loop process for observing GCC stages and process life.
 *
 *   gcc -E loop.c -o loop.i   # Preprocess
 *   gcc -S loop.i -o loop.s   # Compile to assembly
 *   gcc -c loop.s -o loop.o   # Assemble to object
 *   gcc loop.o -o loop        # Link to final ELF
 *
 *   ./loop &                  # run in background, note the PID
 *   top -p <pid>              # watch it burn CPU; press q to exit
 *   kill <pid>                # stop it
 */
#define LOOP 1

int main(void)
{
    while (LOOP)
        ;
}
