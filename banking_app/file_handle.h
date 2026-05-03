#include<inttypes.h>
void memcount_filecheck();
void meminfo_filecheck();
void meminfo_fileaction(char *name,unsigned int *date,unsigned int *month,unsigned int *year,char *gender,uint64_t *ano,uint64_t *phno, char *email,char *un,char *pw,int64_t *bal );
void memcount_fileaction();
int meminfo_credentials_proc(char *username,char *pwd);
void meminfo_display(char *username);
void member_transactions(char *username,unsigned int amount,unsigned int type);
int user_present_check(char *buffer,char *username);
struct member_info
{

    char name[40];
    unsigned int date;
    unsigned int month;
    unsigned int year;
    char gender[10];
    uint64_t account_no;
    uint64_t phone_no;
    char username[15];
    char password[20];
    char email[192];
    unsigned int member_count;
    int64_t balance;

} mi;
