#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filepath>" << std::endl;
        return 1;
    }

    const char* filepath = argv[1];
    int fd = open(filepath, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd < 0) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    int fd2 = dup(fd);
    if (fd2 < 0) {
        std::cerr << "Error duplicating file descriptor" << std::endl;
        close(fd);
        return 1;
    }

    write(fd, "first line\n", strlen("first line\n"));
    write(fd2, "second line\n", strlen("second line\n"));

    close(fd);
    close(fd2);
    return 0;
}
