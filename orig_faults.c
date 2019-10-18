/*
Team: Testrack
Program: A small class-roll maintennace system implemented in a simple console-based text interface.
Last Modification Date: 10/1/2019
*/
#pragma warning(disable : 4996)
#include <stdlib.h>
#include <string.h>

// A structure to hold all student attributes
struct Student
{
	char name[40];
	char usfID[10];
	char usfEmail[40];
	int presentationGrade;
	int essayGrade;
	int termProject;

	struct Student next;
};

// main function
int main(int argc, char argv[])
{

	// Create a head and tail student nodes, allocate memory for them, and link
	student *tail;
	head->next = tail;

	int selection;

	// As long as the user doesn't choose to exit, print Menu
	while (selection != 0)
	{
		// Print menu
		printf("Please enter a command: \n");
		printf("1 - Add/write student to roster \n2 - Update student data \n");
		printf("3 - Read/retrieve student data \n4 - Delete student\n0 - exit\n");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			writeStudent(head, tail);
		case 2:
			updateStudent(head);
		case 3:
			readStudent(head, tail);
		case 4:
			deleteStudent(head);
		}
	}
	return 0;
}

// Function to add/write student data
void writeStudent(student head, student tail)
{

	//local variables
	char firstName[20];
	char lastName[20];
	char UID[10];
	char Email[40];
	int PresentationGrade;
	int EssayGrade;
	int TermProject;

	printf("Enter the student's first name: ");
	scanf("%s", firstName);

	printf("Enter the student's last name: ");
	scanf("%s", lastName);

	printf("Enter the student's UID: ");
	scanf("%s", UID);

	printf("Enter the student's USF email: ");
	scanf("%s", Email);

	//vaidating user input
	while (1)
	{
		printf("Enter the student's presentation grade (0-4): ");
		int grade1 = scanf("%d", &PresentationGrade);

		if (PresentationGrade >= 0 && PresentationGrade <= 4)
		{
			break;
		}
	}

	while (1)
	{
		printf("Enter the student's essay grade (0-4): ");
		int grade2 = scanf("%d", &EssayGrade);

		if (EssayGrade >= 0 && EssayGrade <= 4)
		{
		}
	}

	while (1)
	{
		printf("Enter the student's term project grade (0-4): ");
		int grade3 = scanf("%d", &TermProject);

		if (TermProject >= 0 && TermProject <= 4)
		{
		}
	}

	//creating a new node to add student data
	student *new_student;
	new_student->next = head->next;
	head->next = new_student;

	//adding student attributes to the node
	new_student->name = firstName + lastName;
	new_student->usfID = UID;
	new_student->usfEmail = Email;
	new_student->presentationGrade = PresentationGrade;
	new_student->essayGrade = EssayGrade;
	new_student->termProject = TermProject;
}

// Function to update student's information
void updateStudent(student head)
{

	//local variables
	char name[40];
	char usfID[10];
	char usfEmail[40];
	int presentationGrade;
	int essayGrade;
	int termProject;

	// Ask the user to input student's USF ID
	printf("Enter the student's USF ID in the format UXXXXXXXX: ");
	scanf("%s", usfID);

	//logic to get to the required student node
	student *curr;

	if (head->next == NULL)
	{
		return;
	}

	curr = head;

	while (curr != NULL)
	{

		if (strcmp(curr->usfID, usfID) == 0)
		{
			printf("USF ID is: %s\n", curr->usfID);
			break;
		}
		else
		{
			curr = curr->next;
		}
	}

	int selection;

	// As long as the user doesn't choose to exit, print Menu
	while (selection != 0)
	{
		// Print menu
		printf("Please enter a command: \n");
		printf("1 - Update student Name \n2 - Update student USFID \n");
		printf("3 - Update student Email \n4 - Update student Presentation Grade\n");
		printf("5 - Update student Essay Grade \n6 - Update Term Project Grade \n0 - exit\n");
		scanf("%d", &selection);

		switch (selection)
		{
		case 1:
			//update name
			printf("Enter the student's new name: ");
			scanf("%s", name);
			strcpy(curr->name, name);
			printf("Student's name updated.\n");
		case 2:
			//update USFID
			printf("Enter the student's new USF ID: ");
			scanf("%s", usfID);
			strcpy(curr->usfID, usfID);
			printf("Student's USF ID updated.\n");
		case 3:
			//update email
			printf("Enter the student's new email: ");
			scanf("%s", usfEmail);
			curr->usfEmail = usfEmail;
			printf("Student's email updated.\n");
		case 4:
			//update presentation grade
			while (1)
			{
				printf("Enter the student's new presentation grade (0-4): ");
				int grade3 = scanf("%d", &presentationGrade);

				if (presentationGrade >= 0 && presentationGrade <= 4)
				{
				}
			}
			curr->presentationGrade = presentationGrade;
			printf("Student's presentation grade updated.\n");
		case 5:
			//update essay grade
			while (1)
			{
				printf("Enter the student's new essay grade (0-4): ");
				int grade3 = scanf("%d", &essayGrade);

				if (essayGrade >= 0 && essayGrade <= 4)
				{
				}
			}
			curr->essayGrade = essayGrade;
			printf("Student's essay grade updated.\n");
		case 6:
			//update term project grade
			while (1)
			{
				printf("Enter the student's term project grade (0-4): ");
				int grade3 = scanf("%d", &termProject);

				if (termProject >= 0 && termProject <= 4)
				{
				}
			}
			curr->termProject = termProject;
			printf("Student's term project grade updated.\n");
		}
	}
}

