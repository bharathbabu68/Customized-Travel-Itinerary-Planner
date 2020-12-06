//Mini project
//Implementing travel planner

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

typedef struct{int rating; char name[30]; int cost;}hotel;

typedef struct node{int data;struct node *left; struct node *right;char loc[90];int id; char prodcode[6]; int offprice;}node;

typedef struct{int cost; char loc[90]; int id;}stud;

typedef struct{char dest[90]; int tcost; int tpeople;}recent;

typedef struct nodell{int idno; char name[40]; int age;struct nodell *next; char pref[40]; int stat;}nodell;

typedef struct{hotel vals[10]; int front; int rear;}queue;

typedef struct{recent vals[10]; int top;}stack;


void initstack(stack *st)
{
	st->top=-1;
}

int isemptystack(stack st)
{
	return st.top==-1;
}
int isfullstack(stack st)
{
	return st.top==9;
}

void pushstack(stack *st, int npersons, int price ,char loca[])
{	
	if(!isfullstack (*st))
	{
	st->top+=1;
	strcpy(st->vals[st->top].dest,loca);
	st->vals[st->top].tcost=price;
	st->vals[st->top].tpeople=npersons;
	}
	
}
recent popstack(stack *st)
{	
	if(!isemptystack(*st))
	{
	recent x=st->vals[st->top];
	st->top-=1;
	return x;
	}
}


void initq(queue *q1)
{
	q1->front=-1;
	q1->rear=-1;
}

int isfull(queue q1)
{
	return q1.rear-q1.front==10;
}

int isempty(queue q1)
{
	return q1.rear-q1.front==0;
}

void push(queue *q1, int stars, int price ,char hname[30])
{
	if(!isfull(*q1))
	{
		q1->rear+=1;
		q1->vals[q1->rear].rating=stars;
		q1->vals[q1->rear].cost=price;
		strcpy(q1->vals[q1->rear].name,hname);
	}
	else 
	printf("\nfull");
}

hotel pop(queue *q1)
{
	if(!isempty(*q1))
	{
		q1->front+=1;
		hotel x=q1->vals[q1->front];
		return x;
	}
	else
	printf("\nempty");
}



nodell *createll(int age1, int idno1, char name1[], char food[])
{
	nodell *p;
	p=(nodell*)malloc(sizeof(nodell));
	p->age=age1;
	strcpy(p->name,name1);
	p->idno=idno1;
	strcpy(p->pref,food);
	if(age1<=12)
	p->stat=1;
	else
	p->stat=0;
	p->next=NULL;
	return p;
}

nodell *insertatendll(nodell*n,int age1, int idno1, char name1[], char food[])
{
		if(!n)
		return createll(age1,idno1,name1,food);
		nodell *q=n;
		while(q->next!=NULL)
		{
			q=q->next;
		}
		nodell *r=createll(age1,idno1,name1,food);
		q->next=r;
		return n;
	
}

nodell *deletell(nodell *n,int pos)
{
		nodell *s=n;
		int i=1;
		while(i<pos-1)
		{
			s=s->next;
			i++;
		}
		nodell *t=s->next;
		s->next=t->next;
		return n;
	
}
/*
int searchll(nodell *n,int data1)
{
	
		nodell *m=n;
		int i=0;
		if(m->data==data1)
		return 1;
		while(m->next!=NULL)
		{
			m=m->next;
			if(m->data==data1)
			return 1;
		}
		return 0;
	}
*/


void displayllfinal(nodell *n)
{
	nodell *p=n;
	if(!p)
	printf("\n List has not been created");
	else
	{
	int i=1;
	int cnt3=0;
	while(p)
	{
		printf("\n|");
		printf("\n|");
		printf("\n|                    Details of person %d               ",i);
		printf("\n|                    Name:%s                            ",p->name);
		printf("\n|                    Age:%d                             ",p->age);
		printf("\n|                    ID Number:%d                       ",p->idno);
		if(strcmp(p->pref,"v")==0)
		printf("\n|                    Food preference:Vegetarian         ");
		else if(strcmp(p->pref,"nv")==0)
		printf("\n|                    Food preference:Non-vegetarian     ");
		else 
		printf("\n|                    Food preference:No-food required   ");
		if(p->stat==0)
		printf("\n|                    Ticket: adult fare applicable      ");
		else 
		{
		printf("\n|                    Ticket: Child fare applicable      ");
			cnt3++;
		}
		i++;
		p=p->next;
	}
	    printf("\n|");
	//printf("\nNo of children is %d",cnt3);
	
	
	}
	
}


