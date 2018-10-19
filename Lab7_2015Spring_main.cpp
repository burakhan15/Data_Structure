#include <cstdlib>
#include <iostream>
#include "LinkedL.h"
using namespace std;
void displayLL(struct node *header, char *title);
int mulLL(struct node *header);
int mulRec(struct node *header);
int sizee(struct node *header);
void deleteList (struct node * header);
struct node * array2list (struct node * header, int a[], int size);
struct node * insertnth (struct node * header, int n,int x);
void display_menu();

int main(int argc, char *argv[])
{
	int n,x;
    struct node *header=NULL;
	header=insertFront(header, 5);
	header=insertFront(header, 4);
	header=insertBack(header, 2);
	header=insertBack(header, 12);
	insertAfter(header,11);
	
	struct node * temp = NULL;
	int a[100] = {2,4,5,88};
  	int aSize = 4;

	int user_input;
	while(user_input!=9) {
		display_menu();
		cin>>user_input;
		switch(user_input) {
			case 1:
				cout<<endl;
				cout<< "result is :" << sizee(header)<<endl;
				cout<<endl;
				break;
			case 2:
				cout<<endl;
				temp = array2list(temp, a, aSize);
				cout << "Converted to array: ";
				displayLL(temp, "s");
				cout<<endl;
				break;
			case 3:
				cout<<endl << "Enter Data you want to insert";
				cin >> x;
				cout << endl << "Enter n-th place to insert data to";
				cin >> n;
				header = insertnth(header, n, x);
				displayLL(header,"asd");
				cout<<endl;
				break;
			case 4: 
				cout<<endl;
				char second_menu;
				cin >> second_menu;
				switch(second_menu) {
					case 'a':
						cout<<"Multiplation for Recursive :"<<mulRec(header)<<endl;
						break;
					case 'b':
						cout<<"Multilation for Itteration :"<<mulLL(header)<<endl;
						break;
					default:
						cout << "error";
				}
				break;
			case 5:
				cout << endl << "Enter n-th place to insert data to";
				cin >> n;
				header = updatenth(header, n);
				displayLL(header,"asd");
				cout<<endl;
			case 6:
				cout<<endl;
				header = deleteList(header);
				cout<<"Linked listed deleted";
				cout<<endl;
				break;
			case 7:
				exit;
				break;			
			default:
				cout<<"There was an error executing your command"<<endl;
		}
	}
	return 0;
    system("PAUSE");
    return EXIT_SUCCESS;
}

void display_menu() {
	cout<<"MENU"<<endl;
	cout<<"1- Count List"<<endl;
	cout<<"2- Create Array"<<endl;
	cout<<"3- Insert nt node"<<endl;
	cout<<"4- Multiplation"<<endl;
	cout<<"  A- Multiplation Recursive"<<endl;
	cout<<"  B- Multiplation Itteration"<<endl;
	cout<<"5-Update Nth node"<<endl;
	cout<<"6-Delete List"<<endl;
	cout<<"7-Exit"<<endl;
}

void displayLL(struct node *header,char *title)
{
    struct node*temp;
	for(temp=header; temp!=NULL; temp=temp->next)
		cout<<temp->data<<" ";
    cout<<endl;
}

int sizee(struct node *header){
    int i=0;
    struct node *temp;
    for(temp=header; temp!=NULL; temp=temp->next)
        i++;
    return i;
}
