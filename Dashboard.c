#include <stdio.h>
int main()
{
	int choice;
	printf("=========================================\n");
	printf("=========MANAGEMENT OF DOCUMENTS=========\n");
	printf("=========================================\n");
	printf("\nEnter The Number According To Your Need:\n");
	do
	{
		int ch;
		
		printf("\n1. Creation Of Documents.\n");
		printf("2. Listing Of Documents.\n");
		printf("3. Updating Of Documents. \n");
		printf("4. Deletion Of Documents. \n");
		printf("5. Exit The Program.\n");
		
		printf("\nEnter Your Decision : ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:printf("\nYou Selected CREATING OF DOCUMENTS.\n");
			       createDocument();
			break;
			case 2:printf("\nYou Selected LISTING OF DOCUMENTS.\n");
			       listDocument();
			break;
			case 3:printf("\nYou Selected UPDATING OF DOCUMENTS.\n");
			break;
			case 4:printf("\nYou Selected DELETING OF DOCUMENTS.\n");
			break;
			case 5:printf("\nEXITING THE PROGRAM.\n");
			break;
			default:printf("\nINVALID CHOICE!!!\n");
		
	    }
    if(ch==5)
    break;
    printf("\nPress 1 to Continue ");
    scanf("%d",&choice);
    }while(choice==1);
    return 0;
}