#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // check if the usage is right
    if (argc != 2)
    {
        printf("Usage : ./recover image\n");
        return 1;
    }
    // open file in mode read
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("file can't be read \n");
        return 1;
    }

    // define variables
    int count = 0;
    char filename[8];
    BYTE buffer[512];
    FILE *img = NULL;

    // loop to the end of the file
    while (fread(buffer, 512, 1, file) == 1)
    {

        // ckeck if it is jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // check if first file if not close it
            if (count != 0)
            {
                fclose(img);
            }
            sprintf(filename, "%03i.jpg", count);
            img = fopen(filename, "w");
            count++;
        }
        if (count != 0)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    fclose(file);
    fclose(img);

    return 0;
}