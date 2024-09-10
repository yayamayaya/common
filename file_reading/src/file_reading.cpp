#include "file_reading.h"

int get_file_size(FILE *file);

int file_read(char **buff, int *file_size, const char *file_name)
{
    int size_of_file = 0;
    char *buffer = NULL;

    LOG("starting file reading:");
    FILE *file_to_read = fopen(file_name, "rb");
    if (!file_to_read)
    {
        LOG_ERR("couldn't open file to read, check the directory");
        return READ_FILE_OPN_ERR;
    }

    size_of_file = get_file_size(file_to_read);
    if (size_of_file == 0)
    {
        LOG_ERR("size of file is zero, check the file");
        fclose(file_to_read);
        return EMPTY_FILE_ERR;
    }
    LOG("size of file is: %d", size_of_file);    
        
    LOG("allocating memory:");
    buffer = (char *)calloc(size_of_file + 1, sizeof(char));
    if (!buffer)
    {
        LOG_ERR("couldn't allocate memory for buffer");
        fclose(file_to_read);
        return FILE_MEM_ALC_ERR;
    }

    int error = 0;
    LOG("memory alocated, reading file into the buffer");
    if ((int)fread(buffer, sizeof(char), size_of_file, file_to_read) < size_of_file)
    {
        LOG_ERR("file wasn't read fully");
        error = NOT_READ_FULLY;
    }
    LOG("file reading completed");

    *buff = buffer;
    if (file_size)
        *file_size = size_of_file;
    
    fclose(file_to_read);

    return error;
}

int get_file_size(FILE *file)
{
    int current_position = ftell(file);

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, current_position, SEEK_SET);

    return file_size;
}

