#include <stdio.h>
#include <stdlib.h>

#include "studentsystem.h"

//��ʼ������,Ϊ����ͷָ�����ռ䣬��ȡѧ����¼����
stuNode* InitLinkList()
{
    stuNode* head = (stuNode*)malloc(sizeof(stuNode));
    head->no = 16;
    strcpy(head->name,"BigData");
    fscanf(fp1,"%d",&head->score);
    head->next = NULL;
    return head;
}

//�����ڵ�
stuNode* ListInsert(int no,char name[MaxSize],int score)
{
    stuNode* newnode = (stuNode*)malloc(sizeof(stuNode));
    newnode->no = no;
    strcpy(newnode->name,name);
    newnode->score = score;
    newnode->next = NULL;
    return newnode;
}

//��������ɾ�����
int DeleteList(stuNode* head,int no)
{
    stuNode *p,*q,*t;
    p = q = t = head->next;
    if (p->no == no)
    {
        head->next = p->next;
        head->score--;
        return 1;
    }
    while(p != NULL)
    {
        if(p->no == no)
        {
            while(q->next != p)
                q = q->next;
            q->next = p->next;
            head->score--;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//�޸Ľ����Ϣ
int ChangeList(stuNode* head,int no,stuNode* t)
{
    stuNode* p,* q;
    p = head->next;
    q = head;
    while(p != NULL)
    {
        if(p->no == no)
        {
            t->next = p->next;
            while(q->next != p)
                q = q->next;
            q->next = t;
            Changeposition(head,no);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//���޸Ĺ��Ľ���������
int Changeposition(stuNode* head,int no)
{
    int k = 0;
    stuNode* p,* q,*t;
    p = t = head->next;
    q = head;
    while(t != NULL)
    {
        if(t->no == no)
        {
            printf("\n\tѧ��:%d",t->no);
            printf("\n\t����:%s",t->name);
            printf("\n\t�ɼ�:%d\n",t->score);
            system("pause");
            break;
        }
        t = t->next;
    }
    while(q->next != t)
        q = q->next;
    while(t != head->next)
    {
        if (q->score < t->score)
        {
            q->next = t->next;
            while(p->next != q)
                p = p->next;
            t->next = q;
            p->next = t;
            q = p;
            k = 1;
        }
        else
            break;
    }
    if(k == 0)
    {
        p = t->next;
        while(p != NULL)
        {
            if (p->score > t->score)
            {
                t->next = p->next;
                while(q->next != t)
                    q = q->next;
                p->next = t;
                q->next = p;
                p = t->next;
            }
            else
                break;
        }
    }
    return 0;
}

//����������
int SearchList(stuNode* head,int no)
{
    stuNode* p = head->next;
    while(p != NULL)
    {
        if(p->no == no)
        {
            printf("\n\tѧ��:%d",p->no);
            printf("\n\t����:%s",p->name);
            printf("\n\t�ɼ�:%d\n",p->score);
            return 1;
        }
        p = p->next;
    }
    return 0;
}

//���ļ����������ļ��ж�ȡѧ����Ϣ������
int Readfile(stuNode* head)
{
    int i = 0;
    if(head->score != 0)
    {
        stuNode *q = head;
        for(i = 0;i < head->score; i++)
        {
            stuNode *p = (stuNode*)malloc(sizeof(stuNode));
            //fread(p,sizeof(stuNode),1,fp3);
            fscanf(fp3,"%d %s %d",&p->no,p->name,&p->score);
            p->next = NULL;
            q->next = p;
            q = q->next;
        }
    }
    return 0;
}

//д�ļ���������ѧ����Ϣ������д���ļ�
int Writefile(stuNode* head)
{
    fprintf(fp2,"%d",head->score);
    stuNode* p = head->next;
    while(p != NULL)
    {
        fprintf(fp4,"%d %s %d\n",p->no,p->name,p->score);
        p = p->next;
    }
    return 0;
}

//�����棬��ʾ�����˵������������ѡ�����
int MainMenu()
{
	int i;
	printf("\t\tWelcome to the System of Student Management\n");
	printf("\n\t\t\t1.Add student's information\n");
	printf("\n\t\t\t2.Delete student's information\n");
	printf("\n\t\t\t3.Change student's information\n");
	printf("\n\t\t\t4.Search student's information\n");
	printf("\n\t\t\t5.Show student's information\n");
	printf("\n\t\t\t6.exit system\n\n");
	printf("\tPlease input you choose:");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			system("cls");
			Add(Head);
			break;
		case 2:
			system("cls");
			Delete();
			break;
		case 3:
			system("cls");
			Change();
			break;
		case 4:
			system("cls");
			Search();
			break;
		case 5:
			system("cls");
			Show(Head);
			break;
		case 6:
			system("cls");
			exitsystem();//
			break;
		default:
			break;
	}
	return 0;
}

//���ѧ����Ϣ
int Add(stuNode *head)
{
    int no,score;
    char name[MaxSize];
    stuNode* p = head->next;
    stuNode* q = head->next;
    stuNode* n;
    printf("\n\tPlease input student's NO:");
    scanf("%d",&no);
    printf("\n\tPlease input student's name:");
    scanf("%s",name);
    printf("\n\tPlease input student's score:");
    scanf("%d",&score);
    n = ListInsert(no,name,score);
    if (p == NULL) //�����п�
        head->next = n;
    else
    {
        while(p != NULL )
        {
            if(p->score <= score)
                break;
            p = p->next;
        }
        if(p != NULL)
        {
            if(p == q)
            {
                n->next = p;
                head->next = n;
            }
            else
            {
                while(q->next != p)
                {
                    q = q->next;
                }
                n->next = p;
                q->next = n;
            }
        }
        else
        {
            while(q->next != NULL)
                q = q->next;
            q->next = n;
        }
    }
    head->score++;
    return 0;
}

//ɾ��ѧ����Ϣ
int Delete()
{
    int i,n;
    printf("\tPlease input the No of student's which you want delete:");
    scanf("%d",&i);
    n = DeleteList(Head,i);
    if(n)
    {
        printf("\n\tɾ���ɹ�\n");
        system("pause");
        return 0;
    }
    printf("\n\tû���ҵ���ѧ���ļ�¼\n");
    system("pause");
    return 0;
}

//�޸�ѧ����Ϣ
int Change()
{
    int i,x;
    stuNode *n = (stuNode*)malloc(sizeof(stuNode));
    printf("������Ҫ�޸ĵ�ѧ����ѧ��:");
    scanf("%d",&i);
    printf("�������޸ĺ�ѧ������Ϣ\n");
    n->no = i;
    printf("������ѧ������:");
    scanf("%s",n->name);
    printf("������ѧ���ɼ�:");
    scanf("%d",&n->score);
    n->next = NULL;
    x = ChangeList(Head,i,n);
    if(x)
    {
        printf("\n\t�޸ĳɹ�\n");
        system("pause");
        return 0;
    }
    printf("\n\tû���ҵ���ѧ���ļ�¼\n");
    system("pause");
    return 0;
}

//����ѧ����Ϣ
int Search()
{
    int n,no;
    printf("������Ҫ��ѯ��ѧ��ѧ��:");
    scanf("%d",&no);
    n = SearchList(Head,no);
    if(n == 0)
        printf("\n\tû���ҵ���ѧ���ļ�¼\n");
    system("pause");
    return 0;
}

//��ʾ����ѧ����Ϣ
int Show(stuNode* head)
{
    printf("\t�꼶:%d��\t�༶:%s\t����:%d\n\n",head->no,head->name,head->score);
    stuNode* p = head->next;
    while(p != NULL)
    {
        printf("%d\t%s\t%d\n\n",p->no,p->name,p->score);
        p = p->next;
    }
    printf("������ȫ��ѧ����Ϣ\n");
    system("pause");
    return 0;
}

//ϵͳ��ʼ��,���ļ�����ʼ������ͷָ�룬��ȡѧ����Ϣ
int SystemInit()
{
    fp1 = fopen("StuNum.txt","r+");
    fp2 = fopen("StuNu.txt","w+");
	fp3 = fopen("StuInformation.txt","r+");
	fp4 = fopen("StuIn.txt","w+");
	Head = InitLinkList();
	Readfile(Head);
    return 0;
}

//�˳�ϵͳ����,�洢��Ϣ���ر��ļ�,�ͷ�����ռ䲢�˳�����
int exitsystem()
{
    Writefile(Head);
	fclose(fp1);
	fclose(fp2);
	remove("StuNum.txt");
	rename("StuNu.txt","StuNum.txt");
	fclose(fp3);
	fclose(fp4);
	remove("StuInformation.txt");
	rename("StuIn.txt","StuInformation.txt");
	exit(0);
}
