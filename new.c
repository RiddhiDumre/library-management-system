#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node
{
    char bid[50];
    char bname[50];
    char author[50];
    int status;
    struct node *next;
} *start = NULL;
struct member
{
    char mid[50];
    char mname[50];
    char dept[50];
    struct member *next;
} *first = NULL;
int flag = 1;
void enter()
{
    int id;
    char name[50];
    printf("\n\nPLEASE ENTER THE EMPLOYEE NAME \n");
    scanf("%s", name);
    while ((strcmp(name, "Siya") != 0) && (strcmp(name, "Riddhi") != 0) && (strcmp(name, "Nisha") != 0))
    {
        printf("PLEASE ENTER THE CORRECT NAME \n");
        scanf("%s", name);
    }
    printf("PLEASE ENTER YOUR ID \n");
    scanf("%d", &id);
    while (id != 182250)
    {
        printf("PLEASE ENTER THE CORRECT PASSWORD \n");
        scanf("%d", &id);
    }
}
void create()
{
    int n, temp;
    printf("Enter the no of books to be added\n");
    scanf("%d", &n);
    if (n < 0)
    {
        flag = 1;
    }
    temp = n;
    while (n > 0)
    {
        struct node *new_node, *cur;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("Enter book name,book id and author \n");
        scanf("%s%s%s", new_node->bname, new_node->bid, new_node->author);
        new_node->status = 1;
        new_node->next = NULL;
        if (start == NULL)
        {
            start = new_node;
        }
        else
        {
            cur = start;
            while (cur->next != NULL)
            {
                cur = cur->next;
            }
            cur->next = new_node;
        }
        n--;
        flag = 0;
    }
    if (flag == 0)
        printf("%d books are added successfully......\n", temp);
    return;
}
void display()
{

    struct node *new_node;
    printf("---BOOK ID---\t---BOOK NAME---\t----AUTHOR---\t----STATUS---\n");
    new_node = start;
    while (new_node != NULL)
    {
        printf("%s\t\t%s\t\t%s\t\t", new_node->bid, new_node->bname, new_node->author);
        if (new_node->status == 1)
            printf("available\n");
        else
            printf("Issued\n");
        new_node = new_node->next;
    }
}
void search()
{
    char bk[50];
    if (flag == 1)
        printf("No books are available in library..\n");
    else
    {
        printf("Enter book name\n");
        scanf("%s", bk);
        struct node *cur;
        cur = start;
        while (cur != NULL)
        {
            if (strcmp(cur->bname, bk) == 0)
            {
                printf("book found\n");
                if (cur->status == 1)
                    printf("available for issue\n");
                else
                    printf("Already issued\n");
                return;
            }
            cur = cur->next;
        }
        printf("No such book available in library\n");
    }
}
void addmember()
{
    char id[50];
    char name[50], dep[50];
    int n, ans;
    printf("\nEnter the number of members to be added\n");
    scanf("%d", &n);
    ans = n;
    if (n == 0)
    {
        return;
    }
    while (n > 0)
    {
        printf("Enter member id,name and department\n");
        scanf("%s%s%s", id, name, dep);
        struct member *temp = NULL;
        temp = first;
    h:
        while (temp != NULL)
        {
            if (strcmp(temp->mid, id) == 0)
            {
                printf("Entered ID is already taken...Enter new ID\n");
                scanf("%s", id);
                goto h;
            }
            temp = temp->next;
        }
        struct member *cur, *last;
        cur = (struct member *)malloc(sizeof(struct member));
        cur->next = NULL;
        if (first == NULL)
        {
            strcpy(cur->mid, id);
            strcpy(cur->mname, name);
            strcpy(cur->dept, dep);
            first = cur;
            last = first;
        }
        else
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            strcpy(cur->mid, id);
            strcpy(cur->mname, name);
            strcpy(cur->dept, dep);
            temp->next = cur;
        }
        n--;
    }
    printf("%d member added successfull...\n\n", ans);
}
void issue()
{
    char temp[50];
    char id[10];
    int tag = 0;
    struct node *cur1;
    cur1 = start;
    struct member *cur;
    cur = first;
    if (cur1 == NULL)
    {
        printf("No books are available in library\n\n");
        return;
    }
    printf("Enter member id\n");
    scanf("%s", id);
    while (cur != NULL)
    {
        if (strcmp(cur->mid, id) == 0)
        {
            tag = 1;
        }
        cur = cur->next;
    }
    if (tag == 0)
    {
        printf("not a member of library\n\n");
        return;
    }
    printf("Enter the name of book to be issued\n");
    scanf("%s", temp);
    {
        while (cur1 != NULL)
        {
            if (strcmp(cur1->bname, temp) == 0)
            {
                printf("book found\n");
                if (cur1->status == 1)
                {
                    printf("available for issue\n");
                    cur1->status = 0;
                    printf("book is issued\n");
                    printf("%s is issued by member whose id is %s\n\n", temp, id);
                    return;
                }
                else
                {
                    printf("Already issued\n\n");
                    return;
                }
            }
            cur1 = cur1->next;
        }
        printf("No such book available in library\\n\n");
        return;
    }
}
void idisplay()
{
    struct member *cur;
    cur = first;
    printf("----MEMBER ID---\t---MEMBER NAME-----\t\t-----DEPARTMENT-----\n");
    while (cur != NULL)
    {
        printf("%s\t\t\t\t%s\t\t\t\t%s\t\t\t\n\n", cur->mid, cur->mname, cur->dept);
        cur = cur->next;
    }
}
int returnbook()
{
    char bk[50];
    struct node *temp1;
    temp1 = start;
    if (temp1 == NULL)
    {
        printf("No books in library...\n\n");
        return 0;
    }
    printf("enter the name of book to be returned\n");
    scanf("%s", bk);
    while (temp1 != NULL)
    {
        if (strcmp(temp1->bname, bk) == 0)
        {
            if (temp1->status == 0)
            {
                temp1->status = 1;
                printf("book is returned\n\n");
                return 0;
            }
            else
            {
                printf("Book is not yet issued\n\n");
                return 0;
            }
        }
        temp1 = temp1->next;
    }
    printf("book does not belong to library\n\n");
}
void main()
{
    int ch;

    enter();
    while (1)
    {
        printf("**************:::::**************");
        printf("WELCOME TO SRN LIBRARY MANAGEMENT SYSTEM");
        printf("**************:::::**************\n");
        printf("1.Add Books\n2.Search Books\n3.View Book List\n4.add a member \n5.IssueBook\n6.Return Books\n7.View Member Lists\n8.Close Application\n\n");

        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            search();
            break;
        case 3:
            display();
            break;
        case 4:
            addmember();
            break;
        case 5:
            issue();
            break;
        case 6:
            returnbook();
            break;
        case 7:
            idisplay();
            break;
        case 8:
            printf("THANK YOU\n");
            return;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}