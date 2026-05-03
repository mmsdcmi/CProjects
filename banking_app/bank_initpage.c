#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include "file_handle.h"
#include "banking_validation.h"
#include "login_member.h"
char string_buf[5];



int main()
{       memcount_filecheck();
        meminfo_filecheck();
    unsigned int choice=0;
    printf("Welcome to the bank.\n");
    printf("Please select an option:\n");
    printf("1.Register\n2.Login\n3.Exit the application.\n");
    fgets(string_buf,sizeof(string_buf),stdin);
    choice=atoi(string_buf);
    while(1)
    {
        if(choice==1)
        {
            member_register();
            choice=0;
            memset(string_buf,0,sizeof(string_buf));
            printf("Please select an option:\n");
            printf("2.Login\n3.Exit the application.\n");
            fgets(string_buf,sizeof(string_buf),stdin);
            choice=atoi(string_buf);
        }
        else if(choice==2)
        {
            member_login();
            choice=0;
            memset(string_buf,0,sizeof(string_buf));
            printf("Please select an option:\n");
            printf("1.Register\n3.Exit the application.\n");
            fgets(string_buf,sizeof(string_buf),stdin);
            choice=atoi(string_buf);
        }
        else if(choice==3){
            return 0;
        }
        else
        {
            printf("Invalid Choice.Enter again\n");
            memset(string_buf,0,sizeof(string_buf));
            fgets(string_buf,sizeof(string_buf),stdin);
            choice=atoi(string_buf);
        }
    }






    return 0;
}

