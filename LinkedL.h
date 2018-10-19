struct node{
	int data;
	struct node *next;
};

int is_empty(struct node *header)
{
    if(header==NULL)
       return 1;
    else
       return 0;
}

struct node * new_node(int d)
{
	struct node * temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	return temp;
}

struct node * insertFront(struct node *header, int d)
{
	struct node *temp;
    temp=new_node(d);
	temp->next=header;
	header=temp;
	return header;
}



struct node * insertBack(struct node *header, int d)
{
	struct node *temp, *headertemp;
	temp=new_node(d);
	if(header==NULL)
	{
		header=temp;
		return header;
	}
	headertemp=header;
	while(headertemp->next!=NULL)
		headertemp=headertemp->next;
	headertemp->next=temp;
	return header;
}

void insertAfter(struct node *afterNode, int d)
{
	struct node *temp;
	temp=new_node(d);
	temp->next=afterNode->next;
	afterNode->next=temp;
}


struct node * deleteBack(struct node *header)
{
	struct node *temp, *headertemp;
	if(header==NULL)
		return header;
	if(header->next==NULL)
	{
        free(header);
        header=NULL;
		return header;
    }
	headertemp=header;
	while(headertemp->next->next!=NULL)
		headertemp=headertemp->next;
	temp=headertemp->next;
	headertemp->next=NULL;
	free(temp);
	return header;
}


struct node * deleteFront(struct node *header)
{
	struct node *temp;
	if(header==NULL)
		return header;
	temp=header;
	header=header->next;
	free(temp);
	return header;
}

void deleteAfter(struct node *afterNode)
{
	struct node *temp;
	if(afterNode->next==NULL || afterNode==NULL)
		return;
	temp =afterNode->next;
	afterNode->next=temp->next;
	free(temp);
}


int mulLL(struct node *header)
{
	int mul=1;
	struct node *headertemp;
	headertemp=header;
	while(headertemp!=NULL)
	{
		mul = mul * headertemp -> data;
		headertemp = headertemp->next;
	}
	return mul;
}
int mulRec(struct node *header)
{
	if(header==NULL)
		return 1;
	else
		return (header->data) * mulRec(header->next);

}


struct node * array2list (struct node * header, int a[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		header = insertFront(header, a[i]);
	}
	return header;
}
struct node * insertnth(struct node * header, int n,int x)
{
	if(header == NULL) {
		return header;
	}
	
    struct node* temp = header;
    if(n == 1) {
    	header=insertFront(header, x);
	} else {
	    int i = 2;
	    while (temp != NULL)
	    {
	       if (i == n) {
		   		insertAfter(temp, x);
		   		return header;
		   }
	       i++;
	       temp = temp->next;
	    }		
	}
	return header;
}
struct node * updatenth(struct node * header, int n)
{

    	if(header == NULL) {
		return header;
	}
    struct node* temp = header;

    if(n == 1) {
    	header = insertFront(header, header->data*5);
    	deleteAfter(header);
	} else {
	    int i = 1;
	    while (temp != NULL)
	    {
	       if (i == n) {
		   		insertAfter(temp, temp->data*5);
		   }
	       i++;
	       temp = temp->next;
	    }
	    i = 2;
	    temp = header;
	    while (temp != NULL)
	    {
	       if (i == n) {
		   		deleteAfter(temp);
		   }
	       i++;
	       temp = temp->next;
	    }
	}
	return header;
}

struct node * deleteList (struct node * header)
{
	struct node *headertemp1=header;
	struct node *headertemp2;
	while(headertemp1!=NULL)
	{
		headertemp2=headertemp1->next;
		free(headertemp1);
		headertemp1=headertemp2;
	}
	header=NULL;
	return header;
}
