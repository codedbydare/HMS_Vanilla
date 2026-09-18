/*Doctor_Menu*/
#include <stdio.h>
void addDoctor(){

}
int main(){
    printf("----Docter MENU----\n");
    int choice;
    printf("Menu:\n");
    printf("1.Add Doctor\n");
    printf("2.View Doctor\n");
    printf("3.Update Doctor\n");
    printf("4.Delete Doctor\n");
    printf("5.Search Doctor\n");
    printf("6.Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            addDoctor();
            break;
        case 2:
            viewDoctor();
            break;
        case 3:
            updateDoctor();
            break;
        case 4:
            deleteDoctor();
            break;
        case 5:
            searchDoctor();
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}   