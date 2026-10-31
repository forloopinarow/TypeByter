#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *read_file(char *filename);

int main(int argc, char *argv[]){
    printf("Filepath given: %s \n", argv[1]);
    char *file_contents = read_file(argv[1]);
    if(file_contents == NULL){
        printf("Content null\n");
        return 1;
    }

    sleep(3);

    printf("File Content: %s\n",file_contents);
    fflush(stdout);

    sleep(1);
    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);
    printf("START TYPING QUICK!!!!!!!!!\n");
    sleep(0.1);

    time_t start = time(NULL);


    //basic implementation since im bored
    
    size_t length = strlen(file_contents);
    char *typed = malloc(length +1);
    if (fgets(typed, length + 1, stdin) != NULL) {
        typed[strcspn(typed, "\n")] = '\0';
    }

    char string[2];
    
    if(strcmp(file_contents,typed) ==0){
        time_t finish = time(NULL);
        double timeTaken = difftime(finish,start);
        double minutes = timeTaken / 60.0;
        double wpm = ((double)length / 5.0) / minutes;
        printf("Great job, you finished, here are your stats!\n===========================================================================\nTime taken: %.1f\nWPM: %.2f\nRelative/Absolutepath: %s \nCharacters: %d\n===========================================================================\n", timeTaken,wpm,argv[1],length);
        fflush(stdout);
        //printf("WPM: %.2f\n", wpm);
    }
    else{
        printf("Sadly you didnt write the same Text\n just try again later! Good attempt tho");
    }

    sleep(15);

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