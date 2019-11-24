#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "string_funcs.h"
#define LARGE 1000

void add_student(FILE *fp , int roll , char category[])//this function will add the details of one student in the database and accepts file pointer as parameter
{
    char fname[80],lname[80];
    printf("Enter %s's first name...\n" ,  category);//entering student's first name
    scanf("%s",fname);
    printf("Enter %s's last name...\n" , category);//entering student's last name
    scanf("%s",lname);
    int due, flip = 0;
    char check_due[10];
    printf("Enter due amount...\n");//entering due amount
    scanf("%s" , check_due);
    for(int i = 0; i<strlen(check_due); i++)
    {
      if(check_due[i]<'0' || check_due[i]>'9'){
        flip++;
        break;
      }
    }
    if(flip==0){
      due = to_int(check_due);
      char date[20];
      printf("Enter the due date in DD-MM-YYYY format...\n");//entering the due date
      scanf("%s",date);
      if(check_date(date)){
        if(pending_or_not(date , "24-11-2019")){
          if(fp==NULL)
          {
              printf("Error opening File! Please try again...\n");//integrity check

          }
          else
          {
              fprintf(fp,"namef=%s namel=%s roll=%d fees=%d date=%s category=%s\n",fname,lname,roll,due,date, category);//writing data into file
              printf("ADDITION DONE SUCCESSFULLY !!! :)");

          }
        }
        else{
          printf("Not Pending !!!");
        }
      }
      else{
        printf("Invalid Date");
      }
      //closing and flushing the buffer
    }
    else{
      printf("Invalid amount");
    }
}
