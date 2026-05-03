#include<stdio.h>
#include<inttypes.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#include "file_handle.h"
#include "mail_validation.h"
FILE *fileptr;
char sb[100];


int pwdvalidation(char *uname){
    int cl=0,sl=0,num=0,i=0;
    while(uname[i]!='\0'){
        if(uname[i]>='A' && uname[i]<='Z'){
            cl=1;
            i=0;
            break;
        }
        i++;
    }
    while(uname[i]!='\0'){
        if(uname[i]>='a' && uname[i]<='z'){
            sl=1;
            i=0;
            break;
        }
        i++;
    }
    while(uname[i]!='\0'){
        if(uname[i]>='0' && uname[i]<='9'){
            num=1;
            i=0;
            break;
        }
        i++;
    }
    if(sl==1 && cl==1 && num==1&&(strlen(uname)>=8 && strlen(uname)<=14)){
        return 1;
    }
    else{
        return 0;
    }

}

int unamevalidation(char *uname){
    int cl=0,sl=0,num=0,i=0;
    while(uname[i]!='\0'){
        if(uname[i]>='A' && uname[i]<='Z'){
            cl=1;
            i=0;
            break;
        }
        i++;
    }
    while(uname[i]!='\0'){
        if(uname[i]>='a' && uname[i]<='z'){
            sl=1;
            i=0;
            break;
        }
        i++;
    }
    while(uname[i]!='\0'){
        if(uname[i]>='0' && uname[i]<='9'){
            num=1;
            i=0;
            break;
        }
        i++;
    }
    if(sl==1 && cl==1 && num==1&&(strlen(uname)>=5 && strlen(uname)<=8)){
        return 1;
    }
    else{
        return 0;
    }

}
int namevalidation(char name[50]){

int i=0,inf=0;
                while(name[i]!='\0'){
                    if(name[i]=='@' || name[i]=='_'|| name[i]=='-' || (name[i]>='0' && name[i]<='9')){
                                    inf=1;
                                    break;
                    }
                    i++;
                }

    return inf;
}

int dobvalidation(unsigned int date,unsigned int month,unsigned int year){
            if(date>31){
                    return 1;
                }
                if(month>12 || month==0){
                     return 1;
                }
                if(year>2008){
                    return 1;
                }
                else{
                    return 0;
                }

}

