/*A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method. */

#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node {
    char name[20];
    node *next;
    node *down;
    int flag;
};

class BOOK {
    node *head;

public:
    BOOK() : head(NULL) {} // Constructor to initialize head

    node *createNode(const char* name);
    void insertBook();
    void insertChapter();
    void insertSection();
    void insertSubsection();
    void displayBook();
};

// Function to create a new node
node* BOOK::createNode(const char* name) {
    node *p = new node;
    strcpy(p->name, name);
    p->next = NULL;
    p->down = NULL;
    p->flag = 0;
    return p;
}

// Function to insert a book
void BOOK::insertBook() {
    if (head == NULL) {
        char name[20];
        cout << "\nEnter the name of the book: ";
        cin >> name;
        head = createNode(name);
    } else {
        cout << "\nBook already exists.";
    }
}

// Function to insert a chapter
void BOOK::insertChapter() {
    if (head == NULL) {
        cout << "\nThere is no book.";
        return;
    }

    char chapterName[20];
    cout << "\nEnter the name of the chapter: ";
    cin >> chapterName;
    if (head->down == NULL) {
        head->down = createNode(chapterName);
        head->flag = 1;
    } else {
        node* temp = head->down;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = createNode(chapterName);
    }
}

// Function to insert a section
void BOOK::insertSection() {
    if (head == NULL || head->down == NULL) {
        cout << "\nThere is no book or chapter.";
        return;
    }

    char chapterName[20];
    cout << "\nEnter the name of the chapter: ";
    cin >> chapterName;

    node* temp = head->down;
    while (temp != NULL && strcmp(temp->name, chapterName) != 0)
        temp = temp->next;

    if (temp == NULL) {
        cout << "\nChapter not found.";
        return;
    }

    char sectionName[20];
    cout << "\nEnter the name of the section: ";
    cin >> sectionName;

    if (temp->down == NULL) {
        temp->down = createNode(sectionName);
        temp->flag = 1;
    } else {
        node* secTemp = temp->down;
        while (secTemp->next != NULL)
            secTemp = secTemp->next;
        secTemp->next = createNode(sectionName);
    }
}

// Function to insert a subsection
void BOOK::insertSubsection() {
    if (head == NULL || head->down == NULL) {
        cout << "\nThere is no book or chapter.";
        return;
    }

    char chapterName[20];
    cout << "\nEnter the name of the chapter: ";
    cin >> chapterName;

    node* temp = head->down;
    while (temp != NULL && strcmp(temp->name, chapterName) != 0)
        temp = temp->next;

    if (temp == NULL) {
        cout << "\nChapter not found.";
        return;
    }

    char sectionName[20];
    cout << "\nEnter the name of the section: ";
    cin >> sectionName;

    node* secTemp = temp->down;
    while (secTemp != NULL && strcmp(secTemp->name, sectionName) != 0)
        secTemp = secTemp->next;

    if (secTemp == NULL) {
        cout << "\nSection not found.";
        return;
    }

    char subsectionName[20];
    cout << "\nEnter the name of the subsection: ";
    cin >> subsectionName;

    if (secTemp->down == NULL) {
        secTemp->down = createNode(subsectionName);
    } else {
        node* subTemp = secTemp->down;
        while (subTemp->next != NULL)
            subTemp = subTemp->next;
        subTemp->next = createNode(subsectionName);
    }
}

// Function to display subsections
void displaySubsections(node *sub) {
    cout << "\n\t\t\tName of subsection: " << sub->name;
}

// Function to display sections
void displaySections(node *sec) {
    cout << "\n\t\tName of section: " << sec->name;
    node* subTemp = sec->down;
    while (subTemp != NULL) {
        displaySubsections(subTemp);
        subTemp = subTemp->next;
    }
}

// Function to display chapters
void displayChapters(node *temp) {
    cout << "\n\tName of chapter: " << temp->name;
    node* secTemp = temp->down;
    while (secTemp != NULL) {
        displaySections(secTemp);
        secTemp = secTemp->next;
    }
}

// Function to display the book hierarchy
void BOOK::displayBook() {
    if (head == NULL) {
        cout << "\nBook not exist.";
        return;
    }

    cout << "\nName of book: " << head->name;
    node* temp = head->down;
    while (temp != NULL) {
        displayChapters(temp);
        temp = temp->next;
    }
}

int main() {
    BOOK g;
    int x;
    while(1) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Insert book";
        cout << "\n2. Insert chapter";
        cout << "\n3. Insert section";
        cout << "\n4. Insert subsection";
        cout << "\n5. Display book";
        cout << "\n6. Exit\n";
        cin >> x;

        switch (x) {
            case 1:
                g.insertBook();
                break;
            case 2:
                g.insertChapter();
                break;
            case 3:
                g.insertSection();
                break;
            case 4:
                g.insertSubsection();
                break;
            case 5:
                g.displayBook();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nInvalid choice. Please enter again.";
                break;
        }
    }
    return 0;
}