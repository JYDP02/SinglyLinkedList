#include<stdio.h>
#include<stdlib.h>
struct node
{
    int ele;
    struct node *next;
}*head=NULL,*p,*q,*temp,*new_node;
int count()
{
    int c=0;
    p=head;
    while(p!=NULL)
    {
            c++;
            p=p->next;
    }
    return(c);
}
void display()
{
    p=head;
    if(head==NULL)
        printf("\nList is empty");
    else
    {
        printf("\nElements are\t");
        while(p!=NULL)
        {
            printf("\t%d",p->ele);
            p=p->next;
        }
    }
}
void search()
{
    int a,b=0;
    printf("\nEnter the element to be find\t");
    scanf("%d",&a);
    p=head;
    while(p!=NULL)
    {
        if(p->ele==a)
        {
            b=1;
            break;
        }
        else
            b=0;
        p=p->next;
    }
    if(b==1)
        printf("\n%d is found",a);
    else
        printf("\n%d is not found",a);

}
struct node*create(int x)
{
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->ele=x;
    new_node->next=NULL;
    return new_node;
}
void insert(int x)
{
    int pos,no,i;
    if(head==NULL)
    {
        head=create(x);
    }
    else
    {
        no=count();
        printf("\nEnter the position\t");
        scanf("%d",&pos);
        if(pos==1)
        {
            temp=create(x);
            temp->next=head;
            head=temp;
        }
        else if(pos==no+1)
        {
            temp=create(x);
            p=head;
            while(p->next!=NULL)
                p=p->next;
            p->next=temp;
        }
        else
        {
            p=head;
            temp=create(x);
            for(i=1;i<pos-1;i++)
            {
                p=p->next;
            }
            temp->next=p->next;
            p->next=temp;
        }
    }
}
void delete_node()
{
    int pos,no,i;
    if(head==NULL)
        printf("\nList empty");
    else
    {
        printf("\nEnter in which position you need to delete\t");
        scanf("%d",&pos);
        no=count();
        if(pos==1)
        {
            p=head;
            head=head->next;
            free(p);
        }
        else if(pos==no+1)
        {
            p=head;
            while(p->next->next!=NULL)
                p=p->next;
            q=p->next;
            p->next=NULL;
            free(q);
        }
        else
        {
            p=head;
            for(i=1;i<pos-1;i++)
                p=p->next;
            q=p->next;
            p->next=q->next;
            free(q);
        }
    }
}
int main()
{
    int ch,x,c,op;
    do
    {
        printf("\nEnter the choice\n1.Insertion\n2.Deletion\n3.Searching\n4.Display\n5.No of nodes\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter the element\t");
                    scanf("%d",&x);
                    insert(x);break;
            case 2:delete_node();break;
            case 3:search();break;
            case 4:display();break;
            case 5:c=count();printf("\nNo of nodes is %d",c);break;
        }
        printf("\nEnter 1 to continue\t");
        scanf("%d",&op);
    }while(op==1);
    return 0;
}
