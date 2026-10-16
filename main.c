#include <stdio.h>
#include<unistd.h>

int main(void) {
    int option;

    printf("TypeByter, just pick the mode you want\n");
    printf("1) Start random time trial\n");
    printf("2) Mode two (ka was ich hier machen werde)\n");
    printf("Your choice: ");
    scanf("%d", &option);

    if (option == 1) {
        printf("You picked the time trial, you will be sent into the trial!\n please wait until the Realm has opened.");
        sleep(1);
        printf("3");
        sleep(1);
        printf("2");
        sleep(1);
        printf("1");
        sleep(1);
        printf("Be ready to defend your System");
    } else if (option == 2) {
        printf("You picked mode two\n");
    } else {
        printf("Invalid choice\n");
    }
    return 0;
}