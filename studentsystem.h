#include <stdio.h>
#include <string.h>
#define MaxSize 26

//�����ļ�ָ��
FILE *fp1,*fp2,*fp3,*fp4;

//����ڵ㣬���ѧ����Ϣ
typedef struct studentNode
{
	int no;
	char name[MaxSize];
	int score;
	struct studentNode *next;
}stuNode;

////�ṹ������
//stu Stu[MaxSize];

//����ͷָ��
stuNode* Head;

//��ʼ������
stuNode* InitLinkList();

//�½����
stuNode* ListInsert(int no,char name[MaxSize],int score);

//ɾ�����
int DeleteList(stuNode* head,int no);

//�޸Ľ����Ϣ
int ChangeList(stuNode* head,int no,stuNode*);

//�ı����޸Ľ��λ��
int Changeposition(stuNode* head,int no);

//���ҽ��
int SearchList(stuNode* head,int no);

//���ļ�
int Readfile(stuNode* head);

//д�ļ�
int Writefile(stuNode* head);

//������
int MainMenu();

//���
int Add(stuNode *head);

//ɾ��
int Delete();

//�޸�
int Change();

//����
int Search();

//��ʾѧ����Ϣ
int Show(stuNode* head);

//ϵͳ��ʼ��
int SystemInit();

//�˳�ϵͳ
int exitsystem();
