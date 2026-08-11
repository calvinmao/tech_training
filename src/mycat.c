/*
 * 1-3 FD : a simplified `cat` built only on the four basic syscalls.
 *
 *   open()   -> get an FD for the file
 *   read()   -> pull bytes into a buffer, looping until EOF
 *   write()  -> push those bytes to STDOUT (FD 1)
 *   close()  -> release the FD
 *
 * Usage:
 *   ./mycat <file>
 */
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    if (argc < 2)
        return 1;

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return 1;

    char buffer[BUF_SIZE];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);
    return 0;
}
