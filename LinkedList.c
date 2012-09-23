
#include<stdio.h>
#include<conio.h>
//#include<iostream.h>
#define NULL 0
struct list
{
	int value;
	struct list *link;
};
typedef struct list node;
void create(node *a,int c1);
int search(node *a,int x);
void ins(node *a,int n,int p);
void del(node *a,int x);
int count(node *a);
void display(node *a);
void main()
{

	node *head;

	int ch,c,x,n,o,p,z,c1,ct;
	clrscr();
	do
	{
	printf("Enter ur choice :\n1.Create\n2.search\n3.Insert\n4.Delete\n5.Count\n");
	scanf("%d",&c);
	switch(c)
	{
	case 1:
	       head=(node*)malloc(sizeof(node));
		printf("\nHow many nos values r u going to give : ");
		scanf("%d",&c1);
	       create(head,c1);
	       display(head);
	       break;
	case 2:
		//int x;
		printf("\nEnter the value to search : ");
		scanf("%d",&x);
		o=search(head,x);
		if(o==1)
		  printf("%d is present in the list..",x);
		else
		  printf("%d is not present in the list..",x);
		break;
	case 3:
		//int n,p;
		printf("Enter a value to insert : ");
		scanf("%d",&n);
		printf("\nEnter the previous node : ");
		scanf("%d",&p);
		ins(head,n,p);
		display(head);
		break;
	case 4:
		//int z;
		printf("Enter a value to delete : ");
		scanf("%d",&z);
		del(head,z);
		display(head);
		break;
	case 5:
		ct=count(head);
		printf("\nThere r totally %d lists..",ct);
		break;
	default:
		printf("Wrong choice ") ;
		break;
	}
	printf("\nDo u want to continue ?\n1.Yes \t 2.No :");
	scanf("%d",&ch);
	}while(ch!=2);
	getch();
}
void create(node *a,int c1)
{
	int i,j=1;
	//for(j=1;j<=c1;j++)
	//{
	if(j<=c1)
	{
	 printf("\nEnter a value to add : ");
	 scanf("%d",&i);
	 if(j==c1)
	 {
	   a->value=i;
	   a->link=NULL;

	 }
	 else
	 {
	   a->value=i;
	   a->link=(node*)malloc(sizeof(node));
	   create(a->link,c1-1);
	 }
	 }
      //}
}
int search(node *a,int x)
{
       //	int j=0;
//	while(a!=NULL)
//	{
	if(a!=NULL)
	{
	    if(a->value==x)
	    {
	       //	printf("%d is present in the list..",x);
	       //	j=1;
		return 1;
	    }
	    else
	    {
		a=a->link;
		search(a,x);
	    }
	    /*if(j==0)
	    {
	    printf("%d is not present in the list..",x);
	    return;
	    }  */
	    }
	    else
	      return 0;

//	}
}
void ins(node *a,int n,int p)
{
       //	int p;
	node *t1,*t2;

	if(a->value==p)
	{
	     t1=a->link;
	     t2=(node*)malloc(sizeof(node));
	     t2->value=n;
	     t2->link=t1;
	     a->link=t2;
	}
	else
	{
		a=a->link;
		ins(a,n,p);
	}
}
void del(node *a,int x)
{
	node *t=a;
	while(a->link!=NULL)
	{
		if(a->value==x)
		{
		  t->link=a->link;
		  //a=t;
		  return;
		}
		t=a;
		a=a->link;
	}
}
int count(node *a)
{
	if(a!=NULL)
	{
	   a=a->link;
	   return 1+count(a);
	}else
	return 0;
}
void display(node *a)
{
	printf("\n");
	while(a!=NULL)
	{
		printf("%d\t",a->value);
		a=a->link;
	}
}

