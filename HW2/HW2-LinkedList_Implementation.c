///////////////////////////////////////////////////
// Name: Kaustubh Prashant Karanjkar
// Gnumber: G01314326
// HOMEWORK 2 - CS531
///////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct address_t{                   //Structure creation for linked list
    int octet[4];                   //int array to store address.
    char alias[11];                 //char array to store alias.
    struct address_t *next;         //next pointer to point to the address of next node.
};
struct address_t *head = NULL;      //head pointer

struct address_t* createList(int arr[],char name[]){     //Function to create node and add data to it.
    
    struct address_t *ptr = (struct address_t*)malloc(sizeof(struct address_t));  //The pointer ‘ptr’ now contains address of a newly created node. 
    if(ptr == NULL){               //If the linked list is empty and first node is created then it is also known as a head node.
        printf("\n Node creation failed \n");
        return NULL;
    }
    ptr->octet[0]=arr[0];  
    ptr->octet[1]=arr[1];
    ptr->octet[2]=arr[2];
    ptr->octet[3]=arr[3];
    
    strcpy(ptr->alias,name); 
    
    ptr->next=NULL;

    head=ptr;
    return ptr;
}

struct address_t* add_to_list(int arr[],char name[]){  //Function to add the newly created node to the linked list
    if(head==NULL){                                 //node is added to the front and pointer "head" points to the new node.
        return createList(arr,name);
    }
    
    struct address_t *ptr = (struct address_t*)malloc(sizeof(struct address_t));

    if(ptr == NULL){
        printf("\n Node creation failed\n");
        return NULL;
    }
    ptr->octet[0]=arr[0];    //IPv4 address is added to the new node where 'ptr' points.
    ptr->octet[1]=arr[1];
    ptr->octet[2]=arr[2];
    ptr->octet[3]=arr[3];
    
    strcpy(ptr->alias,name);  //alias is added to the new node where 'ptr' points

    ptr->next=NULL;
    ptr->next=head;  //'next' ptr points to the head which means new node is added in the front. 
    head=ptr;        //new ptr becomes the head.
    
    return ptr;
}

struct address_t* search_in_listAlias(char name[], struct address_t **prev)
{
    struct address_t *ptr = head;         //Function to search alias and return the address of it, where the 'ptr' pointer points.
    struct address_t *tmp = NULL;
    bool found = false;

