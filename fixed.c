/*
Team: Testrack
Program: A small class-roll maintennace system implemented in a simple console-based text interface.
Last Modification Date: 10/1/2019
*/


//Their code had around 70 faults that I found or corrected (things I considered faults or problems), on 62 lines.
//Two of the functions used a tail pointer, but it was only used for checking if the student list is empty. 
//This functionality could have been added with just the head 
//I added in the other two tail parameters to add in empty list checks to read and delete functions, because that is the way (I belive) they wanted to do it


//#pragma warning(disable : 4996)  ## suppressed warnings, doesnt do anything to the fixed code at least, fault ?
#include <stdio.h> // ## did not include this header, fault
#include <stdlib.h>
#include <string.h>

// A structure to hold all student attributes
typedef struct Student // ## did not include typedef here, fault
{
    char name[40];
    char usfID[10];
    char usfEmail[40];
    int presentationGrade;
    int essayGrade;
    int termProject;

    struct Student *next; // ## did not include * on next, fault
} student; // ## did not have student here, fault

void writeStudent(student *head, student *tail); // ## did not include function headers, technically 4 faults
void updateStudent(student *head, student *tail);
void readStudent(student *head, student *tail);
void deleteStudent(student *head, student *tail);

// main function
int main()
{

    // Create a head and tail student nodes, allocate memory for them, and link
    student *head = malloc(sizeof(student)); // ## did not initialize head, did not allocate memory, 2 faults
    student *tail = malloc(sizeof(student)); // ## did not allocate tail memory, fault
    head->next = tail;
    tail->next = NULL; // ## did not set tail->next to NULL but tail is never used so.... ,technical fault

    int selection = 1; // ## had uninitialized int here, fault

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
            break; // ## did not write break statement, fault
        case 2:
            updateStudent(head, tail); // ## did not include tail here, fault
            break; // ## did not write break statement, fault
        case 3:
            readStudent(head, tail);
            break; // ## did not write break statement, fault
        case 4:
            deleteStudent(head, tail);
            break; // ## did not write break statement, fault
        }
    }
    return 0;
}

// Function to add/write student data
void writeStudent(student *head, student *tail) // ## did not use * for head or tail, fault
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
        scanf("%d", &PresentationGrade); // ## had an unused int (grade1) being assigned here, fault?

        if (PresentationGrade >= 0 && PresentationGrade <= 4)
        {
            break;
        }
    }

    while (1)
    {
        printf("Enter the student's essay grade (0-4): ");
        scanf("%d", &EssayGrade); // ## had an unused int (grade2) being assigned here, fault?

        if (EssayGrade >= 0 && EssayGrade <= 4)
        {
            break; // ## did not write break statement here, fault;
        }
    }

    while (1)
    {
        printf("Enter the student's term project grade (0-4): ");
        scanf("%d", &TermProject); // ## had an unused int (grade3) being assigned here, fault?

        if (TermProject >= 0 && TermProject <= 4)
        {
            break; // ## did not write break statement here, fault;
        }
    }

    //creating a new node to add student data
    student *new_student = malloc(sizeof(student)); // ## did not allocate memory for new_student, fault

    //adding student attributes to the node
    strcpy(new_student->name, strcat(firstName, lastName)); // ## used + instead of strcat for firstName and lastName combo, did not use strcpy, 2 faults
    strcpy(new_student->usfID, UID); // ## did not use strcpy, fault
    strcpy(new_student->usfEmail, Email); // ## did not use strcpy, fault
    new_student->presentationGrade = PresentationGrade;
    new_student->essayGrade = EssayGrade;
    new_student->termProject = TermProject;

    new_student->next = head->next; 
    head->next = new_student; // ## assigned head->next to new_student before setting attibutes of new_student, fault
}