int displayll(nodell *n)
{
	nodell *p=n;
	if(!p)
	printf("\n List has not been created");
	else
	{
	int i=1;
	int cnt3=0;
	while(p)
	{
		printf("\n\n");
		printf("\nDetails of person %d",i);
		printf("\nName:%s",p->name);
		printf("\nAge:%d",p->age);
		printf("\nID Number:%d",p->idno);
		if(strcmp(p->pref,"v")==0)
		printf("\nFood preference:Vegetarian");
		else if(strcmp(p->pref,"nv")==0)
		printf("\nFood preference:Non-vegetarian");
		else 
		printf("\nFood preference:No-food required");
		if(p->stat==0)
		printf("\nTicket: adult fare applicable");
		else 
		{
			printf("\nTicket: Child fare applicable");
			cnt3++;
		}
		i++;
		p=p->next;
	}
	printf("\n");
	//printf("\nNo of children is %d",cnt3);
	
	return cnt3;
	}
	return 0;
}

node *create(int data1,char loca[],int id1)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->data=data1;
	strcpy(p->loc,loca);
	p->id=id1;
	int m=id1;
	int cn=4,x;
	char nos[6];
	while(m!=0)
	{
		x=m%10;
		m=m/10;
		x=x+'0';
		nos[cn]=x;
		cn--;
    }
    nos[5]='\0';
    cn=0;
     while(nos[cn]!='\0')
	{
		nos[cn]=nos[cn]+25;
		cn++;
	}
    strcpy(p->prodcode,nos);
    if(p->data>30000)
    p->offprice=p->data-10000;
    else
    p->offprice=p->data-5000;
	p->left=NULL;
	p->right=NULL;
	return p;
}


node* sortedArrayToBST(stud arr[], int start, int end) 
{ 
	/* Base Case */
	if (start > end) 
	return NULL; 

	int mid = (start + end)/2; 
	node *root = create(arr[mid].cost,arr[mid].loc,arr[mid].id); 

	root->left = sortedArrayToBST(arr, start, mid-1); 

	root->right = sortedArrayToBST(arr, mid+1, end); 

	return root; 
} 

/*node *insert(node *n, int data2, char loca[])
{
	node *p=n;
	//node *temp=create(data2,loca);
	if(!n)
	//return temp;
	if(data2<n->data)
	n->left=insert(n->left,data2,loca);
	else if(data2>n->data)
	n->right=insert(n->right,data2,loca);
	return n;
}
*/

void inord(node *n)
{
	if(n){
	inord(n->left);
	printf("\nCost:%3d",n->data);
	printf("\tLocation :%s",n->loc);
	printf("\tID---<%d>",n->id);
	printf("\tPromocode:<%s>",n->prodcode);
	printf("\t\toffer price:%d",n->offprice);
	inord(n->right);
	}

}

void inord2(node *n,int src)
{
	if(n){
	inord2(n->left,src);
	printf("\n%3d",n->data);
	printf("----->%s",n->loc);
	printf("-----<%d>",n->id);
	inord2(n->right,src);
	}
	
}
	


node *search(node *n,int bud)   //to return the plan chosen using id fron tree
{
	
	if(!n)
	{
	printf("\n****ERROR Not found****");
	return NULL;
	}
	if(n->id==bud)
	{
	return n;
	}
	if(n->id > bud)
	return search(n->left,bud);
	if(n->id < bud)
	return search(n->right,bud);
	
}


node *searchbycost(node *n,int bud)   
{
	
	if(n==NULL)
	{
	return NULL;
	}
	if(n->data==bud)
	{
	printf("\nLocation:%s ",n->loc);
	if(n->data > 30000)
	{
		printf("\nCongrats, You have received an offer of 15 percent");
		printf("\nOffer price is:%d",n->offprice);
		return n;
	}
	else
	{
		printf("\nCongrats, You have received an offer of 5 percent");
		printf("\nOffer price is:%d",n->offprice);
		return n;
	}
	}
	if(n->data > bud)
	return searchbycost(n->left,bud);
	if(n->data < bud)
	return searchbycost(n->right,bud);
}

