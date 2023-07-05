#include <stdio.h>
#include <malloc.h>

#define ElemType int
#define Link_is_Empty 1
#define Link_no_Empty 0
typedef struct DListNode{
    ElemType data;
    struct DListNode *next;
    struct DlistNode *previous;
}DListNode;

//双向链表头指针
DListNode *pHead = NULL;
//双向链表尾指针
DListNode *pEnd = NULL;

//创建双向链表节点
void CreatNode(DListNode *pNode){
    if(NULL != pNode){
        printf("请输入节点数据：");
        scanf("%d",&pNode->data);
    }
    pNode->next = NULL;
    pNode->previous = NULL;
    
}

void CreateLinkList(){
    DListNode *pNew = malloc(sizeof(DListNode));
    pNew->next = NULL;
    pNew->previous = NULL;
    pNew->data = -1;

    pHead = pNew;
    pEnd = pNew;
    printf("创建成功！\n");
}

//添加节点
void AddNode(){
    DListNode *pTemp = pEnd;
    DListNode *pNew = malloc(sizeof(DListNode));
    CreatNode(pNew);
    pEnd->next = pNew;
    pEnd = pNew;
    pEnd->previous = pTemp;

}

//判断链表是否为空
int IsEmpty(){
    if (NULL == pHead->next && NULL == pHead->previous)
    {
        printf("链表为空");
        return Link_is_Empty;
    }
    return Link_no_Empty;
}

//输出双向链表
void ShowDLinkNode(){
    if (IsEmpty())
    {
        return;
    }
    
    DListNode *pTemp = pEnd;
    printf("输出的单链表：");
    while (pHead != pTemp)
    {
        printf("%d ",pTemp->data);
        pTemp = pTemp->previous;
    }
    printf("\n");
}

//双向链表中查看某个节点
DListNode* SreachNode(int target){
    if (IsEmpty())
    {
        return NULL;
    }
    DListNode *pTemp = pEnd;
 
    while (pHead != pTemp)
    {
        /* code */
        if (pTemp->data == target)
        {
            return pTemp;
        }
        pTemp = pTemp->previous;

        
    }
    return NULL;//未找到
    
}

//修改双向链表的值
void ModifyNode(ElemType e){
    if (IsEmpty())
    {
        /* code */
        return;
    }
    DListNode *pTemp = SreachNode(e);
    if (pTemp!=NULL)
    {
        /* code */
        printf("请输入新数据：");
        scanf("%d",&pTemp->data);
        printf("修改数据成功！\n");
    }
    else
    {
        printf("未找到数据");
    }
    
    
}



int main(int argc, char const *argv[])
{
    printf("********************************************\n");
	printf("*                  功能菜单                *\n");
	printf("* 1 创建双向链表           2 顺序添加新结点*\n");
	printf("* 3 修改结点               4 查找结点      *\n");
	printf("* 5 任意位置插入结点       6 删除某结点    *\n");
	printf("* 7 清空整个双向链表       8 打印单向链表  *\n");
	printf("********************************************\n");

    while (1)
    {
        /* code */
        int choice;
		printf("请输入功能序号：");
		scanf("%d" ,&choice);
		switch(choice)
		{
		case 1:
			{
				CreateLinkList();
				break;
			}
		case 2:
			{
				AddNode();
				break;
			}
		case 3:
			{
				int e;
				printf("请输入要修改的结点：");
				scanf("%d", &e);
				ModifyNode(e);
				break;
			}
		case 4:
			{
				break;
			}
		case 5:
			{
				int e, type;
				printf("请输入要插入的位置和插入方式(两个数据之间用空格分开)：");
				scanf("%d %d", &e, &type);
				// InsertNode(e, type);
				break;
			}
		case 6:
			{
				int e;
				printf("请输入要删除的结点：");
				scanf("%d", &e);
				// DeleteNode(e);
				break;
			}
		case 7:
			{
				// ClearLinkList();
				break;
			}
		case 8:
			{
				ShowDLinkNode();
				break;
			}
		default:
			printf("error");
		}//end of switch

    }//end of while
    
    return 0;
}
