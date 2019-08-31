#include<stdio.h>
#include<stdlib.h>
#include<pwd.h>
#include<unistd.h>
#include<string.h>
void main();
struct booking{
    int regno;
    char fname[10];
    char lname[10];
    char age[3];
    char gender[7];
    char date[11];
    char source[4];
    char dest[5];  
    struct booking *next;      
};
FILE *fp1;
char ch,buffer[1000];
char source[3],dest[3],fare[4];
char* itoa(int val, int base){
	
static char buf[32] = {0};
	
int i = 30;
	
for(; val && i ; --i, val /= base)
	
 		buf[i] = "0123456789abcdef"[val % base];
	
 	return &buf[i+1];
	
 }
void printroute()
{
    printf("\n\n  The Route Details are as follows : \n\n");
    fp1 = fopen("./route_details.txt","r");
    while((ch = fgetc(fp1)) != EOF)
      printf("%c", ch);
    fclose(fp1);
}
void insertroute()
{   
    char str1[35];
    fp1 = fopen("./route_details.txt","a");
    printf("\n <--------Fill the Following Details to Create a New Route-------->");
    printf("\n\n Enter Source : ");
    scanf("%s",source);
    printf("\n Enter Destination : ");
    scanf("%s",dest);
    printf("\n Enter Fare : ");
    scanf("%s",fare);
    strcat(str1,strcat(strcat(strcat(strcat(source,"    -->      "),dest),"            "),fare));
   // fprintf(fp1,"\n");
    fputs(str1,fp1);
    fprintf(fp1,"\n");
    fclose(fp1);
    strcpy(str1,"");    
}
void deleteroute()
{
    int line_no,temp=1;
    int ran = rand() % 100 + 1;char c;
    fp1 = fopen("./route_details.txt","r");
    rewind(fp1);
    printf("Enter the line no for route you wanna delete : ");
    scanf("%d",&line_no);
    char filename[20] = "route_details.txt";
    FILE *fp2 = fopen("copy.txt","w");
    c = getc(fp1);
    while(c != EOF){
        c = getc(fp1);
        if(c ==  '\n');
            temp++;
        if (temp != line_no)
        {
            putc(c,fp2);
        }
    }fclose(fp1);
    fclose(fp2);
    // rewind(fp1);
    // fseek(fp1,line_no,SEEK_SET);
    // fputs("\n This route is deleted .",fp1);
    // fclose(fp1);
}
void bookticket(struct booking** head) {
    printroute();
    struct booking* newbooking = (struct booking*)malloc(sizeof(struct booking));
    struct booking *last = *head;
    FILE *fp2;
  //  char name[10],sex[5],temp[20],age[2];
    int regno = rand()%100000 + 3;
    printf("\n\n Enter your first name : ");
    scanf("%s",newbooking->fname);
    printf("\n Enter your last name : ");
    scanf("%s",newbooking->lname);
    printf("\n Enter your age : ");
    scanf("%s",newbooking->age);   
    printf("\n Enter your gender : ");
    scanf("%s",newbooking->gender);
    printf("\n Enter your Journey Date : ");
    scanf("%s",newbooking->date);
    printf("\n Enter the Source : ");
    scanf("%s",newbooking->source);
    printf("\n Enter the Destination : ");
    scanf("%s",newbooking->dest);
    newbooking->regno = regno;
    newbooking->next=NULL;
    printf("\n\n Your Registration No is  : %d " , newbooking->regno);
    printf("\n\n -----Booking Successfully !!! Happy Journey ----- ");
    if(*head == NULL)
    {
        *head = newbooking;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next; 
    }
    last->next = newbooking;
}
void printbooking(struct booking *head)
{
    printf("\n  <--------The Booking Details are as follows:-------->");
    while(head != NULL)
    {
        printf("\n\n Registration No : %d",head->regno);
        printf("\n Name : %s",strcat(strcat(head->fname," "),head->lname));
        printf("\n Age : %s",head->age);
        printf("\n Gender : %s",head->gender);
        printf("\n Journey Date : %s",head->date);
        printf("\n Source : %s",head->source);
        printf("\n Detination : %s",head->dest);
        printf("\n");
        head = head->next;
    }
}
void cancelticket(struct booking **head) 
{
    int regno;
    printf("\nEnter the Registration ID for the Ticket you want to cancel : ");
    printf("\n----->");
    scanf("%d",&regno);
    struct booking* temp = *head , *prev;
    if(temp != NULL && temp->regno == regno)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp !=NULL && temp->regno != regno)
    {
        prev = temp;
        temp=temp->next;
    }
    if(temp == NULL)return;
    
    prev->next = temp->next;

    free(temp);

}
void checkout(struct booking *head)
{
    FILE *fp3;int reg;char temp[50];
    while(head!=NULL)
    {
        char Jdate [] = " Journey Date : ";
        char Regno [] = " Registration No : ";
        char fname[] = " Name : " ;
        char reg[5];
        strcpy(reg,itoa(head->regno,10));
        strcpy(temp,head->fname);
        strcat(temp,"_");
        strcat(temp,reg);
        fp3 = fopen(strcat(temp,".pdf"),"w");
        // strcpy(temp,"");strcpy(temp,itoa(head->regno,10));
        // fputs(strcat(" RegNO : " ,temp),fp3);
        // // fputs("\n",fp3);
        //  strcpy(temp,"");
        //  strcpy(temp,head->fname);
        printf("%s",temp);
        fputs("\n",fp3);
        fputs("!!!  HAPPY JOURNEY !!!",fp3);
        fputs("\n\n",fp3);
        fputs(strcat(Jdate,head->date),fp3);
        fputs("\n",fp3);strcpy(temp,"");strcpy(temp,itoa(head->regno,10));
        fputs(strcat(Regno,temp),fp3);
        fputs("\n",fp3);
        fputs(strcat(fname,head->fname),fp3);
        fputs("\n",fp3);
        //  fputs(strcat(lname,head->lname),fp3);
        //  fputs("\n",fp3);
        char Age[] = " Age : " ;
        strcat(Age,head->age);
        fputs(Age,fp3);
        fputs("\n",fp3);
        char g[] = " Gender : " ;
       // printf("%s",g);
        strcat(g,head->gender);
        fputs(g,fp3);
      //  printf("\n%s",g);
        fputs("\n",fp3);
        char Source[] = " Source : " ;
        strcat(Source,head->source);
        fputs(Source,fp3);
        fputs("\n",fp3);
       // printf("\n%s",dest);
        char dest[] = " Destination : " ;
        strcat(dest,head->dest);
        fputs(dest,fp3);
      //  printf("\n%s",dest);
        fputs("\n",fp3);
        fputs("\n",fp3);
        fputs("----------------------------",fp3);
        //  strcpy(temp,"");strcpy(temp,head->lname);
        //  fputs(strcat(" Last Name : " ,temp),fp3);
        //  fputs("\n",fp3);
        //  strcpy(temp,"");strcpy(temp,head->gender);
        //  fputs(strcat(" Gender : " ,temp),fp3);
        //  fputs("\n",fp3);
        // strcpy(temp,"");strcpy(temp,head->lname);
        // fputs(strcat(" Last Name : " ,temp),fp3);
        // fputs("\n",fp3);
        fclose(fp3);
        free(head);
        head = head->next;
      //  strcpy(temp,"");
    }main();    
}
void admindisplay()
{   
    char admin[] = "admin";
    char adpass[] = "@dm:n";    
    int choice;
    char acct[5], password[5],pass2[5];
    printf("\n Enter Username : ");
    scanf("%s",acct);
    strncpy(password, getpass(" Enter Password: "), 5);
   // password[5] = getpass("Enter password :");
    //getpass(password);
  //  printf("%s",acct);
    //printf("%s",password);
    //strncpy(password, getpass("Password: "), 80);
    if(strcmp(acct,admin) && strcmp(password,adpass))
    {
    printf("\n\n <------Hello Admin------>");
    printf("\n\n What can I do for you from the following ");
    while(choice!=4)
    {
        printf("\n\n\n 1 : Route Details");
        printf("\n 2 : Insert a New Route" );
        printf("\n 3 : Delete a Existing Route ");
        printf("\n\n Enter your choice --> ");
        scanf("%d",&choice);
        if(choice==1)printroute();
        else if(choice==2)insertroute();
        else if(choice==3) deleteroute();
    }}
    else{
        printf("Invalid Credentials.");
    }

}
void userdisplay()
{
    struct booking* head = NULL;
    int choice;
    printf("\n\n <------Hello User------>");
    printf("\n\n What can I do for you from the following ");
    while(choice!=5)
    {
        //printf("\n\n\n 1 : Route Details");
        printf("\n\n\n 1 : Book a Ticket" );
        printf("\n 2 : Cancel a Ticket ");
        printf("\n 3 : View Current Booking Details ");
       // printf("\n 4 : View Booked Tickets ");
        printf("\n 4 : Checkout & Exit");
        printf("\n\n Enter your choice --> ");
        scanf("%d",&choice);
       // printf("\n\n  The Route Details are as follows : \n\n");
        //if(choice==1)printroute();
        if(choice==1)bookticket(&head);
        else if(choice==2) cancelticket(&head);
        else if(choice==3) printbooking(head);
        else if(choice==4) checkout(head);
    }
}
void main()
{
    int choice ;
    printf("\n\n************ Welcome To Bhushan's Bus Reservation System ************** \n");
    while(choice!=3)
    {
        printf("\n\n Select an option from below :");
        printf("\n ___________________________");
        printf("\n\n\n 1 : Admin Login\n");
        printf(" 2 : User Login\n");
        printf("\n --->");
	    scanf("%d",&choice);
        if(choice==1)admindisplay();
        else if(choice==2)userdisplay();
    }
}