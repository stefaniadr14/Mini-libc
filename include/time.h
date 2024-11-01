#include <stdio.h>
#include <stdlib.h>

typedef long time_t;

struct tm {
    int tm_sec;     // seconds (0 - 60)
    int tm_min;     // minutes (0 - 59)
    int tm_hour;    // hours (0 - 23)
    int tm_mday;    // day of the month (1 - 31)
    int tm_mon;     // month (0 - 11)
    int tm_year;    // years since 1900
};

struct timespec {
    time_t tv_sec;        /* seconds */
    long   tv_nsec;       /* nanoseconds */
};

unsigned int sleep(unsigned int seconds);
int nanosleep(const struct timespec *req, struct timespec *rem);
