#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>

//�ִ� �Է¹��� �� �ִ� �л� ��

#define MAX_SIZE 3


//�л� ���� ����ü ����
struct STUDENT_INFO
{
    char name[10];
    int id,gender,c,java,kotlin,total;
    double avr;
    char grade;

};

//�л� ���� ����ü �̸� ������
typedef struct STUDENT_INFO stu_info;

int total_stu,flag,flag_d=0;

//���� �Է� �Լ�
void input_score(stu_info* stu);

//��� ��� �Լ�
char cal_grade(double avr);

//���� ��� �Լ�
void output_score(stu_info* stu,int total_stu);

//���� �˻� �Լ�
void search_score(stu_info* stu);

//���� ���� �Լ�
void insert_score(stu_info* stu);

//���� ���� �Լ�
void remove_score(stu_info* stu);

//���� ���� �Լ�
void modify_score(stu_info* stu);

//���� ���� �Լ�
void sort_score(stu_info* stu);



int main()
{
    //�������α׷� ������

    stu_info stu[MAX_SIZE];

    int menu=0;

    while(1)
    {
        //�������α׷��� �Է��� �л� ��

        printf("����� �л� ��:");
        scanf("%d",&total_stu);


            if(total_stu>MAX_SIZE)
            {
                printf("���� �ο��̻��� ���� �Է��� �� �����ϴ�. �ٽ� �Է��ϼ���.\n");
                continue;
            }
            else
            {
                break;
            }


    }


    while(!flag)
    {


        printf("1. ���� �Է�  ");
        printf("2. ���� ���  ");
        printf("3. ���� �˻�  ");
        printf("\n");

        printf("4. ���� ���� ");
        printf("5. ȭ�� ������ ");
        printf("6. ȭ�� �ʱ�ȭ ");
        printf("\n");

        printf("7. ���� ���� ");
        printf("8. ���� ���� ");
        printf("9. ���� ����(��������/��������) ");
        printf("\n");

        printf("�޴��� �����ϼ���\n");
        scanf("%d",&menu);



        switch(menu)
        {
            case 1:
                input_score(stu);
                printf("���� �Է� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 2:
                output_score(stu,total_stu);
                printf("���� ��� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 3:
                search_score(stu);
                printf("���� �˻� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 4:
                insert_score(stu);
                printf("���� ���� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 5:
                flag=1;
                printf("ȭ�� ����\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 6:
                system("cls");
                printf("ȭ�� �ʱ�ȭ �Ϸ�\n");
                getchar();
                getchar();
                break;

            case 7:
                remove_score(stu);
                printf("���� ���� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 8:
                modify_score(stu);
                printf("���� ���� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 9:
                sort_score(stu);
                printf("���� ���� �Ϸ�\n");
                getchar();
                getchar();
                system("cls");
                break;

            default: printf("try again\n");

        }




    }


        printf("���α׷��� �����մϴ�");

        return 0;


}







 void input_score(stu_info* stu)
 {
     int i=0;

     for(i=0;i<total_stu;i++)
     {
         stu[i].name[0]='A'+rand()%(25-0+1)+0;
         stu[i].name[1]='A'+rand()%(25-0+1)+0;
         stu[i].name[2]='A'+rand()%(25-0+1)+0;
         stu[i].name[3]=0;

         stu[i].id=rand()%(9999-1000+1)+1000;

         stu[i].gender=rand()%(1-0+1)+0;  //��(M):1 ��(F):0

         stu[i].c=rand()%(100-0+1)+0;
         stu[i].java=rand()%(100-0+1)+0;
         stu[i].kotlin=rand()%(100-0+1)+0;

         stu[i].total=stu[i].c+ stu[i].java+ stu[i].kotlin;
         stu[i].avr=stu[i].total/(double)3;
         stu[i].grade=cal_grade(stu[i].avr);


     }

    return;



 }






 char cal_grade(double avr)
 {
     char grade=0;

     if(avr>=90)
     {
         grade='A';
     }
     else if(avr>=80 && avr<90)
     {
         grade='B';
     }
     else if(avr>=70 && avr<80)
     {
         grade='C';
     }
     else if(avr>=60 && avr<70)
     {
         grade='D';
     }
     else
     {
        grade='F';
     }

    return grade;

 }









void output_score(stu_info* stu,int total_stu)
{
     int i=0;

     for(i=0;i<total_stu;i++)
     {
       printf("%8d %8s %8d %8c %8d %8d %8d %8d %8.2lf %8c\n",i+1,stu[i].name, stu[i].id, (stu[i].gender==1)?'M':'F',
               stu[i].c, stu[i].java, stu[i].kotlin,
               stu[i].total, stu[i].avr, stu[i].grade);

     }


    return;

}









void search_score(stu_info* stu)
{
    char name[10]={0,};

    int i=0;

    printf("�˻��� �л� �̸��� �Է��ϼ���:");
    scanf("%s",&name[0]);

    for(i=0;i<total_stu;i++)
    {
      if(!strnicmp(&stu[i].name[0],&name[0], 3))
      {
          output_score(&stu[i],1);
          flag=1;
      }



    }

  if(flag==0)
  {
      printf("�˻� ����� �����ϴ�\n");
  }


    return;
}








void insert_score(stu_info* stu)
{


    if(total_stu+1>MAX_SIZE)
    {
        printf("���� �߰� �Ұ���\n");
        return;

    }




    printf("�߰��� �л� �̸�:");
    scanf("%s",&stu[total_stu].name[0]);

    printf("�߰��� �л� �й�:");
    scanf("%d",&stu[total_stu].id);

    printf("�߰��� �л� ����(��:0 ��:1):");
    scanf("%d",&stu[total_stu].gender);

    printf("�߰��� �л� c ����:");
    scanf("%d",&stu[total_stu].c);

    printf("�߰��� �л� java ����:");
    scanf("%d",&stu[total_stu].java);

    printf("�߰��� �л� kotlin ����:");
    scanf("%d",&stu[total_stu].kotlin);


     stu[total_stu].total=stu[total_stu].c+ stu[total_stu].java+ stu[total_stu].kotlin;
     stu[total_stu].avr=stu[total_stu].total/(double)3;
     stu[total_stu].grade=cal_grade(stu[total_stu].avr);

     total_stu++;


     return;


    }







void remove_score(stu_info* stu)
{

    char name[10]={0,};

    int i=0;

    printf("������ �л� �̸��� �Է��ϼ���:");
    scanf("%s",&name[0]);

    for(i=0;i<total_stu;i++)
    {
      if(!strnicmp(&name[0], &stu[i].name[0], 3))
      {

     strcpy(stu[i].name,"");
     stu[i].id=0;
     stu[i].gender=0;
     stu[i].c=0;
     stu[i].java=0;
     stu[i].kotlin=0;
     stu[i].total=0;
     stu[i].avr=0.0;
     stu[i].grade=0;

     flag=1;

      }




if(flag==0)
{
   printf("��������� ����\n");
}




    return;

}

}



void modify_score(stu_info* stu)
{

    char name[10]={0,};

    int i=0;

    printf("������ �л� �̸��� �Է��ϼ���:");
    scanf("%s",&name[0]);

    for(i=0;i<total_stu;i++)
    {
      if(!strnicmp(&name[0], &stu[i].name[0], 3))
      {

     printf("������ �л� c ����:");
     scanf("%d",&stu[i].c);

     printf("������ �л� java ����:");
     scanf("%d",&stu[i].java);

     printf("������ �л� kotlin ����:");
     scanf("%d",&stu[i].kotlin);



     stu[i].total=stu[i].c + stu[i].java + stu[i].kotlin;
     stu[i].avr=stu[i].total/(double)3;
     stu[i].grade=cal_grade(stu[i].avr);

    flag=1;


}

    }

    if(flag==0)
    {
       printf("��������� ����\n");
    }




        return;
}




void sort_score(stu_info* stu)
{

    int i,j,select_num=0;

    stu_info buff_stu;
    stu_info copy_stu[total_stu];   //�纻 ����ü ����

    for(i=0;i<total_stu;i++)
    {

      memcpy(&copy_stu[i],&stu[i], sizeof(stu[i]));


    }


    //��������: ���� ����  ��������: ���� ����

    printf("������ ��������(0) or ��������(1) �迭:");
    scanf("%d",&select_num);

    if(select_num==0)
    {


        for(i=0;i<total_stu-1;i++)
        {

            for(j=i+1;j<total_stu;j++)
            {

            if(copy_stu[i].total>copy_stu[j].total)
            {
               memcpy(&buff_stu,&copy_stu[i],sizeof(buff_stu));
               memcpy(&copy_stu[i],&copy_stu[j],sizeof(buff_stu));
               memcpy(&copy_stu[j],&buff_stu,sizeof(buff_stu));

            }



        }




    }


        }


    else
    {


        for(i=0;i<total_stu-1;i++)
        {

            for(j=i+1;j<total_stu;j++)
            {

            if(copy_stu[i].total<copy_stu[j].total)
            {
               memcpy(&buff_stu,&copy_stu[i],sizeof(buff_stu));
               memcpy(&copy_stu[i],&copy_stu[j],sizeof(buff_stu));
               memcpy(&copy_stu[j],&buff_stu,sizeof(buff_stu));

            }




        }




    }






    }


    output_score(copy_stu,total_stu);

    return;


}
