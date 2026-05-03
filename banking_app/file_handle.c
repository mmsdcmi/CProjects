#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<inttypes.h>

FILE *fileptr=NULL,*fileptr1=NULL;


void memcount_filecheck()
{

    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_count.txt","r+t");
    if(fileptr==NULL)
    {
        printf("File not present.Trying to create member count file.\n");
        fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_count.txt","w");
        if(fileptr==NULL)
        {
            printf("Member count file creation failed.");

        }
        else
        {
            printf("Member count File created successfully.\n");
            fprintf(fileptr,"%u\n",0);
            fclose(fileptr);

        }

    }
    else
    {
        printf("Member Count file read successfully.\n");
        fclose(fileptr);
        Sleep(1000);
        system("cls");
    }


}
void meminfo_filecheck()
{

    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","a");
    if(fileptr==NULL)
    {
        printf("File not present.Trying to create member info file.\n");
        fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","w");
        if(fileptr==NULL)
        {
            printf("Member info File creation failed.");

        }
        else
        {
            printf("Member info File created successfully.\n");
            fclose(fileptr);

        }

    }
    else
    {
        printf("Member Info file read successfully.\n");
        fclose(fileptr);
        Sleep(1000);
        system("cls");
    }


}
void memcount_fileaction()
{
    unsigned int count=0;
    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_count.txt","r+t");
    fscanf(fileptr,"%u",&count);
    count++;
    rewind(fileptr);
    fprintf(fileptr,"%u\n",count);
    fclose(fileptr);
}


void meminfo_fileaction(char *name,unsigned int *date,unsigned int *month,unsigned int *year,char *gender,uint64_t *ano,uint64_t *phno, char *email,char *un,char *pw,int64_t *bal )
{
    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","a");
    if(fileptr==NULL)
    {
        printf("Info fail opening failed.\n");
    }
    else
    {

        fprintf(fileptr,"%s,%02u/%02u/%u,%s,%"PRIu64",%"PRIu64",%s,%s,%s,%"PRId64"\n",name,*date,*month,*year,gender,*ano,*phno,email,un,pw,*bal);
        fclose(fileptr);
    }

}
int meminfo_credentials_proc(char *username,char *pwd)
{
    char buffer[400];
    int pos=0;
    uint8_t successuser=0,successpass=0,success=0;
    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","r");
    if(fileptr!=NULL)
    {
        while(fgets(buffer,sizeof(buffer),fileptr))
        {
            pos=0;
            buffer[strcspn(buffer,"\n")]='\0';
            char *tok=strtok(buffer,",");
            while(tok!=NULL)
            {

                if(strcmp(username,tok)==0 && pos==6)
                {
                    successuser=1;
                }
                if(strcmp(pwd,tok)==0 && pos==7)
                {
                    successpass=1;
                }
                tok=strtok(0,",");
                pos++;

            }

            if(successuser==1 && successpass==1)
            {

                success=1;
                break;
            }

        }
    }
    else
    {
        printf("Member File read failed.\n");
    }
    fclose(fileptr);
    return success;


}
int user_present_check(char *buffer,char *username){
    char strcmpbuf[50];
    char *strcmptrav=strcmpbuf;
    int pos=0;
    while(*buffer!='\0')
            {
                if(*buffer==',')
                {   pos++;

                    if(strcmp(strcmpbuf,username)==0 && pos==7)
                    {
                        return 1;


                    }
                    memset(strcmpbuf,0,sizeof(strcmpbuf));
                    strcmptrav=strcmpbuf;
                    buffer++;
                }
                *strcmptrav=*buffer;
                strcmptrav++;
                buffer++;
            }
        return 0;
}
void meminfo_display(char *username)
{
    char buffer[400];
    uint8_t userfound=0,i=0;
    char *fields[10]= {"Name:","D.O.B:","Gender:","Account Number:","Phone Number:","Email:","Username:","Balance:"};
    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","r");
    if(fileptr!=NULL)
    {
        while(fgets(buffer,sizeof(buffer),fileptr))
        {
            buffer[strcspn(buffer,"\n")]='\0';
            userfound=user_present_check(buffer,username);

            if(userfound==1)
            {
                int j=0;
                char *tok=strtok(buffer,",");
                while(tok!=NULL)
                {
                    if(j!=7)
                    {
                        printf("%s%s\n",fields[i],tok);
                        i++;

                    }
                    j++;
                    tok=strtok(0,",");

                }
                break;

            }



        }
    }

    else
    {
        printf("Member File read failed.\n");
    }
    fclose(fileptr);



}

void member_transactions(char *username,unsigned int amount,unsigned int type)
{
    char buffer[400];
    uint8_t userfound=0,writeflag=0;
    int64_t balance=0,i=0;
    fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","r");
    if(fileptr!=NULL)
    {
        while(fgets(buffer,sizeof(buffer),fileptr))
        {
            buffer[strcspn(buffer,"\n")]='\0';
            userfound=user_present_check(buffer,username);
            if(userfound==1)
            {
                break;
            }

        }
        fclose(fileptr);
        char *tok=strtok(buffer,",");
            while(tok!=NULL)
            {
                if(i==8)
                {
                    balance=atoi(tok);
                    break;
                }


                tok=strtok(0,",");
                i++;
            }
        if(type==1)
        {

            balance=balance+amount;
            writeflag=1;
        }
        if(type==2){
            if((balance-amount)>=0){
                balance=balance-amount;
                writeflag=1;
            }
            else{
                printf("Insufficient balance in account.\n");
            }
        }
            if(writeflag==1){
            fileptr=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\member_info.txt","r");
            fileptr1=fopen("C:\\Users\\Deepan\\Documents\\cblk\\banking_app\\temp.txt","w");
            memset(buffer,0,sizeof(buffer));
            while(fgets(buffer,sizeof(buffer),fileptr))
            {   buffer[strcspn(buffer,"\n")]='\0';
                userfound=user_present_check(buffer,username);
                if(userfound==0)
                {
                    fputs(buffer,fileptr1);
                    fputs("\n",fileptr1);
                }
                else if(userfound==1)
                {
                    char strbuf[60];
                    char *strptr=strbuf;
                    char *bufftrav=buffer;
                    while(*bufftrav!='\0')
                    {
                        if(*bufftrav==',')
                        {
                            fputs(strbuf,fileptr1);
                            fputs(",",fileptr1);

                            memset(strbuf,0,sizeof(strbuf));
                            strptr=strbuf;
                            bufftrav++;
                        }

                        *strptr=*bufftrav;
                        strptr++;
                        bufftrav++;



                    }
                    fprintf(fileptr1,"%"PRId64"\n",balance);






                }
            }
            fclose(fileptr);
            fclose(fileptr1);
            remove("member_info.txt");
            rename("temp.txt","member_info.txt");
            }

            printf("Your current balance is %"PRId64"\n",balance);

        }
else
    {
        printf("Member File read failed.\n");
    }
    fclose(fileptr);


    }