// Function to update student's information
void updateStudent(student *head, student *tail) // ## did not incude * for head, did not include student *tail, 2 faults
{

    if (head->next == tail || head->next == NULL) // ## head->next == NULL instead of head->next == tail, fault
    {
        printf("List empty.\n");
        return;
    }

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


    student *curr;
    curr = head;

    //logic to get to the required student node

    while (curr->next != NULL) // ## used curr here instead of curr->next, fault
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

    int selection = 1; // ## uninitiallized int here, fault 

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
            break; // ## did not include break statement, fault
        case 2:
            //update USFID
            printf("Enter the student's new USF ID: ");
            scanf("%s", usfID);
            strcpy(curr->usfID, usfID);
            printf("Student's USF ID updated.\n");
            break; // ## did not include break statement, fault
        case 3:
            //update email
            printf("Enter the student's new email: ");
            scanf("%s", usfEmail);
            strcpy(curr->usfEmail, usfEmail); // ## did not use strcpy here, fault
            printf("Student's email updated.\n");
            break; // ## did not include break statement, fault
        case 4:
            //update presentation grade
            while (1)
            {
                printf("Enter the student's new presentation grade (0-4): ");
                scanf("%d", &presentationGrade); // ## had unused int here (grade3), fault?

                if (presentationGrade >= 0 && presentationGrade <= 4)
                {
                    break; // ## did not include break statement, fault
                }
            }
            curr->presentationGrade = presentationGrade;
            printf("Student's presentation grade updated.\n");
            break; // ## did not include break statement, fault
        case 5:
            //update essay grade
            while (1)
            {
                printf("Enter the student's new essay grade (0-4): ");
                scanf("%d", &essayGrade); // ## had unused int here (grade3), fault?

                if (essayGrade >= 0 && essayGrade <= 4)
                {
                    break; // ## did not include break statement, fault
                }
            }
            curr->essayGrade = essayGrade;
            printf("Student's essay grade updated.\n");
            break; // ## did not include break statement, fault
        case 6:
            //update term project grade
            while (1)
            {
                printf("Enter the student's term project grade (0-4): ");
                scanf("%d", &termProject); // ## had unused int here (grade3), fault?

                if (termProject >= 0 && termProject <= 4)
                {
                    break; // ## did not include break statement, fault
                }
            }
            curr->termProject = termProject;
            printf("Student's term project grade updated.\n");
            break; // ## did not include break statement (not really needed b/c at bottom of switch), technical fault
        }
    }
}

// Function to read/retrieve student data
void readStudent(student *head, student *tail)
{
    // ## I check for empty list, not technically a fault but better usage
    student *temp;
    temp = head->next;
    if (temp == NULL || temp == tail)
    {
        puts("Empty List.");
        return;
    }

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
        break; // ## did not include break statement, fault
    case 2:
        printf("Enter the student's UID in the format UXXXXXXXX: ");
        scanf("%s", UID);
        selection = 2;
        break; // ## did not include break statement, fault
    case 3:
        printf("Enter the student's email: \n");
        scanf("%s", Email);
        selection = 3;
        break; // ## did not include break statement, fault
    }

    //temporary node to traverse through the linked list
    temp = head->next;

    //retrieve student info by name
    if (selection == 1)
    {
        // Search for name
        while (temp->next != NULL) // ## they used temp != tail here. Maybe their implementation used tail in this function, but I dont. fault
        {
            if (strcmp(temp->name, Name) == 0)
            {
                strcpy(UID, temp->usfID);
                strcpy(Email, temp->usfEmail);
                presentationGrade = temp->presentationGrade;
                essayGrade = temp->essayGrade;
                termProject = temp->termProject;
            }
            temp = temp->next; // ## did not include a way to traverse the list, fault
        }
    }

    //retrieve student info by UID
    else if (selection == 2)
    {
        //search for UID
        while (temp->next != NULL) // ## used temp != NULL instead of temp->next, fault
        {
            if (strcmp(UID, temp->usfID) == 0) // ## did not use strcmp, used = instead of ==, technically 2 faults
            {
                strcpy(Name, temp->name); // ## did not use strcpy, fault
                strcpy(Email, temp->usfEmail); // ## did not use strcpy, fault
                presentationGrade = temp->presentationGrade;
                essayGrade = temp->essayGrade;
                termProject = temp->termProject;
            }
            temp = temp->next; // ## did not include a way to traverse the list, fault
        }
    }

    //retrieve student info by Email
    else
    {
        //search for Email
        while (temp->next != NULL) // ## they used temp != tail here. Maybe their implementation had tail in this function, but I dont. fault
        {
            if (strcmp(Email, temp->usfEmail) == 0) // ## did not use strcmp, used = instead of ==, technically 2 faults
            {
                strcpy(Name, temp->name); // ## did not use strcpy, fault
                strcpy(UID, temp->usfID); // ## did not use strcpy, fault
                presentationGrade = temp->presentationGrade;
                essayGrade = temp->essayGrade;
                termProject = temp->termProject;
            }
            temp = temp->next; // ## did not include a way to traverse the list, fault
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
void deleteStudent(student *head, student *tail)
{

    if (head->next == tail || head->next == NULL) // ## dont check for empty list. Doesnt crash but better usage
    {
        printf("List empty.\n");
        return;
    }

    //local variable
    char UID[10];

    // Ask for UID of the student, since students may have the same name
    printf("Enter the UID (in the format UXXXXXXXX) of the student you wish to delete: ");
    scanf("%s", UID);

    student *curr;
    student *prev;

    //traverse through the list to find the student
    for (curr = head->next, prev = head; curr != NULL && prev->next != NULL; prev = curr, curr = curr->next) // ## had prev = head->next, curr = head instead of curr = head->next, prev = head, had == NULL instead of != NULL, 2 faults
    {

        //logic to delete the student node from the list
        if (strcmp(curr->usfID, UID) == 0)
        {
            prev->next = curr->next;
            free(curr);
            printf("Student has been deleted\n\n"); // ## had this statement outside of loop, printed every time function was called, fault
            return;
        }
    }
}