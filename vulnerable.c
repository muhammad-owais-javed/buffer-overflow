#include <stdio.h>
#include <string.h>

int check_authentication(char *password) {
    int auth_Flag = 0; 
    char password_Buffer[16]; 

    strcpy(password_Buffer, password);

    if (strcmp(password_Buffer, "secret123") == 0) {
        auth_Flag = 1;
    }

    return auth_Flag;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    if (check_authentication(argv[1])) {
        printf("Access Granted!\n");
    } else {
        printf("Access Denied.\n");
    }

    return 0;
}