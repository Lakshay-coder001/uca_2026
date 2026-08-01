#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define LOGFILE "audit.log"
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc < 2) {
        write(STDOUT_FILENO,
              "Usage:\n./auditlog --add \"message\"\n./auditlog --view\n",
              54);
        return 1;
    }

    if (strcmp(argv[1], "--add") == 0) {

        if (argc != 3) {
            write(STDOUT_FILENO, "Usage: ./auditlog --add \"message\"\n", 34);
            return 1;
        }

        int fd = open(LOGFILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) {
            perror("open");
            return 1;
        }

        write(fd, argv[2], strlen(argv[2]));
        write(fd, "\n", 1);

        close(fd);
    }

    else if (strcmp(argv[1], "--view") == 0) {

        int fd = open(LOGFILE, O_RDONLY);

        if (fd < 0) {
            perror("open");
            return 1;
        }

        char ch;
        int line = 1;
        char buffer[32];

        sprintf(buffer, "%d: ", line);
        write(STDOUT_FILENO, buffer, strlen(buffer));

        while (read(fd, &ch, 1) > 0) {

            write(STDOUT_FILENO, &ch, 1);

            if (ch == '\n') {
                line++;
                sprintf(buffer, "%d: ", line);
                write(STDOUT_FILENO, buffer, strlen(buffer));
            }
        }

        close(fd);
    }

    else {
        write(STDOUT_FILENO, "Invalid command\n", 16);
        return 1;
    }

    return 0;
}