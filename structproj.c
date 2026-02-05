#include<stdio.h>
struct student{

    char name[50];
    int regno;
    int totalmarks;
    int english;
    int tamil;
    int maths;
    int science;
    int socialstudies;
    int pflag;

};

int main(){

      struct student stu[3];
      for(int index=0;index<3;index++){
        printf("Enter the details for Student %d:\n",index+1);
        printf("Enter Name:\n");
        scanf("%s",stu[index].name);
        printf("Enter Reg.No:\n");
        scanf("%d",&stu[index].regno);
        printf("Enter the marks for English:\n");
        scanf("%d",&stu[index].english);
        printf("Enter the marks for Tamil:\n");
        scanf("%d",&stu[index].tamil);
        printf("Enter the marks for Maths:\n");
        scanf("%d",&stu[index].maths);
        printf("Enter the marks for Science:\n");
        scanf("%d",&stu[index].science);
        printf("Enter the marks for Social Studies:\n");
        scanf("%d",&stu[index].socialstudies);

      }
            for(int in=0;in<3;in++){
                if((stu[in].english>=35) && (stu[in].tamil>=35) && (stu[in].maths>=35) && (stu[in].science>=35) && (stu[in].socialstudies>=35)){
                    stu[in].pflag=1;
                }
                else{
                    stu[in].pflag=0;
                }
            }

            for(int in=0;in<3;in++){
                    if(stu[in].pflag==1){
                        stu[in].totalmarks=stu[in].english+stu[in].tamil+stu[in].maths+stu[in].science+stu[in].socialstudies;
                    }
                    else{
                        stu[in].totalmarks=0;
                    }


            }




            int rankarr[3];
            int temp;
            for(int i=0;i<3;i++){
                rankarr[i]=stu[i].totalmarks;
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(rankarr[j]<rankarr[j+1] && (j+1)<3){
                        temp=rankarr[j];
                        rankarr[j]=rankarr[j+1];
                        rankarr[j+1]=temp;
                    }
                }
            }
            int rank[3];
            for(int i=0;i<3;i++){
                if(rankarr[0]==stu[i].totalmarks){
                    rank[0]=i;

                }
                else if(rankarr[1]==stu[i].totalmarks){
                    rank[1]=i;
                }
                else if(rankarr[2]==stu[i].totalmarks){
                    rank[2]=i;
                }
            }
            int ranknum=1;
            for(int i=0;i<3;i++){
                    if(stu[i].pflag==1){

                        printf("Student with rank %d and their details:\n",ranknum);
                printf("Name: %s\n",stu[rank[i]].name);
                printf("Reg.No: %d\n",stu[rank[i]].regno);
                printf("Marks:\n");
                printf("English:%d\n",stu[rank[i]].english);
                printf("Tamil:%d\n",stu[rank[i]].tamil);
                printf("Maths:%d\n",stu[rank[i]].maths);
                printf("Science:%d\n",stu[rank[i]].science);
                printf("Social Studies:%d\n",stu[rank[i]].socialstudies);
                printf("Total Marks:%d\n",stu[rank[i]].totalmarks);
                printf("\n");
                ranknum++;
                    }
                else{
                    printf("Student %s has failed the exam.\n",stu[i].name);
                }

            }





return 0;
}
