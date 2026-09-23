/*Doctor_Menu*/
#include <stdio.h>
void addDoctor(){
struct Doctor{
    int id;
    char name[50];
    char specialization[50];
    char hospital[100];
    char phone[15];
}doctor[100];
void addDoctor(int doccount){
    printf("Enter Doctor ID: ");
    scanf("%d", &doctor[0].id);

    printf("Enter Doctor Name: ");
    scanf("%s", doctor[0].name);

    printf("Enter Doctor Specialization: ");
    scanf("%s", doctor[0].specialization);

    printf("Enter Doctor Phone: ");
    scanf("%s", doctor[0].phone);

    printf("Enter Doctor Hospital: ");
    scanf("%s", doctor[0].hospital);

    doctor[doccount] = doctor[0];
    doccount++;
    printf("Doctor added successfully!\n");

}
void viewDoctor(int doccount){
    if(doccount == 0){
        printf("No doctors available.\n");
        return;
    }
    printf("Doctor List:\n");
    for(int i = 0; i < doccount; i++){
         printf(" ID  name  Specialization  Phone  Hospital\n");
        printf("%d  %s  %s  %s  %s\n", doctor[i].id, doctor[i].name, doctor[i].specialization, doctor[i].phone, doctor[i].hospital);
    }
}
void update(int doccount){
    
}
int main(){
    int doccount = 0;
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