#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int coeff;
	int power;
	struct node *next;
}node;
node * getnode(int,int);
void traverse(node *);
node * addlast(node *,int,int);
node * merge(node *,node *);
node * input1(node *);
node * input2(node *);
int main()
{
	node *start=NULL;
	node *l1=NULL,*l2=NULL,*l3;
	l3=merge(l1,l2);
	traverse(l3);
	return 0;
}
node *getnode(int a,int x)
{
	node *t=(node *)malloc(sizeof(node));
	t->coeff=a;
	t->power=x;
	return t;
}
void traverse(node *start)
{
	printf("\nLinked List is:  \n");
	node *ptr=start;
	while(ptr!=NULL)
	{
		printf("%dx^", ptr->coeff);
		printf("%d + ", ptr->power);
		ptr=ptr->next;
	}
	printf("\n");
}
node *addlast(node *start,int a,int x)
{
	node *newnode;
	newnode=getnode(a,x);
	newnode->next=NULL;
	if(start==NULL)
	{
		start=newnode;
	}
	else
	{	node *ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
	return start;
}
node *merge(node *l1,node *l2)
{
	l1=input1(l1);
	l2=input2(l2);
	printf("\nAdded Linked List is\n");
	node *l3=NULL;
	while(l1!=NULL && l2!=NULL)
	{
		
		if(l1->power > l2->power)
		{
			l3=addlast(l3,l1->coeff,l1->power);
			l1=l1->next;
		}
		else if(l2->power > l1->power)
		{
			
			l3=addlast(l3,l2->coeff,l2->power);
			l2=l2->next;
		}
		else if(l1->power == l2->power)
		{
			l3=addlast(l3,l1->coeff+l2->coeff,l1->power);
			l1=l1->next;
			l2=l2->next;
		}
	}
	while(l1!=NULL)
	{
		l3=addlast(l3,l1->coeff,l1->power);
		l1=l1->next;
	}
	while(l2!=NULL)
	{
		l3=addlast(l3,l2->coeff,l2->power);
		l2=l2->next;
	}
	return l3;
	
}
node *input1(node *l1)
{
	int n1,i,a,x;
	i=1;
	printf("Enter the number of terms you want to add in polynomial 1\n");
	scanf("%d",&n1);
	printf("Enter the coeffecient and power of polynomial 1\n");
	while(i<=n1)
	{
		scanf("%d %d",&a,&x);
		l1=addlast(l1,a,x);
		i++;
	}
	traverse(l1);
	return l1;
}
node *input2(node *l2)
{
	int n2,j,a,x;
	j=1;
	printf("Enter the numners of terms you want to add in polynimal 2\n");
	scanf("%d",&n2);
	printf("Enter the coeffecient and power of polynomial 2\n");
	while(j<=n2)
	{
		scanf("%d %d",&a,&x);
		l2=addlast(l2,a,x);
		j++;
	}
	traverse(l2);
	return l2;
}