void member_register()
{
    system("cls");
    printf("Welcome to registration. Please enter your details.\n");
    printf("Enter your name:\n");
    fgets(mi.name,40,stdin);
    mi.name[strcspn(mi.name,"\n")]='\0';
    while(1)
    {
        int inf=0;
        inf=namevalidation(mi.name);
        if(inf==1)
        {
            printf("Invalid Name.Enter Again.\n");
            fgets(mi.name,40,stdin);
            mi.name[strcspn(mi.name,"\n")]='\0';
        }
        else
        {
            break;
        }

    }
    printf("Enter your date of birth in dd/mm/yyyy format:\n");
    fgets(sb,sizeof(sb),stdin);
    sscanf(sb,"%u/%u/%u",&mi.date,&mi.month,&mi.year);
    while(1)
    {
        int inf=0;
        inf=dobvalidation(mi.date,mi.month,mi.year);
        if(inf==1)
        {
            printf("Invalid Date of Birth Entered.Please enter again in dd/mm/yyyy format.\n");
            fgets(sb,sizeof(sb),stdin);
            sscanf(sb,"%u/%u/%u",&mi.date,&mi.month,&mi.year);
        }
        else
        {

            break;
        }


    }
    printf("Enter your gender details:\n");
    fgets(mi.gender,sizeof(mi.gender),stdin);
    mi.gender[strcspn(mi.gender,"\n")]='\0';
    while(1)
    {
        if((strcmp(mi.gender,"Male")==0) || ((strcmp(mi.gender,"Female")==0)))
        {
            break;

        }
        else
        {
            printf("Invalid Gender.Enter again.\n");
            fgets(mi.gender,sizeof(mi.gender),stdin);
            mi.gender[strcspn(mi.gender,"\n")]='\0';

        }
    }
    printf("Enter your 12 digit account number:\n");
    fgets(sb,sizeof(sb),stdin);
    mi.account_no=atoll(sb);
    while(1)
    {
        if(mi.account_no>=999999999999 || mi.account_no<=920000000000)
        {
            printf("Invalid Account Number.Enter Again.\n");
            fgets(sb,sizeof(sb),stdin);
            mi.account_no=atoll(sb);
        }
        else
        {
            break;
        }
    }
    printf("Enter your email id:\n");
    fgets(mi.email,sizeof(mi.email),stdin);
    mi.email[strcspn(mi.email,"\n")]='\0';
    while(1){
        int inf=0;
        inf=mailvalidation(mi.email);
        if(inf==0){
            printf("Invalid Email Id.Enter again.\n");
            fgets(mi.email,sizeof(mi.email),stdin);
            mi.email[strcspn(mi.email,"\n")]='\0';
        }
        else{
            break;
        }
    }
    printf("Enter your mobile no:\n");
    fgets(sb,sizeof(sb),stdin);
    mi.phone_no=atoll(sb);
    while(1){
        if(mi.phone_no>9999999999 || mi.phone_no<1000000000){
            printf("Invalid phone number.Enter again.\n");
            fgets(sb,sizeof(sb),stdin);
            mi.phone_no=atoll(sb);
        }
        else{
            break;
        }
    }
    printf("Enter the username that you want to use:\n");
    printf("Minimum length is 5 and maximum length is 8.\n");
    fgets(mi.username,sizeof(mi.username),stdin);
    mi.username[strcspn(mi.username,"\n")]='\0';
    while(1){
        int inf=0;
        inf=unamevalidation(mi.username);
        if(inf==0){
                    printf("Invalid username. Enter again.\n");
                    fgets(mi.username,sizeof(mi.username),stdin);
                    mi.username[strcspn(mi.username,"\n")]='\0';

        }
        else{
            break;
        }
    }
    printf("Enter the password that you want to set:\n");
    printf("Minimum length is 8 and maximum length is 14.\n");
    fgets(mi.password,sizeof(mi.password),stdin);
    mi.password[strcspn(mi.password,"\n")]='\0';
    while(1){
        int inf=0;
        inf=pwdvalidation(mi.password);
        if(inf==0){
            printf("Invalid Password.Enter again.\n");
            fgets(mi.password,sizeof(mi.password),stdin);
            mi.password[strcspn(mi.password,"\n")]='\0';
        }
        else{
            break;
        }
    }

    system("cls");
    printf("Please review your details:\n");
    printf("Name: %s\n",mi.name);
    printf("DOB: %02u/%02u/%u\n",mi.date,mi.month,mi.year);
    printf("Gender: %s\n",mi.gender);
    printf("Account No: %"PRIu64"\n",mi.account_no);
    printf("Mobile No: %"PRIu64"\n",mi.phone_no);
    printf("Email Id: %s\n",mi.email);
    printf("Username: %s\n",mi.username);
    printf("Password: %s\n",mi.password);
    printf("Press 1 to submit.Press 2 to reenter details.\n");
    fgets(sb,sizeof(sb),stdin);
    sb[strcspn(sb,"\n")]='\0';
    if(strcmp(sb,"1")==0){
        mi.balance=0;
        memcount_fileaction();
        meminfo_fileaction(mi.name,&mi.date,&mi.month,&mi.year,mi.gender,&mi.account_no,&mi.phone_no,mi.email,mi.username,mi.password,&mi.balance);
    }
    else if(strcmp(sb,"2")==0){
        member_register();
    }
    else{
        printf("Invalid Option.Select again\n");
    }
    }


