#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** rendy, Node** muhamad);
    bool listEmpety();
    bool delNode();
    void traverse();

};

void CircularLinkedList::addNode() { // membuat awal linkedlist
    Node* newNode = new Node();
    cout << "Enter roll Number : ";
    cin >> newNode->rollNumber;
    cout << "Enter name : ";
    cin >> newNode->name;

     // membuat kolom new node
    newNode->next = LAST->next;

    //membuat kolom last poin new node
    LAST->next = newNode;
}

bool CircularLinkedList::search(int rollno, Node** rendy, Node** muhamad) {
    *rendy = LAST->next;
    *muhamad = LAST->next;

    while (*muhamad != LAST) {
        if (rollno == (*muhamad)->rollNumber) {
            return true;
        }
        *rendy = *muhamad;
        *muhamad = (*muhamad)->next;
    }

    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpety() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() { //
    if (listEmpety()) {
        cout << "List is Empety. Deletion not posibble." << endl;
        return false;
    }
    int rollno;
    cout << "Enter the roll Number of the Node to delete: ";
    cin >> rollno;

    Node* rendy = NULL;
    Node* muhamad = NULL;
    bool found = search(rollno, &rendy, &muhamad);

    if (found) { // beginning of the list
        if (rendy == LAST) { // if the node to be deleted is the only node in the list

            if (LAST->next == LAST) {
                delete LAST;
                LAST = NULL;
                cout << "Node deleted successfuly. List is now Empety" << endl;
                return true;
            }
            LAST->next = muhamad->next;
            delete muhamad;
            cout << "Node deleted successfuly." << endl;
            return true;
        }
        // end off the list
        if (muhamad == LAST) {
            rendy->next = muhamad->next;
            LAST = rendy;
            delete muhamad;
            cout << "Noted deleted successfuly." << endl;
            return true;
        }

        //betwen two nodes in the list
        rendy->next = muhamad->next;
        delete muhamad;
        cout << "Node deleted successfuly." << endl;
        return true;
    }
    else {
        cout << "Node not found in the list." << endl;
        return false;
    }
}

void CircularLinkedList::traverse() {
    if (listEmpety()) {
        cout << "\nList is Empety\n";
    }
    else {
        cout << "\nRecords in the list are :\n";
        Node* muhamadNode = LAST->next;
        while (muhamadNode != LAST) {
            cout << muhamadNode->rollNumber << "  " << muhamadNode->name << endl;
            muhamadNode = muhamadNode->next;
        }
        cout << LAST->rollNumber << "  " << LAST->name << endl;
    }
}

int main()
{
    CircularLinkedList obj;
}

