#include <stdio.h>
#include <string.h>
struct Document
{
	int id;
	char name[100];
	char details[500];
};
 void createDocument()
{
	FILE *fp;
	struct Document doc;
	printf("\n=========CREATING DOCUMENT=======\n");
	printf("\nEnter The Document ID : ");
	scanf("%d",&doc.id);
	printf("Enter The Name Of The Document : ");
	scanf(" %[^\n]",doc.name);
	printf("Enter The Details Of The Document : ");
	scanf(" %[^\n]",doc.details);
	
	fp=fopen("documents.txt","a");
	
	if(fp==NULL)
	{
		printf("Error Document Cannot Be Created!!\n");
		return;
	}
	
	strcat(doc.details, "*");
	fprintf(fp,"%d|%s|%s\n",doc.id,doc.name,doc.details);
	printf("\n-----------DOCUMENT CRETAED SUCCESSFULLY--------\n");
	fclose(fp);
	
}

void listDocument()
{
	FILE *fp;
	struct Document doc;
	int searchID;
	int found=0;
	printf("Enter The Document ID To Be Searched : ");
	scanf("%d",&searchID);

	fp=fopen("documents.txt","r");
	if(fp==NULL)
    {
    	printf("\nFile Could Not Be Found !!\n");
    	return;
	}
	//
	while(fscanf(fp,"%d|%99[^|]|%499[^*]*",&doc.id,doc.name,doc.details)==3)
	{
		if(searchID==doc.id)
		{
			printf("\n__________DOCUMENT FOUND________\n");
			printf("__________DETAILS OF THE DOCUMENT_______\n");
			printf("ID Of The Document : %d\n",doc.id);
			printf("Name Of The Document :%s\n",doc.name);
			printf("Details Of The Document : %s\n",doc.details);
			found=1;
		}
	}
	if(found==0)
	{
		printf("-------Document With This ID Name Does Not Exist!!-----\n");
		printf("---------Document Search Unsuccessfull!!----------\n");
	}
	else
	{
		printf("Document Search Successfull!!\n");
	}
	fclose(fp);
}

void updateDocument()
{
	struct Document doc;
	FILE *fp;
	FILE *temp;
	int searchID;
	int found=0;
	
	printf("Enter The ID Of The Document You Want To Update : ");
	scanf("%d",&searchID);
	
	fp=fopen("documents.txt","r");
	temp=fopen("temp.txt","a");
	
	if((fp==NULL)||(temp==NULL))
	{
		printf("\nFile Could Not Be Found!!!\n");
		return;
	}
	
	while(fscanf(fp,"%d|%99[^|]|%499[^*]*",&doc.id,doc.name,doc.details)==3)
	{
		if(searchID==doc.id)
		{
			printf("\nDOCUMENT DETAILS BEFORE IT IS CHANGED:\n");
			printf("Name Of The Document :%s\n",doc.name);
			printf("Details Of The Document :%s\n",doc.details);
			
			printf("\nEnter The Updated Name Of The Document : ");
			scanf(" %[^\n]",doc.name);
			
			printf("\nEnter The Updated Detail Of The Document : ");
			scanf(" %[^\n]",doc.details);
			found=1;
		}
		strcat(doc.details, "*");
		fprintf(temp,"%d|%s|%s\n",doc.id,doc.name,doc.details);
	}
	fclose(fp);
	fclose(temp);
	if(found==1)
	{
		printf("\nDocument With ID %d Is Found ",searchID);
		remove("documents.txt");
		rename("temp.txt","documents.txt");
		printf("\nDocuments Updated Successfully!!");
	}
	else
	{
		remove("temp.txt");
		printf("\nDocument With %d ID Could Not Be Found");
	}
}

void deleteDocument()
{
	struct Document doc;
	FILE *fp;
	FILE *temp;
	int searchID;
	int found=0;
	
	printf("Enter The ID Of The Document You Want To Delete : ");
	scanf("%d",&searchID);
	
	fp=fopen("documents.txt","r");
	temp=fopen("temp.txt","a");
	
	if((fp==NULL)||(temp==NULL))
	{
		printf("\nFile Could Not Be Found!!!\n");
		return;
	}
	
	while(fscanf(fp,"%d|%99[^|]|%499[^*]*",&doc.id,doc.name,doc.details)==3)
	{
		if(searchID==doc.id)
		{
			found=1;
			continue;
		}
		strcat(doc.details, "*");
		fprintf(temp,"%d|%s|%s\n",doc.id,doc.name,doc.details);
	}
	fclose(fp);
	fclose(temp);
	if(found==1)
	{
		printf("\nDocument With ID %d Is Found \n",searchID);
		remove("documents.txt");
		rename("temp.txt","documents.txt");
		printf("\nDocuments Deleted Successfully!!");
	}
	else
	{
		remove("temp.txt");
		printf("\nDocument With %d ID Could Not Be Found");
	}
}
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
			       updateDocument();
			break;
			case 4:printf("\nYou Selected DELETING OF DOCUMENTS.\n");
			       deleteDocument();
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