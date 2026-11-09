#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void readFile(FILE *file)    {
    char *line = NULL;
    size_t len = 0;
o

    // loop for read lines from input file
    while (getline(&line, &len, file) != -1) {
        
        size_t lineLen = strlen(line);

        // ensure the line ends with line change '\n'
        if(lineLen == 0 || line[lineLen - 1] != '\n')   {
            line = realloc(line, lineLen + 2); // realloc line if newline is missing
            if(line == NULL)    {
                fprintf(stderr, "realloc failed\n");
                exit(1);
            }
            line[lineLen] = '\n';
            line[lineLen + 1] = '\0';
            lineLen++;
        }

        fprintf(stdout, "%s", line);
    }

    free(line);
    return;
}

int main(int argc, char* argv[]) {
    FILE *fp;

    if (argc == 1)    {
        exit(0);
    };
    for (int i = 1; i < argc; i++)    {
        
        // fprintf(stdout, "%s\n", argv[i]);
        fp = fopen(argv[i], "r");
        if (fp == NULL)   {
            fprintf(stderr, "my-cat: cannot open file\n");
            exit(1);
        }
        readFile(fp);
        fclose(fp);
    }

return 0;
}