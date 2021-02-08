#include"head.h"
char *username;
char *keyword;
char fileuser[25];
void startmenu()
{
    printf("\t\t\t-----------------------------------------------------\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t**************      [1] ��¼�˻�      ***************\n");
    printf("\t\t\t**************      [2] ע���˻�      ***************\n");
    printf("\t\t\t**************      [3]   �˳�        ***************\n");
    printf("\t\t\t*****************************************************\n");
    printf("\t\t\t-----------------------------------------------------\n");
}
int choose(char range)
{
    printf("\t\t\t��ѡ��:");
    char tmp;
    int flag=1;
    while(1)
    {
        scanf("%c",&tmp);
        while((getchar()!='\n'))
            flag=0;
        if(tmp>='1'&&tmp<=range&&flag)
            return tmp-'0';
        else
            printf("\t\t\t������1~%c֮�������:",range);
        flag=1;
    }
}
int next1(int choose,int*flag)
{
    *flag=1;
    switch(choose)
    {
    case 1:
        return login()? TRUE:(*flag=0,TRUE);
    case 2:
        return signup()? TRUE:(*flag=0,TRUE);
    case 3:
        return FALSE;
    }
}
int login()
{
    int len=0,flag=1,pan=0;
    char t[21];
    char tmp;
    printf("\t\t\t�������û���(�����ո�,����Ϊ5-20):");
    username=(char*)malloc(21);
    while((tmp=getchar())!='\n')
    {
        if(tmp==' ')
        {
            pan=1;
            break;
        }
        if(len==20)
        {
            len++;
            break;
        }
        username[len]=tmp;
        len++;
    }
    if(len==21||len<5||pan)
    {
        printf("\t\t\t�û�������\n\t\t\t");
        system("pause");
        system("cls");
        free(username);
        username=NULL;
        return FALSE;
    }
    username[len]='\0';
    FILE*user=fopen(USER,"r");
    if(!user)
    {
        flag=1;
    }
    else
    {
        while(~fscanf(user,"%s",t))
        {
            if(!strcmp(t,username))
            {
                flag=0;
                keyword=(char*)malloc(21);
                fscanf(user,"%s",keyword);
                break;
            }
            else
                fscanf(user,"%s",t);
        }
    }
    if(flag)
    {
        printf("\t\t\t�û�������\n\t\t\t");
        system("pause");
        system("cls");
        free(username);
        username=NULL;
        return FALSE;
    }
    int i;
    char inputkey[21];
    for(i=0;i<3;i++)
    {
        pan=0;
        len=0;
        if(i)
            printf("\n");
        printf("\t\t\t����������(�����пո�,ʣ�����%d��,����Ϊ5-20):",3-i);
        while((tmp=getch())!='\r')
        {
            if(tmp=='\b')
            {
                if(len>0)
                {
                    printf("\b \b");
                    len--;
                }
                continue;
            }
            if(tmp==' ')
            {
                pan=1;
                break;
            }
            if(len==20)
            {
                continue;
            }
            printf("*");
            inputkey[len]=tmp;
            len++;
        }
        if(len<5||pan)
        {
            printf("\n\t\t\t����Ƿ�\n");
            continue;
        }
        inputkey[len]='\0';
        if(!strcmp(keyword,inputkey))
        {
            printf("\n\t\t\t��¼�ɹ�\n");
            strcpy(fileuser,username);
            strcat(fileuser,".txt");
            free(username);
            username=NULL;
            free(keyword);
            keyword=NULL;
            sys();
            return TRUE;
        }
        else
            printf("\n\t\t\t�������");
    }
    printf("\n\t\t\t��¼ʧ��\n");
    free(username);
    username=NULL;
    free(keyword);
    keyword=NULL;
    sys();
    return FALSE;
}
int signup()
{
    int len=0,pan=0;
    char tmp;
    printf("\t\t\t�������û���(�����пո�,����Ϊ5-20):");
    username=(char*)malloc(21);
    while((tmp=getchar())!='\n')
    {
        if(tmp==' ')
        {
            pan=1;
            break;
        }
        if(len==20)
        {
            len++;
            break;
        }
        username[len]=tmp;
        len++;
    }
    if(len==21||len<5||pan)
    {
        printf("\t\t\t�û����Ƿ�\n\t\t\t");
        system("pause");
        system("cls");
        return FALSE;
    }
    username[len]='\0';
    char tmpuser[21];
    FILE*tmpfile=fopen(USER,"r");
    int chong=0;
    while(~fscanf(tmpfile,"%s",tmpuser))
    {
        if(!strcmp(tmpuser,username))
        {
            chong=1;
            break;
        }
        else
            fscanf(tmpfile,"%s",tmpuser);
    }
    if(chong)
    {
        printf("\t\t\t�û�%s�Ѵ���\n",username);
        free(username);
        fclose(tmpfile);
        sys();
        return FALSE;
    }
    fclose(tmpfile);
    keyword=(char*)malloc(21);
    char again[21];
    while(1)
    {
        pan=0;
        len=0;
        printf("\t\t\t����������(�����пո�,����Ϊ5-20):");
        while((tmp=getch())!='\r')
        {
            if(tmp=='\b')
            {
                if(len>0)
                {
                    printf("\b \b");
                    len--;
                }
                continue;
            }
            if(tmp==' ')
            {
                pan=1;
                break;
            }
            if(len==20)
            {
                continue;
            }
            printf("*");
            keyword[len]=tmp;
            len++;
        }
        if(len<5||pan)
        {
            printf("\n\t\t\t����Ƿ�\n");
            continue;
        }
        keyword[len]='\0';
        printf("\n\t\t\t���ٴ�ȷ������:");
        len=0;
        pan=0;
        while((tmp=getch())!='\r')
        {
            if(tmp=='\b')
            {
                if(len>0)
                {
                    printf("\b \b");
                    len--;
                }
                continue;
            }
            if(tmp==' ')
            {
                pan=1;
                break;
            }
            if(len==20)
            {
                continue;
            }
            printf("*");
            again[len]=tmp;
            len++;
        }
        if(len<5||pan)
        {
            printf("\n\t\t\t����Ƿ�");
            continue;
        }
        again[len]='\0';
        if(!strcmp(keyword,again))
        {
            printf("\n\t\t\tע��ɹ�");
            printf("\n\t\t\t���Զ���¼\n");
            FILE* pf=fopen(USER,"a+");
            if(!pf)
            {
                printf("%s",strerror(errno));
                return FALSE;
            }
            fprintf(pf,"%s\n%s\n",username,keyword);
            fclose(pf);
            strcpy(fileuser,username);
            strcat(fileuser,".txt");
            free(keyword);
            free(username);
            username=NULL;
            keyword=NULL;
            sys();
            return TRUE;
        }
        printf("\n\t\t\t�����������벻��ͬ,����������\n");
    }
}
void sys()
{
    printf("\t\t\t");
    system("pause");
    system("cls");
    Sleep(200);
}
