#include<stdio.h>
#include "file_handle.h"
#include<string.h>
#include<stdlib.h>
char buffer[30];
unsigned int option=0;
unsigned int amount=0;
void member_login(){
    //TODO
                system("cls");
                printf("Welcome to login.\n");
                printf("Please enter your username:\n");
                fgets(mi.username,sizeof(mi.username),stdin);
                mi.username[strcspn(mi.username,"\n")]='\0';
                printf("Enter your password.\n");
                fgets(mi.password,sizeof(mi.password),stdin);
                mi.password[strcspn(mi.password,"\n")]='\0';
                int successflag=meminfo_credentials_proc(mi.username,mi.password);
                if(successflag==1){
                    printf("Login Successful.\n");
                    printf("Please select one of the below options.\n");
                    printf("1.View member information.\n2.Deposit Amount.\n3.Withdraw amount.\n4.Logout\n");
                    memset(buffer,0,sizeof(buffer));
                    fgets(buffer,sizeof(buffer),stdin);
                    option=atoi(buffer);
                    while(1){
                        if(option==1){
                        system("cls");
                        printf("Member Information:\n");
                        meminfo_display(mi.username);
                        printf("Enter a option:\n2.Deposit\n3.Withdrawal\n4.Logout\n");
                        memset(buffer,0,sizeof(buffer));
                        fgets(buffer,sizeof(buffer),stdin);
                        option=atoi(buffer);
                    }
                    else if(option==2){
                        system("cls");
                        printf("Enter amount to deposit:\n");
                        memset(buffer,0,sizeof(buffer));
                        fgets(buffer,sizeof(buffer),stdin);
                        amount=atoi(buffer);
                        member_transactions(mi.username,amount,1);
                        memset(buffer,0,sizeof(buffer));
                        printf("Enter a option:\n1.View member information\n3.Withdrawal\n4.Logout\n");
                        fgets(buffer,sizeof(buffer),stdin);
                        option=atoi(buffer);
                    }
                    else if(option==3){
                        system("cls");
                        printf("Enter amount to withdraw:\n");
                        memset(buffer,0,sizeof(buffer));
                        fgets(buffer,sizeof(buffer),stdin);
                        amount=atoi(buffer);
                        member_transactions(mi.username,amount,2);
                        memset(buffer,0,sizeof(buffer));
                        printf("Enter a option:\n1.View member information\n2.Deposit\n4.Logout\n");
                        fgets(buffer,sizeof(buffer),stdin);
                        option=atoi(buffer);
                    }
                    else if(option==4){
                        printf("Logging out.\n");
                        break;
                    }
                    else{
                        printf("Invalid choice. Please enter again.\n");
                        memset(buffer,0,sizeof(buffer));
                        fgets(buffer,sizeof(buffer),stdin);
                        option=atoi(buffer);

                    }
                    }
                }
                else{
                    printf("Login Failed.\n");
                    member_login();
                }


    }