void merge(stud a[],int l,int m,int r, int choice)
{
    int i=l,j=m+1,k=l;
    stud res[100];
    if(choice==1)
    {
    while(i<=m && j<=r)
    {
    
        if(a[i].cost<=a[j].cost)
        {
            res[k].cost=a[i].cost;
            strcpy(res[k].loc,a[i].loc);
           	res[k].id=a[i].id;
           	
            k++;
            i++;
           }
        else
           {
            res[k].cost=a[j].cost;
             strcpy(res[k].loc,a[j].loc);
           	 res[k].id=a[j].id;
            k++;
            j++;
            }
    }
    while(i<=m)
        {
         res[k].cost=a[i].cost;
            strcpy(res[k].loc,a[i].loc);
          	res[k].id=a[i].id;
            k++;
            i++;
           }
    while(j<=r)
       {
         res[k].cost=a[j].cost;
            strcpy(res[k].loc,a[j].loc);
          	res[k].id=a[j].id;
            k++;
            j++;
           }
    for(i=l;i<=r;i++)
      {
        a[i].cost=res[i].cost;
        strcpy(a[i].loc,res[i].loc);
       a[i].id=res[i].id;
    
      }
}
else if(choice==2)
{
	 while(i<=m && j<=r)
	 {
	 if(a[i].id <= a[j].id)
        {
            res[k].cost=a[i].cost;
            strcpy(res[k].loc,a[i].loc);
           	res[k].id=a[i].id;
           	
            k++;
            i++;
           }
        else
           {
            res[k].cost=a[j].cost;
             strcpy(res[k].loc,a[j].loc);
           	 res[k].id=a[j].id;
            k++;
            j++;
            }
    }
    while(i<=m)
        {
         res[k].cost=a[i].cost;
            strcpy(res[k].loc,a[i].loc);
          	res[k].id=a[i].id;
            k++;
            i++;
           }
    while(j<=r)
       {
         res[k].cost=a[j].cost;
            strcpy(res[k].loc,a[j].loc);
          	res[k].id=a[j].id;
            k++;
            j++;
           }
    for(i=l;i<=r;i++)
      {
        a[i].cost=res[i].cost;
        strcpy(a[i].loc,res[i].loc);
       a[i].id=res[i].id;
    
      }
      

}
}

void divide_and_conquer(stud *a,int l,int r,int ch)
{
    if(r>l)
    {
        int m=(l+r)/2;
        divide_and_conquer(a,l,m,ch);
        divide_and_conquer(a,m+1,r,ch);
        merge(a,l,m,r,ch);
    }

}

int codetoplanid(char x[])
{
	int codecnt=4,nocode=0,i=0;
	while(x[i]!='\0')
		{
			x[i]=x[i]-25;
			x[i]=x[i]-'0';
			nocode+=pow(10,codecnt)*x[i];
			i++;
			codecnt--;
			//printf("\nchecker");
		}
		return nocode;
	}

void Print(struct node *root, int k1, int k2) 
{ 
	if ( NULL == root ) 
      return; 
	if ( k1 < root->data ) 
     Print(root->left, k1, k2); 
    if ( k1 <= root->data && k2 >= root->data ) 
   {
    printf("\n|-----%3d",root->data);
    printf("-----|  %3d",root->id);
	printf("  |  %s |",root->loc);
}
   if ( k2 > root->data ) 
     Print(root->right, k1, k2); 
} 




