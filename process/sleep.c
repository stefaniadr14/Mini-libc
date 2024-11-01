#include <unistd.h>
#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>
#include <time.h>

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_nanosleep, req, rem);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return 0;
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req, rem;
    req.tv_sec = seconds;
    req.tv_nsec = 0;
    while (nanosleep(&req, &rem) != -1) {
        if (errno == EINTR) {
            req = rem;
        } else {
            return -1;
        }
    }

    return 0;
}
