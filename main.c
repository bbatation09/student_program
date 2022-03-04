#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mem.h>

//최대 입력받을 수 있는 학생 수

#define MAX_SIZE 3


//학생 정보 구조체 정의
struct STUDENT_INFO
{
    char name[10];
    int id,gender,c,java,kotlin,total;
    double avr;
    char grade;

};

//학생 정보 구조체 이름 재정의
typedef struct STUDENT_INFO stu_info;

int total_stu,flag,flag_d=0;

//성적 입력 함수
void input_score(stu_info* stu);

//등급 계산 함수
char cal_grade(double avr);

//성적 출력 함수
void output_score(stu_info* stu,int total_stu);

//성적 검색 함수
void search_score(stu_info* stu);

//성적 삽입 함수
void insert_score(stu_info* stu);

//성적 삭제 함수
void remove_score(stu_info* stu);

//성적 수정 함수
void modify_score(stu_info* stu);

//성적 정렬 함수
void sort_score(stu_info* stu);



int main()
{
    //성적프로그램 데이터

    stu_info stu[MAX_SIZE];

    int menu=0;

    while(1)
    {
        //성적프로그램에 입력할 학생 수

        printf("등록할 학생 수:");
        scanf("%d",&total_stu);


            if(total_stu>MAX_SIZE)
            {
                printf("본교 인원이상의 값은 입력할 수 없습니다. 다시 입력하세요.\n");
                continue;
            }
            else
            {
                break;
            }


    }


    while(!flag)
    {


        printf("1. 성적 입력  ");
        printf("2. 성적 출력  ");
        printf("3. 성적 검색  ");
        printf("\n");

        printf("4. 성적 삽입 ");
        printf("5. 화면 나가기 ");
        printf("6. 화면 초기화 ");
        printf("\n");

        printf("7. 성적 삭제 ");
        printf("8. 성적 수정 ");
        printf("9. 성적 정렬(오름차순/내림차순) ");
        printf("\n");

        printf("메뉴를 선택하세요\n");
        scanf("%d",&menu);



        switch(menu)
        {
            case 1:
                input_score(stu);
                printf("성적 입력 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 2:
                output_score(stu,total_stu);
                printf("성적 출력 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 3:
                search_score(stu);
                printf("성적 검색 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 4:
                insert_score(stu);
                printf("성적 삽입 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 5:
                flag=1;
                printf("화면 종료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 6:
                system("cls");
                printf("화면 초기화 완료\n");
                getchar();
                getchar();
                break;

            case 7:
                remove_score(stu);
                printf("성적 삭제 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 8:
                modify_score(stu);
                printf("성적 수정 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            case 9:
                sort_score(stu);
                printf("성적 정렬 완료\n");
                getchar();
                getchar();
                system("cls");
                break;

            default: printf("try again\n");

        }




    }


        printf("프로그램을 종료합니다");

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

         stu[i].gender=rand()%(1-0+1)+0;  //남(M):1 여(F):0

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

    printf("검색할 학생 이름을 입력하세요:");
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
      printf("검색 결과가 없습니다\n");
  }


    return;
}








void insert_score(stu_info* stu)
{


    if(total_stu+1>MAX_SIZE)
    {
        printf("성적 추가 불가능\n");
        return;

    }




    printf("추가할 학생 이름:");
    scanf("%s",&stu[total_stu].name[0]);

    printf("추가할 학생 학번:");
    scanf("%d",&stu[total_stu].id);

    printf("추가할 학생 성별(여:0 남:1):");
    scanf("%d",&stu[total_stu].gender);

    printf("추가할 학생 c 점수:");
    scanf("%d",&stu[total_stu].c);

    printf("추가할 학생 java 점수:");
    scanf("%d",&stu[total_stu].java);

    printf("추가할 학생 kotlin 점수:");
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

    printf("삭제할 학생 이름을 입력하세요:");
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
   printf("삭제대상이 없음\n");
}




    return;

}

}



void modify_score(stu_info* stu)
{

    char name[10]={0,};

    int i=0;

    printf("수정할 학생 이름을 입력하세요:");
    scanf("%s",&name[0]);

    for(i=0;i<total_stu;i++)
    {
      if(!strnicmp(&name[0], &stu[i].name[0], 3))
      {

     printf("수정할 학생 c 점수:");
     scanf("%d",&stu[i].c);

     printf("수정할 학생 java 점수:");
     scanf("%d",&stu[i].java);

     printf("수정할 학생 kotlin 점수:");
     scanf("%d",&stu[i].kotlin);



     stu[i].total=stu[i].c + stu[i].java + stu[i].kotlin;
     stu[i].avr=stu[i].total/(double)3;
     stu[i].grade=cal_grade(stu[i].avr);

    flag=1;


}

    }

    if(flag==0)
    {
       printf("수정대상이 없음\n");
    }




        return;
}




void sort_score(stu_info* stu)
{

    int i,j,select_num=0;

    stu_info buff_stu;
    stu_info copy_stu[total_stu];   //사본 구조체 정의

    for(i=0;i<total_stu;i++)
    {

      memcpy(&copy_stu[i],&stu[i], sizeof(stu[i]));


    }


    //오름차순: 점점 증가  내림차순: 점점 감소

    printf("성적을 오름차순(0) or 내림차순(1) 배열:");
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