    while(ptr != NULL){
        if(strcmp(ptr->alias,name)==0){  //strcmp used to match the input given by the user to the value stored in the char alias[]
            found = true;
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if(true == found){
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else{
        return NULL;
    }
}

struct address_t* search_in_list(int arr[], struct address_t **prev)
{
    struct address_t *ptr = head;  //function to search the address and return the address of it, where the 'ptr' points.
    struct address_t *tmp = NULL;
    bool found = false;

    while(ptr != NULL){
        if(ptr->octet[0]==arr[0] && ptr->octet[1]==arr[1] && ptr->octet[2]==arr[2] && ptr->octet[3]==arr[3]){
            found = true;
            break;
        }
        else{
            tmp = ptr;
            ptr = ptr->next;
        }
    }
    if(true == found){
        if(prev)
            *prev = tmp;
        return ptr;
    }
    else{
        return NULL;
    }
}

int delete_from_list(char name[]){  //function to delete node from the list.
    struct address_t *prev = NULL;   //previous pointer
    struct address_t *del = NULL;   //delete pointer
    struct address_t *curr = NULL;  //current pointer
    del = search_in_listAlias(name,&prev);
    if(del == NULL){
        return -1;
    }
    else{
        if(prev != NULL)
            prev->next = del->next;  //prev node points to the next node of pointer 'del'.

        if(del == curr){
            curr = prev;
        }
        else if(del == head){   //to delete the head of the linkedlist.
            head = del->next;
        }
    }
    free(del);  //clears the memory of the deleted node.
    del = NULL;
    return 0;
}

void displayList(void){       //Function to display list.
    struct address_t *ptr = head;
    int count = 0;
    printf("\n -------List------- \n");
    while (ptr!=NULL){
        count++;
        printf("\n %d.%d.%d.%d %s\n",ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3],ptr->alias);
        ptr=ptr->next;  //points to the next node.
    }
    printf("\nTotal node count: %d",count);  //prints the number of nodes in the linkedlist.
    printf("\n ----------------- \n");   
    return;
}

//Function to add address to the list, it checks whether the alias and address is present in the list or not. If present then it 
// will notify user to about the duplicate address/alias, and will not store the data in the list.
void addAddress(){  
            struct address_t *ptr = NULL;  
            char buf1[512]; //char array to store address
            char ans[11];  //char array to store alias name.
            int temp[4]; //temporary array 
            printf("Enter alias: ");
            scanf("%s",ans);
            ptr=search_in_listAlias(ans,NULL);
            if(ptr==NULL){
                printf("Enter address for %s: ",ans);
                scanf("%s",buf1);
                sscanf(buf1,"%d.%d.%d.%d",&temp[0],&temp[1],&temp[2],&temp[3]);
                if(temp[0]<0 || temp[0]>255 || temp[1]<0 || temp[1]>255 || temp[2]<0 || temp[2]>255 || temp[3]<0 || temp[3]>255){
                    printf("\nInvalid address entered, please re-enter. INVALID INPUT!\n");  //to check whether range of the address is in 0-255 inclusive.
                }else{
                ptr=search_in_list(temp,NULL);
                if(ptr==NULL){
                     add_to_list(temp,ans);
                }else{
                    printf("\nDuplicate address, add address operation failed.\n");                  
                }
                }
            }else{
                printf("\n%s already exists, add address operation failed.\n",ans);
            }   
}

void lookupAddress(){    //Function to search address of the alias provided by the user in input.
            struct address_t *ptr = NULL;
            char ans[11];  //char array to store alias name.
            printf("Enter alias: ");
            scanf("%s",ans);
            ptr=search_in_listAlias(ans,NULL);
            if(ptr==NULL){
                printf("%s does not exists\n",ans);
               // continue;
            }else{
                printf("Address for %s: %d.%d.%d.%d\n",ans,ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3]);
            }  
}

void updateAddress(){           //Function to update the corresponding address of alias entered by the user in input. 
            struct address_t *ptr = NULL;
            char ans[11];  //char array to store alias name.
            printf("Enter alias: ");
            scanf("%s",ans);
            ptr=search_in_listAlias(ans,NULL);   
            if(ptr==NULL){
                printf("\n%s does not exists\n",ans);
            }else{
                printf("Update address for %s: %d.%d.%d.%d",ans,ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3]);
                int x=1;
                int value;
                int temp[4];
                while(x<5){
                    printf("\nEnter location value #%d (0-255): ",x);
                    scanf("%d",&value);
                    if(value>=0 && value<=255){  //to check whether the range of the address is between 0-255 inclusive.
                        temp[x-1]=value;
                        x++;
                    }else{
                        printf("\nError: Illegal entry, please re-enter!");
                        continue;
                    }
                }
                struct address_t *ptr1 = NULL;
                ptr1=search_in_list(temp,NULL);
                if(ptr1==NULL){
                    ptr->octet[0]=temp[0];  
                    ptr->octet[1]=temp[1];
                    ptr->octet[2]=temp[2];
                    ptr->octet[3]=temp[3];
                }else{
                    printf("Error: Duplicate address entered!\n");
                }               
            }
}

void deleteAddress(){     //Function to delete the address and alias given by the user in input.
            struct address_t *ptr = NULL;
            char ans[11];  //char array to store alias name.
            char ans1[1];  //char array to store 'y' or 'n' input from the user.
            int result=0;
            printf("Enter alias to be deleted: ");
            scanf("%s",ans);
            ptr=search_in_listAlias(ans,NULL);  //Search function called to search the node having the address which is to be deleted.
            if(ptr==NULL){
                printf("Alias named %s does not exist!\n",ans);
            }else{
                printf("Delete %s %d.%d.%d.%d? Enter (y/n): ",ans,ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3]);
                scanf("%s",ans1);
                if(ans1[0]=='y'){
                    result=delete_from_list(ans); //delete function called to delete the node from the list.
                    if(result==0){
                        printf("%s was deleted!\n",ans);
                    }
                }else if(ans1[0]=='n'){
                    printf("Delete operation cancelled!\n");
                }else{
                    printf("Invalid input!\n");
                }
            }
}

