#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<conio.h>

struct vehicle
{
    int no;
    struct vehicle * next;
};

struct vehicle *head1=NULL,*head2=NULL,*head3=NULL;

int s1=500,s2=100,s3=50;
int c1=0,c2=0,c3=0;

void * twoWheeler(int t)
{
    struct vehicle *curr,*s;

    s = (struct vehicle *)malloc(sizeof(struct vehicle));
    s->no = t;
    s->next = NULL;

    if(head1==NULL)
    {
        head1=s;
    }
    else
    {
        curr=head1;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=s;
    }
    c1++;
}

int twoWheelerExits(int t)
{
    struct vehicle *temp,*curr=NULL;
    curr=head1;
    if(head1->no==t)
    {
        temp=head1;
        head1=head1->next;
    }
    else
    {
        while(curr->next!=NULL && curr->next->no!=t)
        {
            curr=curr->next;
        }
        if(curr->next==NULL)
        {
            return -1;
        }
        temp=curr->next;
        curr->next=temp->next;
    }
    free(temp);
    c1--;
    return 1;
}

void * fourWheeler(int t)
{
    struct vehicle *curr,*s;

    s = (struct vehicle *)malloc(sizeof(struct vehicle));
    s->no = t;
    s->next = NULL;

    if(head2==NULL)
    {
        head2=s;
    }
    else
    {
        curr=head2;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=s;
    }
    c2++;
}

int fourWheelerExits(int t)
{
    struct vehicle *temp,*curr=NULL;
    curr=head2;
    if(head2->no==t)
    {
        temp=head2;
        head2=head2->next;
    }
    else
    {
        while(curr->next!=NULL && curr->next->no!=t)
        {
            curr=curr->next;
        }
        if(curr->next==NULL)
        {
            return -1;
        }
        temp=curr->next;
        curr->next=temp->next;
    }
    free(temp);
    c2--;
    return 1;
}


void * heavyVehicle(int t)
{
    struct vehicle *curr,*s;

    s = (struct vehicle *)malloc(sizeof(struct vehicle));
    s->no = t;
    s->next = NULL;

    if(head3==NULL)
    {
        head3=s;
    }
    else
    {
        curr=head3;
        while(curr->next!=NULL)
        {
            curr=curr->next;
        }
        curr->next=s;
    }
    c3++;
}

int heavyVehicleExits(int t)
{
    struct vehicle *temp,*curr=NULL;
    curr=head3;

    if(head3->no==t)
    {
        temp=head3;
        head3=head3->next;
    }
    else
    {
        while(curr->next!=NULL && curr->next->no!=t)
        {
            curr=curr->next;
        }
        if(curr->next==NULL)
        {
            return -1;
        }
        temp=curr->next;
        curr->next=temp->next;
    }
    free(temp);
    c3--;
    return 1;
}


int main()
{
    int ans1,ans2,no;

    do{
    printf("\n\n\n FARE \n");
    printf("Two Wheeler : 50\n");
    printf("Four Wheeler : 80\n");
    printf("Heavy Vehicle : 120\n");
    printf("\nEnter your choice \n");
    printf("1. Entry into Parking lot\n");
    printf("2. Exit from Parking lot\n");
    printf("5. Exit program\n");
    scanf("%d",&ans1);

    switch(ans1)
    {
        case 1: printf("\nPress 1 for Two Wheeler\nPress 2 for Four Wheeler\nPress 3 for Heavy Vehicles\n");
                scanf("%d",&ans2);

                switch(ans2)
                {
                    case 1: if(c1!=s1)
                            {
                                printf("Parking Space Available\n");
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                twoWheeler(no);
                                printf("Vehicle parked successfully\n");
                            }
                            else
                            {
                                printf("Parking Space Not Available, Sorry :\(\n");
                            }
                            break;
                    case 2: if(c2!=s2)
                            {
                                printf("Parking Space Available\n");
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                fourWheeler(no);
                                printf("Vehicle parked successfully\n");
                            }
                            else
                            {
                                printf("Parking Space Not Available, Sorry :\(\n");
                            }
                            break;
                    case 3: if(c3!=s3)
                            {
                                printf("Parking Space Available\n");
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                heavyVehicle(no);
                                printf("Vehicle parked successfully\n");
                            }
                            else
                            {
                                printf("Parking Space Not Available, Sorry :\(\n");
                            }
                            break;
                    default:printf("Invalid choice\n");
                }

                break;

        case 2: printf("Press 1 for Two Wheeler\nPress 2 for Four Wheeler\nPress 3 for Heavy Vehicles\n");
                scanf("%d",&ans2);

                int r;

                switch(ans2)
                {
                    case 1: if(c1==0)
                            {
                                printf("There is no vehicle in the parking area\n");
                            }
                            else
                            {
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                r=twoWheelerExits(no);
                            }
                            break;

                    case 2: if(c2==0)
                            {
                                printf("There is no vehicle in the parking area\n");
                            }
                            else
                            {
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                r=fourWheelerExits(no);
                            }
                            break;

                    case 3: if(c3==0)
                            {
                                printf("There is no vehicle in the parking area\n");
                            }
                            else
                            {
                                printf("Enter the vehicle no\n");
                                scanf("%d",&no);
                                r=heavyVehicleExits(no);
                            }
                            break;

                    default:printf("Invalid choice\n");
                }
                if(r==1)
                {
                    printf("Vehicle with vehicle no %d exited\n",no);
                }
                else if(r==-1)
                {
                    printf("No such vehicle found with vehicle no. %d\n",no);
                }
                break;

        default : if(ans1!=5)
                  {
                      printf("Invalid choice\n");
                  }

    }
    getch();
    }while(ans1!=5);


    getch();
}
