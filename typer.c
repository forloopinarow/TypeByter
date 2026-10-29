#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *read_file(char *filename);

int main(int argc, char *argv[]){
    printf("Filepath given: %s \n", argv[1]);
    char *file_contents = read_file(argv[1]);
    if(file_contents == NULL){
        printf("Content null\n");
        return 1;
    }

    sleep(3);

    printf("File Content: %s",file_contents);
    fflush(stdout);

    sleep(5);
    return 0;
}

char *read_file(char *filename){
    FILE *file;

    file = fopen(filename, "r");

    if(file == NULL) return NULL;

    fseek(file,0,SEEK_END);
    int length = ftell(file);
    fseek(file,0,SEEK_SET);

    char *string = malloc(sizeof(char) * (length+1));

    int c;
    int i =0;
    while ((c = fgetc(file))!= EOF){
        string[i] = c;
        i++;
    }
    string[i] = '\0';

    fclose(file);

    return string;
}