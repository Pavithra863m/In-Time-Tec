#include <stdio.h>
#define SIZE 50

struct User{
    int id;
    char name[SIZE];
    int age;
};

void createFileIfNotExists(){
    FILE *file = fopen("users.txt", "r");
    if (file == NULL){
        file = fopen("users.txt", "w");
        fclose(file);
    }
    fclose(file);
}

int isIdUnique(int id){
    FILE *file = fopen("users.txt", "r");
    if(file == NULL){
        printf("Error: Could not open users.txt for reading.\n");
        return 1;
    }

    struct User user;
    while(fscanf(file, "%d\t\t%[^\t]\t\t%d\n", &user.id, user.name, &user.age) != EOF){
        if(user.id == id){
            fclose(file);
            return 0;
        }
    }
    fclose(file);
    
    return 1;
}

void getUserDetails(struct User *user){
    int isUnique;
    int ch;
    do{
        printf("Enter ID: ");
        if(scanf("%d", &user->id) != 1){
            printf("Error: Please enter a valid integer for ID.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);

            continue;
        }
        isUnique = isIdUnique(user->id);
        if(!isUnique){
            printf("Error: ID already exists. Please enter a different ID.\n");
        }
        
    }while(!isUnique);

    printf("Enter Name: ");
    scanf(" %[^\n]%*c",user->name);
        
    do{
        printf("Enter Age: ");
        if(scanf("%d", &user->age) != 1){
            printf("Error: Please enter a valid integer for Age.\n");
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if(user->age <= 0 || user->age >= 120){
            printf("Error: Please enter a valid age.\n");
        }
    }while(user->age <= 0 || user->age >= 120);
}

void createUser(){
    FILE *file = fopen("users.txt", "a");
    if(file == NULL){
        printf("Error: Could not open users.txt for appending.\n");
        return;
    }

    struct User user;

    getUserDetails(&user);

    fprintf(file, "%d\t\t%s\t\t%d\n", user.id, user.name, user.age);

    fclose(file);
    printf("User added successfully.\n");
}

void readUsers(){
    FILE *file = fopen("users.txt", "r");
    if(file == NULL){
        printf("Error: Could not open users.txt for reading.\n");
        return;
    }

    struct User user;

    printf("\nID\tName\t\tAge\n");
    while(fscanf(file, "%d\t\t%[^\t]\t\t%d\n", &user.id, user.name, &user.age) != EOF){
        printf("%d\t%s\t\t%d\n", user.id, user.name, user.age);
    }

    fclose(file);
}

void updateUser(){
    int targetId;
    printf("Enter ID of the user to update: ");
    scanf("%d", &targetId);

    FILE *file = fopen("users.txt", "r");
    if(file == NULL){
        printf("Error: Could not open users.txt for reading.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if(tempFile == NULL){
        printf("Error: Could not open temp.txt for writing.\n");
        fclose(file);
        return;
    }

    int recordFound = 0;
    struct User updatedUser, tempUser;

    while(fscanf(file, "%d\t\t%[^\t]\t\t%d\n", &tempUser.id, tempUser.name, &tempUser.age) != EOF){
        if(tempUser.id == targetId){
            recordFound = 1;

            getUserDetails(&updatedUser);

            fprintf(tempFile, "%d\t\t%s\t\t%d\n", updatedUser.id, updatedUser.name, updatedUser.age);
        } 
        else{
            fprintf(tempFile, "%d\t\t%s\t\t%d\n", tempUser.id, tempUser.name, tempUser.age);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if(recordFound){
        printf("User details updated successfully.\n");
    }else{
        printf("Record with ID %d not found.\n", targetId);
    }
}

void deleteUser(){
    int targetId;
    printf("Enter ID of the user to delete: ");
    scanf("%d", &targetId);

    FILE *file = fopen("users.txt", "r");
    if(file == NULL){
        printf("Error: Could not open users.txt for reading.\n");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if(tempFile == NULL){
        printf("Error: Could not open temp.txt for writing.\n");
        fclose(file);
        return;
    }

    struct User user;
    int recordFound = 0;

    while(fscanf(file, "%d\t\t%[^\t]\t\t%d\n", &user.id, user.name, &user.age) != EOF){
        if(user.id != targetId){
            fprintf(tempFile, "%d\t\t%s\t\t%d\n", user.id, user.name, user.age);
        }
        else{
            recordFound = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("users.txt");
    rename("temp.txt", "users.txt");


    if(recordFound){        
        printf("User with ID %d deleted successfully.\n", targetId);
    } else {
        printf("User with ID %d not found.\n", targetId);
    }
}

int main(){
    int choice;

    createFileIfNotExists();

    do{
        printf("\nMenu:\n");
        printf("1. Create User\n");
        printf("2. Read Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                createUser();
                break;

            case 2:
                readUsers();
                break;

            case 3:
                updateUser();
                break;

            case 4:
                deleteUser();
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice != 5);

    return 0;
}
