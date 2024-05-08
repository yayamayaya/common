#include "file_reading.h"

_INIT_LOG();

int get_file_size(FILE *file);

int file_read(char **buff, int *file_size, const char *file_name)
{
    _OPEN_LOG("logs/file_reading.log");

    int size_of_file = 0;
    char *buffer = NULL;

    LOG("> starting file reading:\n");
    FILE *file_to_read = fopen(file_name, "rb");
    if (!file_to_read)
    {
        LOG("[error]>>> couldn't open file to read, check the directory\n");
        return READ_FILE_OPN_ERR;
    }

    size_of_file = get_file_size(file_to_read);
    if (file_size == 0)
    {
        LOG("[error]>>> size of file is zero, check the file\n");
        fclose(file_to_read);
        _CLOSE_LOG();
        return EMPTY_FILE_ERR;
    }
    LOG("> size of file is: %d\n", size_of_file);    
        
    LOG("> allocating memory:\n");
    buffer = (char *)calloc(size_of_file + 1, sizeof(char));
    if (!buffer)
    {
        LOG("[error]>>> couldn't allocate memory for buffer\n");
        fclose(file_to_read);
        _CLOSE_LOG();
        return FILE_MEM_ALC_ERR;
    }

    int error = 0;
    LOG("> memory alocated, reading file into the buffer\n");
    if ((int)fread(buffer, sizeof(char), size_of_file, file_to_read) < size_of_file)
    {
        LOG("[error]>>> file wasn't read fully\n");
        error = NOT_READ_FULLY;
    }
    LOG("> file reading completed\n");

    *buff = buffer;
    if (file_size)
        *file_size = size_of_file;
    
    fclose(file_to_read);
    _CLOSE_LOG();

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

