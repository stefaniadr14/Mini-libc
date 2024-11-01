// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
    int ret = syscall(__NR_fstat, fd, st);
    if (ret < 0) {
        errno = -ret;
		if (errno == ENOENT) {
			return -1;
		} else if (errno == EISDIR) {
			return -1;
		} else if (errno == EROFS) {
			return -1;
		} else {
			return -1;
		}
    }
    return ret;
}
