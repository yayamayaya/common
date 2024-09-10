#ifndef FILE_READING
#define FILE_READING

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

enum FILE_READING_ERRORS
{
    READ_FILE_OPN_ERR = 1313,
    EMPTY_FILE_ERR,
    FILE_MEM_ALC_ERR,
    NOT_READ_FULLY,
};

int file_read(char **buff, int *file_size, const char *file_name);

#endif