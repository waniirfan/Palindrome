#include<iostream>
#include<array>
struct Node
{
	char info;
	Node* next;
};
void display(Node* ptr)
{
	while (ptr != NULL)
	{
		std::cout << ptr->info << "->";
		ptr = ptr->next;
	}
}

int main()
{
	std::array <char, 100> myarray;
	int count{};
	Node* start=NULL;
	Node* save;
	char ch{'y'};
	while (ch == 'y' || ch == 'Y')
	{
		std::cout << "\nEnter the character: ";
		char c;
		std::cin >> c;
		Node* newptr = new Node;
		newptr->info = c;
		newptr->next = NULL;
		if (start == NULL)
			start = newptr;
		else
		{
			save = start;
			start = newptr;
			newptr->next = save;
		}
		display(start);
		std::cout << "\nAdd More Y/N: ";
		std::cin>>ch;

	}
	save = start;
	while (save != NULL)
	{
		myarray[count] = save->info;
		count++;
		save = save->next;

	}
	std::cout << "\nLength of Linked List= " << count << '\n';
	std::cout << "\nArray is: ";
	for (int i = 0; i < count; i++)
	{
		std::cout<<myarray[i];
	}
	save = start;
	while (save != NULL)
	{
		count--;
		if(myarray[count] != save->info)
		{
			std::cout << "\nNo Match found\n";
			exit(0);
		}
		
		save = save->next;

	}
std:: cout << "\nThe number is palindrome\n";
 
	return 0;
}
