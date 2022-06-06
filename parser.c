#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *input = fopen("input.txt", "r");
    FILE *ints = fopen("ints.txt", "w+");
    FILE *chars = fopen("chars.txt", "w+");
    FILE *floats = fopen("floats.txt", "w+");

    int flag, ipint, exitStatus;
    char ipchar;
    float ipfloat;

    if (NULL == input) {
        perror("File not found [input.txt]");
        return EXIT_FAILURE;
    }

    while ((exitStatus = fgetc(input)) != EOF && ungetc(exitStatus, input))
    {
        fscanf(input, "%d", &flag);
        switch (flag) {

            case 'I':
                fscanf(input, "%i", &ipint);
                fprintf(ints, "%i", ipint);
                break;

            case 'C':
                fscanf(input, "%c", &ipchar);
                fprintf(chars, "%c", ipchar);

                break;

            case 'F':
                fscanf(input, "%f", &ipfloat);
                fprintf(floats, "%f", ipfloat);
                break;

            default:
                puts("Flag not recognized");
                fclose(input);
                fclose(ints);
                fclose(floats);
                fclose(chars);
                return EXIT_FAILURE;
        }

    }
    fclose(input);
    fclose(ints);
    fclose(floats);
    fclose(chars);

    return EXIT_SUCCESS;
}
