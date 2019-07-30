#include <stdio.h>
#include <string.h>
#define MaxSize 26

//声明文件指针
FILE *fp1,*fp2,*fp3,*fp4;

//链表节点，存放学生信息
typedef struct studentNode
{
	int no;
	char name[MaxSize];
	int score;
	struct studentNode *next;
}stuNode;

////结构体数组
//stu Stu[MaxSize];

//链表头指针
stuNode* Head;

//初始化链表
stuNode* InitLinkList();

//新建结点
stuNode* ListInsert(int no,char name[MaxSize],int score);

//删除结点
int DeleteList(stuNode* head,int no);

//修改结点信息
int ChangeList(stuNode* head,int no,stuNode*);

//改变新修改结点位置
int Changeposition(stuNode* head,int no);

//查找结点
int SearchList(stuNode* head,int no);

//读文件
int Readfile(stuNode* head);

//写文件
int Writefile(stuNode* head);

//主界面
int MainMenu();

//添加
int Add(stuNode *head);

//删除
int Delete();

//修改
int Change();

//查找
int Search();

//显示学生信息
int Show(stuNode* head);

//系统初始化
int SystemInit();

//退出系统
int exitsystem();
