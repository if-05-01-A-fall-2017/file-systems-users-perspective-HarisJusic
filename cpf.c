#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 
#include <fcntl.h>

int main(int argc, char* argv[]) {

	int src_fd, dst_fd;
	int n, checkError;
    unsigned char buffer[4096];
    char * srcPath, dstPath;

    if (argc != 3) {
        printf("Wrong arguments.\n");
        exit(1);
    }

    srcPath = argv[1];
    dstPath = argv[2];

    src_fd = open(srcPath, O_RDONLY);
    dst_fd = open(dstPath, O_CREAT | O_WRONLY);

    while (1) {
        checkError = read(src_fd, buffer, 4096);
        if (checkError == -1) {
            printf("Couldn't read file.\n");
            exit(1);
        }
        n = checkError;
        if (n == 0) 
			break;
        checkError = write(dst_fd, buffer, n);
        if (checkError == -1) {
            printf("Couldn't write to file.\n");
            exit(1);
        }
    }

    close(src_fd);
    close(dst_fd);
}