int main()
{
	int ndays=4,bud=0,ch;
	char password[30]="bharath";
	char enteredpass[30];
	recent trans;
	int breaker=0;
	int choice1=0;
	stack st;
	initstack(&st);
	int size=15,i;
	int no;
	hotel w1;
	int childs=0;
  	stud s[size],fin[size];
  	
  	int planid;
  	nodell *list=NULL;
  	int age,idno;
  	char foodpref[30];
  	char name[30];
  
  	s[0].cost=10000;
  	strcpy(s[0].loc,"Shimla and Gangtok valley tour      ");
  	
  
  	s[1].cost=20000;
  	strcpy(s[1].loc,"Punjab colors                       ");
  	
  
  	s[2].cost=30000;
  	strcpy(s[2].loc,"Haryana Blues                       ");


  	s[3].cost=40000;
  	strcpy(s[3].loc,"Rajasthani experience               ");
  
  
  	s[4].cost=50000;
  	strcpy(s[4].loc,"Shimla complete travel experience   ");
  
  
  	s[5].cost=60000;
  	strcpy(s[5].loc,"Exquisite Andaman and Nicobar tours ");
  	
  	
  	s[6].cost=70000;
  	strcpy(s[6].loc,"Varanasi Ghats                      ");
 	
 	
  	s[7].cost=80000;
  	strcpy(s[7].loc,"Delhi capital tour                  ");
  	
  
  	s[8].cost=15000;
  	strcpy(s[8].loc,"Temple tour south india             ");
  	
   
  	s[9].cost=25000;
  	strcpy(s[9].loc,"North-East experience               ");
  	
  	
  	s[10].cost=35000;
  	strcpy(s[10].loc,"Jammu and Kashmir landscape         ");
 
  	
  	s[11].cost=45000;
  	strcpy(s[11].loc,"Himachal Pradesh zipline adventure  ");
  	
  	
  	s[12].cost=55000;
  	strcpy(s[12].loc,"Pondicherry                         ");
 
  	
  	s[13].cost=65000;
  	strcpy(s[13].loc,"Kerala mountains                    ");
  
  	
  	s[14].cost=75000;
  	strcpy(s[14].loc,"Andhra Pradesh nature               ");

  	
  	
  	
  	//printf("\n");
  	for(i=0;i<15;i++)
  	{
  		s[i].id=rand()%10000+rand()%50000+rand()%20000;
  	}
  	
  	/*To print before sorting array
  	for(i=0;i<size;i++)
  	{
  		printf("\nloc:%s,cost:%d,id:%d ",s[i].loc,s[i].cost,s[i].id);
  	}*/
  	
   // printf("\n");
    
    divide_and_conquer(s,0,14,1);//Sorting on the basis of cost
    
  // printf("\n");
   
   /*To print after sorting on the basis of cost
   for(i=0;i<size;i++)
  	{
  		printf("\nloc:%s,cost:%d,id:%d",s[i].loc,s[i].cost,s[i].id);
  	}*/
  	
//printf("\n");

	node *root = sortedArrayToBST(s, 0, size-1); //sorted bst by cost
	//inord(root);
	//printf("\n\n");
	divide_and_conquer(s,0,14,2);//Sorting on the basis of id
	node *root1 = sortedArrayToBST(s, 0, size-1); //sorted bst by id
	
	queue q8;
	
	initq(&q8);
	push(&q8,1,3000,"Holiday inn");
	push(&q8,1,3500,"Mahindra Resort");
	push(&q8,3,4000,"Livein Resort");
	push(&q8,3,4500,"Vivanta Resort");
	push(&q8,4,5000,"Kaldor Resort");
	push(&q8,5,6000,"Hablis Hotel");
	push(&q8,5,6500,"Radisson");
	push(&q8,5,7000,"Taj Hotel");
	push(&q8,5,7500,"Emporio Hotel");
	push(&q8,5,8000,"Hilton Hotel");
	
//	inord(root);
	
	//Travel Planner
	int cp1=0;
	char codeent[6];
	int ans2,ans3;
	node *p;
	int adm,ch2;
	char admloc[50];
	int admcost;
	int admid;
	int ch3;
	int codecnt=4;
	int nocode=0;
	int adminsert=1;
	int admcnt=15;
	printf("\n\n");
	printf("\n*********Travel Itinerary Planner*********");
	printf("\n");
	while(breaker!=6)
	{
	list=NULL;
	p=NULL;
	cp1=0;
	q8.front=-1;
	q8.rear=9;
	printf("\n");
	printf("\nUser");
	printf("\nAre you an admin or customer, enter choice");
	printf("\n1.Admin");
	printf("\n2.Customer");
	printf("\n3.End transaction");
	printf("\n4.Previous transactions");
	scanf("%d",&adm);
	switch(adm)
	{
		case 1:
		printf("\nEnter your password");
		scanf("%s",enteredpass);
		if(strcmp(enteredpass,password)!=0)
		{
			printf("\nIncorrect password");
			break;
		}
		printf("\nEnter your choice");
		printf("\n1.Make changes to existing tour packages and locations");
		scanf("%d",&ans2);
		if(ans2==1)
		{
			printf("\nExisting tour packages are as follows");
			inord(root);
			printf("\n");
			printf("\nDo you want to add further tour packages");
			scanf("%d",&ans3);
			while(ans3==1)
			{
				size++;
				printf("\n");
				printf("\nEnter location");
				scanf("%s",admloc);
				printf("\nEnter ID of place: enter id in 5 digits only");
				scanf("%d",&admid);
				printf("\nEnter cost of location");
				scanf("%d",&admcost);
				s[admcnt].cost=admcost;
				s[admcnt].id=admid;
				strcpy(s[admcnt].loc,admloc);
				divide_and_conquer(s,0,admcnt,1);
				root = sortedArrayToBST(s, 0, size-1);
				divide_and_conquer(s,0,admcnt,2);
				root1 = sortedArrayToBST(s, 0, size-1); 
				printf("\nLocation %d has been inserted successfully",adminsert);
				printf("\n");
				printf("\nPress 1 to continue");
				scanf("%d",&ans3);
				adminsert++;
				admcnt++;
			}
			printf("\nUpdated tour packages are as follows");
			inord(root);
			
		}
		break;
	
	case 2:
	
	printf("\n");
	//inord(root);
	printf("\nFor a specially designed tour package,as per your needs enter the following information\n");
	printf("\nDo you have a promocode::::");
	scanf("%d",&choice1);
	
	//promo code booking
	if(choice1==1)
	{
		//i=0;
		printf("\nEnter promocode::::");
		scanf("%s",codeent);
		printf("\nYour entered promo code is %s",codeent); 
		nocode=codetoplanid(codeent);
		printf("\n%d is plan number",nocode);
		p=search(root1,nocode);
		if(p==NULL)
		{
			printf("\nYour entered promocode is invalid");
			return 0;
		}
	
	if(p)
	{
	
	printf("\nYour promo code has been successfully applied:");
	printf("\n");
	printf("\n--------------------------------------------");
	printf("\nOffer price per person is %d",p->offprice);
	printf("\nLocation as per entered promo code is %s",p->loc);
	printf("\n--------------------------------------------");
	}
	printf("\n\n");
	goto expressbooking;
	}
	
	//normal booking
	
	printf("\nEnter number of days of travel::::");
	scanf("%d",&ndays);
	printf("\nEnter your estimated budget for the trip::::");
	scanf("%d",&bud);
	while(bud<10000)
	{
	printf("\nOur plans start from 10,000 INR onwards please re-enter the amount::::");
	scanf("%d",&bud);
	}
	printf("\nFor your budget, we offer the following plans::::");
	printf("\n");
	printf("\n-------------------------------------------------------------------");
	printf("\n|     COST      |   ID    |           LOCATION                    |");
	printf("\n-------------------------------------------------------------------");
	//search(root,bud);
	Print(root,10000,bud);
	printf("\n-------------------------------------------------------------------");
	printf("\n");
	printf("\nEnter the ID of the plan you choose:::");
	scanf("%d",&planid);
	p=search(root1,planid);
	while(p==NULL)
		{
			printf("\nInvalid ID chosen,re-enter-ID");
			scanf("%d",&planid);
			p=search(root1,planid);
		}
	
	if(p)
	{
	
	printf("\nYour requested plan has been successfully chosen:");
	printf("\n");
	cp1=p->data;
	printf("\n--------------------------------------------");
	printf("\nCost per person is %d",p->data);
	printf("\nLocation is %s",p->loc);
	printf("\n--------------------------------------------");
	}
	printf("\n\n");
	printf("\n*********Enter 1 to confirm details*********::::");
	scanf("%d",&i);
	printf("\n");
	if(!i)
	{
		printf("\n*****Booking cancelled");
		return 0;
	}
	printf("\nDetails have been confirmed");
	printf("\n\n");
	printf("\n***************************************************************");
	expressbooking:
	printf("\nEnter number of people::::");
	scanf("%d",&no);
	for(i=0;i<no;i++)
	{
		printf("\n\n");
		printf("\nEnter details of person %d",i+1);
		printf("\n1.Enter name::::");
		scanf("%s",name);
		printf("\n2.Enter age::::");
		scanf("%d",&age);
		printf("\n3.Enter any registered ID number::::");
		scanf("%d",&idno);
		printf("\n4.Enter food preference 'v' for veg, 'nv' for non-veg and 'n' for no-food::::");
		scanf("%s",foodpref);
		while(strcmp(foodpref,"v")!=0 && strcmp(foodpref,"nv")!=0 && strcmp(foodpref,"n")!=0)
		{
			printf("\nInvalid entry please try again");
			scanf("%s",foodpref);
		}
		list=insertatendll(list,age, idno, name, foodpref);
		printf("\nDetails of person %d successully entered",i+1);
		printf("\n-------------------------------------------------------------------");
	}
	printf("\n\n");
	printf("\n*************************************************************");
	printf("\nAll details have been entered succesfully");
	printf("\n*************************************************************");
	printf("\n\n");
	printf("\nPlease verify your details");
	childs=displayll(list);
	printf("\n\n");
	printf("\n*********Enter 1 to confirm details or 0 to make changes*********::::");
	scanf("%d",&i);
	printf("\n");
	int tem,tem1,i1;
	if(i!=1 && i!=0)
	{
		printf("\n*****Booking cancelled");
		return 0;
	}
	if(i==0)
	{
	while(1)
	{
		
		printf("\n");
		printf("\nWhich person would you like to make a change to, enter person no to continue:::");
		scanf("%d",&tem);
		while(tem > no || tem<1)
		{
			printf("\nPerson %d doesn't exist,please enter again::::",tem);
			scanf("%d",&tem);
		}
		deletell(list,tem);
		printf("\nPerson %d has been deleted from the list",tem);
		printf("\nWould you like to re-enter the details? : enter 1 for yes, 0 for no");
		scanf("%d",&tem);
		if(tem==0)
		{
			printf("\nChanges complete");
			break;
		}
		if(tem==1)
		{
		printf("\n\n");
		printf("\nEnter the details of person ");
		printf("\n1.Enter name:::");
		scanf("%s",name);
		printf("\n2.Enter age:::");
		scanf("%d",&age);
		printf("\n3.Enter any registered ID number:::");
		scanf("%d",&idno);
		printf("\n4.Enter food preference 'v' for veg, 'nv' for non-veg and 'n' for no-food:::");
		scanf("%s",foodpref);
		while(strcmp(foodpref,"v")!=0 && strcmp(foodpref,"nv")!=0 && strcmp(foodpref,"n")!=0)
		{
			printf("\nInvalid entry please try again::");
			scanf("%s",foodpref);
		}
		list=insertatendll(list,age, idno, name, foodpref);
		printf("\nDetails of the person have been successully entered");
		}
		printf("\nWould you like to make any more changes enter 1 for yes 0 for no?::");
		scanf("%d",&tem1);
		if(tem1==0)
		break;
	}
	childs=displayll(list);
	}
		
	printf("\nNow, choose accomodation");
	
	
	printf("\n");
	printf("\n--------------------------------------------------------------------------");
	printf("\n| S.No  |           Name                |      Rating    |      Cost     |");
	printf("\n--------------------------------------------------------------------------");
	for(i=0;i<10;i++)
		{	
			
			 w1=pop(&q8);
			printf("\n|   %d",i+1);
			printf("\t|\t%s\t",w1.name);
			printf("\t|\t%d  ",w1.rating);
			printf("\t|\t%d\t |",w1.cost);
		}
	printf("\n--------------------------------------------------------------------------");
	printf("\n");
	int hno;
	int total;
	int ch4;
	int answer=0;
	node *nearby;
	printf("\nEnter the hotel number you prefer:::");
	scanf("%d",&hno);
	printf("\nYou have chosen");
	printf("\nHotel Name: %s",q8.vals[hno-1].name);
	printf("\nCost:%d",q8.vals[hno-1].cost);
	printf("\n");
	//printf("\n");
	printf("\n");
	
	
	
	
	if(cp1!=0)
	{
	nearby=searchbycost(root,cp1+5000);
	answer=1;
	printf("\nWould you also like to visit this place?");
	printf("\n");
	printf("\nWould you like to claim the offer?::::");
	scanf("%d",&ch2);
	if(ch2==1 && choice1!=1)
	{
		printf("\nYou have received a promocode");
		printf("\nYour promo-code will be valid in the next booking");
		printf("\nPromocode is %s",nearby->prodcode);
	}
	}
	
	
	
	printf("\n\nYour itinerary has been generated, thanks for booking through us");
	printf("\n-------------------------------------------------------------------------------------");
	printf("\n|                                 ITINERARY                                               ");
	printf("\n|                                                                                         ");
	printf("\n|                     Your chosen holiday location:                                       ");
	printf("\n|                      --%s                                                               ",p->loc);
	printf("\n|                                                                                         ");
	printf("\n|                     Number of days of trip                                              ");
	printf("\n|                      --%d                                                               ",ndays);
	printf("\n|                                                                                         ");
	printf("\n|                     Traveller details                                                   ");
	displayllfinal(list);
	printf("\n|                                                                                         ");
	printf("\n|                     Your accomodation details:                                          ");
	printf("\n|                                                                                         ");
	printf("\n|                     Your chosen hotel                                                   ");
	printf("\n|                     Hotel Name: %s                                                      ",q8.vals[hno-1].name);
	printf("\n|                     Cost:%d                                                             ",q8.vals[hno-1].cost);
	printf("\n|                     Hotel rating:%d stars                                               ",q8.vals[hno-1].rating);
	printf("\n|                     No of nights is %d                                                  ",ndays-1);
	if(choice1==1)
	total=p->offprice*(no-childs)+(p->offprice/2 *childs)+(q8.vals[hno-1].cost)*(ndays-1);
	else
	total=p->data*(no-childs)+(p->data/2 *childs)+(q8.vals[hno-1].cost)*(ndays-1);
	printf("\n|                     Your final cost is %d                                               ",total);
	printf("\n|");
	if(choice1==1)
	{
	printf("\n|                     Price break-up                                                      ");
	printf("\n|");
	printf("\n|                     No of adults:%d--------------->cost:%d                              ",no-childs,p->offprice*(no-childs));
	printf("\n|                     No of children:%d------------->cost:%d                              ",childs,(p->offprice/2 *childs));
	printf("\n|                     Hotel cost for %d nights------>cost:%d                              ",ndays-1,(q8.vals[hno-1].cost)*(ndays-1));
	}
	else
	{
	printf("\n|                    Price break-up                                                       ");
	printf("\n|");
	printf("\n|                    No of adults:%d--------------->cost:%d                               ",no-childs,p->data*(no-childs));
	printf("\n|                    No of children:%d------------->cost:%d                               ",childs,(p->data/2 *childs));
	printf("\n|                    Hotel cost for %d nights------>cost:%d                               ",ndays-1,(q8.vals[hno-1].cost)*(ndays-1));
	}
	printf("\n|");
	printf("\n|                              Total: %d",total);
	printf("\n|");
	if(ch2==1 && choice1!=1)
	{
	printf("\n|                  You received a promocode, which can be used in the next booking");
	printf("\n|                                   Your promocode is %s                          ",nearby->prodcode);
	printf("\n|");
	}
	printf("\n-------------------------------------------------------------------------------------");
	printf("\n");
	printf("\n");

	pushstack(&st,no,total,p->loc);
	printf("\nWould like to make another transaction");
	scanf("%d",&ch4);
	if(ch4==0)
	breaker=6;
	break;
	
	case 3:
	printf("\nProgram has been terminated");
	breaker=6;
	break;
	
	case 4:
	if(isemptystack(st))
	printf("\nNo previous transactions to show");
	else
	{
	while(!isemptystack(st))
	{
		printf("\n");
		trans=popstack(&st);
		printf("\nTour location booked: %s",trans.dest);
		printf("\nTotal cost of trip:%d",trans.tcost);
		printf("\nTotal no of people:%d",trans.tpeople);
		printf("\n-------------------------------------------");
	}
	}
	
	}
	
}
}
	
	