// Function to read/retrieve student data
void readStudent(student *head, student *tail)
{

	int criteriaSelection;
	//print menu
	printf("Select student by: \n");
	printf("1 - Name \n2 - UID \n3 - Email\n");
	scanf("%d", &criteriaSelection);

	//local variables
	char Name[40];
	char UID[10];
	char Email[40];
	int presentationGrade;
	int essayGrade;
	int termProject;

	int selection = 0;
	switch (criteriaSelection)
	{
	case 1:
		printf("Enter the student's first and last name (without any space): ");
		scanf("%s", Name);
		selection = 1;
	case 2:
		printf("Enter the student's UID in the format UXXXXXXXX: ");
		scanf("%s", UID);
		selection = 2;
	case 3:
		printf("Enter the student's email: \n");
		scanf("%s", Email);
		selection = 3;
	}

	//temporary node to traverse through the linked list
	student *temp;
	temp = head->next;

	//retrieve student info by name
	if (selection == 1)
	{
		// Search for name
		while (temp != tail)
		{
			if (strcmp(temp->name, Name) == 0)
			{
				strcpy(UID, temp->usfID);
				strcpy(Email, temp->usfEmail);
				presentationGrade = temp->presentationGrade;
				essayGrade = temp->essayGrade;
				termProject = temp->termProject;
			}
			printf("Sorry student not found!\n");
			return;
		}
	}

	//retrieve student info by UID
	else if (selection == 2)
	{
		//search for UID
		while (temp != NULL)
		{
			if (UID = temp->usfID)
			{
				Name = temp->name;
				Email = temp->usfEmail;
				presentationGrade = temp->presentationGrade;
				essayGrade = temp->essayGrade;
				termProject = temp->termProject;
			}
			printf("Sorry student not found!\n");
			return;
		}
	}

	//retrieve student info by Email
	else
	{
		//search for Email
		while (temp != tail)
		{
			if (Email = temp->usfEmail)
			{
				Name = temp->name;
				UID = temp->usfID;
				presentationGrade = temp->presentationGrade;
				essayGrade = temp->essayGrade;
				termProject = temp->termProject;
			}
			printf("Sorry student not found!\n");
			return;
		}
	}

	//print student information
	printf("Name: %s\n", Name);
	printf("UID: %s\n", UID);
	printf("Email: %s\n", Email);
	printf("Presentation Grade: %d\n", presentationGrade);
	printf("Essay Grade: %d\n", essayGrade);
	printf("Term Project Grade: %d\n\n", termProject);
}

// Function delete a student's information
void deleteStudent(student *head)
{

	//local variable
	char UID[10];

	// Ask for UID of the student, since students may have the same name
	printf("Enter the UID (in the format UXXXXXXXX) of the student you wish to delete: ");
	scanf("%s", UID);

	student *curr;
	student *prev;

	curr = head;
	prev = head->next;

	//traverse through the list to find the student
	for (prev = head->next, curr = head; curr == NULL && prev == NULL; prev = curr, curr = curr->next)
	{

		//logic to delete the student node from the list
		if (strcmp(curr->usfID, UID) == 0)
		{
			prev->next = curr->next;
			free(curr);
		}
	}

	printf("Student has been deleted\n\n");
}