///////////////////////////////////////////////////
// Name: Kaustubh Prashant Karanjkar
// Gnumber: G01314326
///////////////////////////////////////////////////

#include<stdio.h>
#include<string.h>

char str[10][40];    //2D character array to store input strings from user.
char test[100];      //Temporary array created for illegal_char() and duplicate_char() functions.
int x=0;             //Input count 

int illegal_char(char str[],int n){   //Function to check whether illegal characters are present or not. This function will return 1 if any of the mentioned illegal string is present.
    for(int i=0;i<n;i++){
        if(str[i]=='!' || str[i]=='@' || str[i]=='#' || str[i]=='$' || str[i]=='%' || str[i]=='^' || str[i]=='(' || str[i]==')'){
            return 1;
        }
    }
    return 0;
}

int duplicate_char(char arr[]){   //Function to check duplicate strings
    if(x>=1){
    for(int i=0;i<x;i++){
        char temp1[100];
        strcpy(temp1,str[i]);
        int y = strcmp(arr,temp1); // If the output of strcmp() function is 0 then this means that both strings from the parameter are equal.
        if(y==0){                  //If y=0 then duplicate string is detected and this function will return 1.
            return 1;
        }
    }
    }
    return 0;
}

void bubbleSortAscending(){       //Bubble sort function to sort strings in ascending order 
    char t[100];
    for(int i=0;i<9;i++){
        for(int j=0;j<10-i-1;j++){
            int ret = strcmp(str[j],str[j+1]);
            if(ret>0){
                strcpy(t,str[j]);    //swapping logic
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);                
            }
        }
    }
}

void bubbleSortdescending(){      // Bubble sort function to sort strings in descending order
    char t[100];
    for(int i=0;i<9;i++){
        for(int j=0;j<10-i-1;j++){
            int ret = strcmp(str[j],str[j+1]);
            if(ret<0){
                strcpy(t,str[j]);   //swapping logic
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],t);                
            }
        }
    }
}

void display(){      // function to display the output
    for(int i=0;i<x;i++){
            printf("output: %s\n", str[i]);
    }
}

void ascendingOrder(){    //Function to display the output in ascending order
    bubbleSortAscending();
    printf("-------------------------------------------------\n");
    printf("ASCENDING ORDER:\n");
    printf("-------------------------------------------------\n");
    display();
    printf("-------------------------------------------------\n");
    printf("String with lowest ascii value: %s\n",str[0]);
    printf("String with highest ascii value: %s\n",str[9]);
}

void descendingOrder(){   //Function to display the output in descending order
    bubbleSortdescending();
    printf("-------------------------------------------------\n");
    printf("DESCENDING ORDER:\n");
    printf("-------------------------------------------------\n");
    display();
    printf("-------------------------------------------------\n");
    printf("String with lowest ascii value: %s\n",str[9]);
    printf("String with highest ascii value: %s\n",str[0]);
}



int main(){
    
    printf("Enter 10 character strings: \n");

    while(x<10){    //While loop to enter user input.
        printf("Enter string %d: ",x+1);
        fgets(str[x],500,stdin);
        strcpy(test,str[x]);
        int n = strlen(test);

        if( strlen(str[x])<2 || strlen(str[x])>26){   //Condition to check string length
            printf("Error: Please enter the characters between 1 and 25 inclusive, please re enter\n");
            continue;
        }else if(illegal_char(test,n)==1){   //Condition to check illegal character; If the 
            printf("Error: Invalid character entered, please re enter: \n");
            continue;
        }else if(duplicate_char(test)==1){  //Condition to check duplicate character
            printf("Error: Duplicate string, please re enter: \n");
            continue;
        }
        else{
            x++;    //increments counter for input
        }
    }

    int t=0; //Used to continue the loop
    while(t==0){
    char g[10]; //character array to store user input.

    printf("Press A to print characters in Ascending order or D to print characters in Descending order: ");
    scanf("%s",g);

    if(strcmp(g,"A")==0){  //If the input is "A" and the condition is true, then the ascendingOrder(); function will execute.
        ascendingOrder();
        t=1;               // t=1 to exit the while loop
    }else if (strcmp(g,"D")==0){   //If the input is "D" and the condition is true, then the descendingOrder(); function will execute.
        descendingOrder();
        t=1;
    }else{
        continue;  //If the input is not "A" or "D" then continue; statement will execute to again prompt the user to enter input values. 
    }
    }
    return 0;
}
    



