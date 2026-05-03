#include<stdio.h>
#include<string.h>
int hasat(char *email);
int atindex(char *email);
int hasdot(char *emaildom);

int hasat(char *email){
int hasat=0;
for(int index=0;email[index]!='\0';index++){
                if(email[index]=='@'){
                    hasat++;
                }
        }

return hasat;

}
int atindex(char *email){
        int atindex=0;
        for(int index=0;email[index]!='\0';index++){
                if(email[index]=='@'){
                    atindex=index;
                    break;
                }
        }
return atindex;
}

int hasdot(char *emaildom){
int hasdot=0;
                    for(int index=0;index<strlen(emaildom);index++){
                            if(emaildom[index]=='.'){
                                hasdot++;
}
}

return hasdot;
}
int mailvalidation(char *email){

        //char emailid[192];

        char emailprefix[64];
        char emaildomain[126];
        int at_index=0;
        int ha=hasat(email);
        int domcheck=0;
        if(ha==0 || ha>1){


            return 0;
        }
        else if(ha==1){

                at_index=atindex(email);

                for(int indexdom=0,idindex=at_index+1;idindex<strlen(email)+2;indexdom++,idindex++){
                        emaildomain[indexdom]=email[idindex];
                }





                        int hd= hasdot(emaildomain);

                            if(hd==0 || hd>1){


                                return 0;
                            }
                            else if(hd==1){

                                        if(emaildomain[0]=='-' || emaildomain[strlen(emaildomain-1)]=='-'){
                                                return 0;
                                        }
                                        else{

                                            for(int index=0;index<strlen(emaildomain);index++){
                                                if(emaildomain[index]>='a' && emaildomain[index]<='z' || emaildomain[index]>='A' && emaildomain[index]<='Z' || emaildomain[index]=='-' || emaildomain[index]=='.'){
                                                    domcheck=1;
                                                }
                                                else{
                                                    domcheck=0;
                                                    break;
                                                }

                                                }
                                            }
                                        }

                                            if(domcheck==1){
                                                 for(int index=0;index<at_index;index++){
                                                emailprefix[index]=email[index];}
                                                            int prefcheck=1;
                                                for(int index=0;index<strlen(emailprefix);index++){

                                                    if(emailprefix[0]=='.'|| emailprefix[strlen(emailprefix)-1]=='.' || (emailprefix[index]=='.' && emailprefix[index+1]=='.') || emailprefix[index]==' '){
                                                        prefcheck=0;
                                                        break;

                                                    }






                                            }
                                             if(prefcheck==1){

                                                            return 1;
                                                        }
                                                        else if(prefcheck==0){

                                                            return 0;
                                                        }

                                            }
                                            else if(domcheck==0){

                                                return 0;
                                            }






                                        }


           return 0;
                                        }











