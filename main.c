#include <stdio.h>
#include <string.h>     // strcspn
#include <unistd.h>     // sleep, fork, execlp, _exit
#include <sys/types.h>  // pid_t
#include <sys/wait.h>   // waitpid

int main(void)
{
    int choice;
    char filePath[512];

    printf("Welcome to TypeByter\nPlease pick the mode you want to do!\n");
    printf("1) TypingTest\n2) CareerMode (doesn't work)\n");

    if (scanf("%d", &choice) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    if (choice == 1) {
        printf("\nEnter the path of the file: ");

        if (fgets(filePath, sizeof(filePath), stdin) == NULL) {
            printf("Could not read input.\n");
            return 1;
        }
        filePath[strcspn(filePath, "\n")] = '\0';

        if (filePath[0] == '\0') {
            printf("No path entered.\n");
            return 1;
        }

        printf("\nYou picked the typing test, a second terminal should open.\n");
        sleep(1);
        printf("Please wait a few seconds\n");
        sleep(2);

        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            return 1;
        }

        if (pid == 0) {
            // Child: gnome-terminal runs ./typer <filePath>
            execlp("gnome-terminal", "gnome-terminal", "--wait", "--",
                   "./typer", filePath, (char *)NULL);
            perror("execlp");   // only reached if execlp failed
            _exit(1);
        }
        waitpid(pid, NULL, 0);
        printf("Typing test finished, back in the menu.\n");
    }
    else if (choice == 2) {
        printf("Career mode doesn't work yet.\n");
    }

    return 0;
}