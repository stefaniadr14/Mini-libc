// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
    // Copy each character from source to destination
	int i;
	for (i = 0; source[i] != '\0'; i++) {
		destination[i] = source[i];
	}
	destination[i] = '\0';
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
    // Copying the first len characters from source to destination
	int i;
	for (i = 0; i < (int)len; i++) {
		destination[i] = source[i];
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
    // Moving to the end of destination
    while (*destination) {
        destination++;
    }
    // Copying the source at the end
    while (*source) {
        *destination = *source;
        destination++;
        source++;
    }
    // Setting the new end for destination
    *destination = '\0';
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
    while (*destination) {
        destination++;
    }
    while (*source && len > 0) {
        *destination = *source;
        destination++;
        source++;
		len--;
    }
    *destination = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    if (*str1 == '\0' && *str2 == '\0') {
        return 0;  // strings are equal
    } else if (*str1 < *str2) {
        return -1; // str1 is less than str2
    } else {
        return 1;  // str1 is greater than str2
    }
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len > 0 && *str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
        len--;
    }
    if (len == 0 || (*str1 == '\0' && *str2 == '\0')) {
        return 0;  // strings are equal up to len characters
    } else if (*str1 < *str2) {
        return -1; // str1 is less than str2
    } else {
        return 1;  // str1 is greater than str2
    }
}


size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	int i;
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == c)
			return (char *)&str[i];
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	int i;
	for (i = strlen(str) - 1; i > 0; i--) {
		if (str[i] == c)
			return (char *)&str[i];
	}
	return NULL;
}

char *strstr(const char *haystack, const char *needle)
{
    int i, j;
    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;
        // Verify if needle string is found
        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }
        if (needle[j] == '\0') {
            return (char *)&haystack[i];
        }
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
    int i, j;
    int last = -1;

    for (i = 0; haystack[i] != '\0'; i++) {
        j = 0;

        while (needle[j] != '\0' && haystack[i + j] == needle[j]) {
            j++;
        }

        if (needle[j] == '\0') {
            last = i;
        }
    }

    if (last >= 0) {
        return (char *)&haystack[last];
    } else {
        return NULL;
    }
}

void *memcpy(void *destination, const void *source, size_t num)
{
    char *dst = (char *)destination;
    const char *src = (const char *)source;

    while (num > 0) {
        *dst = *src;
        dst++;
        src++;
        num--;
    }

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
    char *dst = (char *)destination;
    const char *src = (const char *)source;

    if (dst < src) {
        while (num > 0) {
            *dst = *src;
            dst++;
            src++;
            num--;
        }
    } else if (dst > src) {
        dst += num;
        src += num;
        while (num > 0) {
            dst--;
            src--;
            *dst = *src;
            num--;
        }
    }

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
    const unsigned char *p1 = (const unsigned char *)ptr1;
    const unsigned char *p2 = (const unsigned char *)ptr2;

    while (num > 0) {
        if (*p1 != *p2) {
            return *p1 - *p2;
        }
        p1++;
        p2++;
        num--;
    }

    return 0;
}

void *memset(void *source, int value, size_t num)
{
    unsigned char *src = (unsigned char *)source;
    unsigned char val = (unsigned char)value;

    while (num > 0) {
        *src = val;
        src++;
        num--;
    }

	return source;
}