void displayAliasLocation(){      //Function to display aliases as per the location given by the user in input.
            int x=1;
            int value;
            int temp[4];
                while(x<3){
                    printf("\nEnter location value #%d (0-255): ",x);
                    scanf("%d",&value);
                    if(value>=0 && value<=255){  //To check the range of the address entered. (range: 0-255 inclusive)
                        temp[x-1]=value; 
                        x++;
                    }else{
                        printf("Illegal entry, please re-enter!");
                        continue;
                    }
                }
                struct address_t *ptr = head;
                int flag=0;
                while(ptr!=NULL){
                    if(ptr->octet[0]==temp[0] && ptr->octet[1]==temp[1]){
                        printf("%d.%d.%d.%d %s\n",ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3],ptr->alias); 
                        flag=1;   
                    }
                    ptr=ptr->next;
                }
                if(flag==0){
                    printf("\nError: Location doesn't exist within the list!\n\n");
                }
}

void saveToFile(){                  //Function to save list to a new file.
            FILE *fptr;   //file pointer "fptr"
            char fileName[100];
            printf("Enter file name:");
            scanf("%s",fileName);
            fptr=fopen(fileName,"w");  //file opened/created in WRITE mode.
            struct address_t *ptr = head;
            while(ptr!=NULL){  //prints the output from the list to the file.
                fprintf(fptr,"%d.%d.%d.%d %s\n",ptr->octet[0],ptr->octet[1],ptr->octet[2],ptr->octet[3],ptr->alias);
                ptr=ptr->next;
            }
            printf("\nFile saved.\n");
            fclose(fptr);

}

void quit(){     //Function to quit the program
    printf("Goodbye!\n");
}

int main(void){
    FILE *fp;   //file pointer 'fp'
    char buf[512];
    fp = fopen("CS531_Inet.txt","r");  //open the file 
    
    if(fp==NULL){
        perror("Input file CS531_Inet.txt not present ");
        return(-1);
    }
    while(fgets(buf,500,fp)!=NULL){  //adds the data from the file and create a linkedlist and add to it by creating new nodes.
        int octTemp[4];
        char alien[11];
        sscanf(buf,"%d.%d.%d.%d %s", &octTemp[0],&octTemp[1],&octTemp[2],&octTemp[3],alien);  //parse the data to from char buf[]      
        add_to_list(octTemp,alien);        
    }
    int choice=0;
    while(choice!=8){    //while loop is used to display the menu
        printf("\n----------MENU----------\n");
        printf("1) Add address\n");
        printf("2) Lookup address\n");
        printf("3) Update address\n");
        printf("4) Delete address\n");
        printf("5) Display list\n");
        printf("6) Display aliases for location\n");
        printf("7) Save to file\n");
        printf("8) Quit");
        printf("\n------------------------\n");
        int input=0;
        printf("Enter option: ");
        scanf("%d",&input);
        if(input==1){
             addAddress();  //addAddress() function called.
        }else if(input==2){
            lookupAddress(); //lookupAddress() function called.
        }else if(input==3){
            updateAddress(); //updateAddress() function called.
        }else if(input==4){
            deleteAddress(); //deleteAddress() function called.
        }else if(input==5){
            displayList();   //displayList() function called.
        }else if(input==6){
            displayAliasLocation(); //displayAliasLocation() function called.
        }else if(input==7){
            saveToFile();  //saveToFile() function called.
        }else if(input==8){
            choice=8;    //value of choice variable changed to 8 to teminate the while loop and end the program.
            quit();  //quit() function called.
        }else{
            printf("Please enter valid input\n"); //if any input other than 1-8 is entered then this will print.
            continue;
        }
    }
    return 0;
}