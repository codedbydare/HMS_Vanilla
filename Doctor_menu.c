/*Doctor_Menu*/
#include <stdio.h>
struct Doctor{
    int id;
    char name[50];
    char specialization[50];
    char hospital[100];
    char phone[15];
}doctor[100];
void addDoctor(int *doccount){
	printf("---------------------\n");
    printf("Enter Doctor ID: ");
    scanf("%d", &doctor[*doccount].id);

    printf("Enter Doctor Name: ");
    scanf("%s", doctor[*doccount].name);

    printf("Enter Doctor Specialization: ");
    scanf("%s", doctor[*doccount].specialization);

    printf("Enter Doctor Phone: ");
    scanf("%s", doctor[*doccount].phone);

    printf("Enter Doctor Hospital: ");
    scanf("%s", doctor[*doccount].hospital);

    printf("---------------------\n");
    printf("Doctor added successfully!\n");
    printf("---------------------\n");

}
void viewDoctor(int doccount){
	printf("---------------------\n");
    if(doccount == 0){
        printf("No doctors available.\n");
        return;
    }
    printf("Doctor List:\n");
    int i;
    for( i = 0; i < doccount; i++){
         printf(" ID  name  Specialization  Phone  Hospital\n");
        printf("%d  %s  %s  %s  %s\n", doctor[i].id, doctor[i].name, doctor[i].specialization, doctor[i].phone, doctor[i].hospital);
    }
    printf("---------------------\n");
}
void updateDoctor(int doccount){
    int id;
    printf("---------------------\n");
    printf("Enter Doctor ID to update: ");
    scanf("%d", &id);
    int i;
    for (i=0;i<doccount;i++){
        if(doctor[i].id==id){
            printf("enter new Doctor Name:");
            scanf("%s",doctor[i].name);

            printf("enter new specialization:");
            scanf("%s",doctor[i].specialization);

            printf("enter new phone no.:");
            scanf("%s", doctor[i].phone);
        }
        else{
            printf("Doctor not found.\n");
        }
    }
    printf("---------------------\n");

}
void deleteDoctor(int *doccount){
    int id;
    int i,j;
    printf("---------------------\n");
    printf("Enter Doctor ID to delete: ");
    scanf("%d", &id);
    
    for(i=0;i<*doccount;i++){
        if(doctor[i].id==id){
            for(j=i;j<*doccount-1;j++){
                doctor[j]=doctor[j+1];
            }
            (*doccount)--;
            printf("Doctor deleted successfully!\n");
            return;
        }

}
printf("---------------------\n");
}
void searchDoctor(int doccount){
    int id;
    int i,erro=0;
    printf("---------------------\n");
    printf("enter Doctor ID to search: ");
    scanf("%d", &id);
    printf("---------------------\n");
    for(i=0;i<doccount;i++){
        if(doctor[i].id==id){
            printf("Doctor:\n");
            printf("ID:%d\n", doctor[i].id);
            printf("Name:%s\n", doctor[i].name);
            printf("Specialization:%s\n", doctor[i].specialization);
            printf("Phone:%d\n", doctor[i].phone);
            printf("Hospital:%s\n", doctor[i].hospital);
            erro=1;
        }
    }
    if(erro==0){
        printf("Doctor not found.\n");
}
printf("---------------------\n");  
}
int main(){
    int doccount = 0;
    printf("----Docter MENU----\n");
    int choice;
    printf("1.Add Doctor\n");
    printf("2.View Doctor\n");
    printf("3.Update Doctor\n");
    printf("4.Delete Doctor\n");
    printf("5.Search Doctor\n");
    printf("6.Exit\n");
    do{
    	printf("---------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                addDoctor(&doccount);
                doccount++;
                break;
            case 2:
                viewDoctor(doccount);
                break;
            case 3:
                updateDoctor(doccount);
                
                break;
            case 4:
                deleteDoctor(&doccount);
                break;
            case 5:
                searchDoctor(doccount);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=6);
  printf("Welcome to Hospital Management System\n");
  return 0;
}
