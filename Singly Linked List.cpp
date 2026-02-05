#include <bits/stdc++.h>  // Includes all standard libraries

using namespace std;


// Node class representing each element of the linked list
class Node {
public:
    int data; // Stores the data
    Node* link; // Pointer to the next node

    // Constructor to initialize a node with given data
    Node(int data) {
        this->data = data;
        this->link = nullptr;
    }
};

// Global pointer to the first node (head) of the linked list
Node* head = nullptr;


// -------------------- INSERT FIRST --------------------
void insertFirst(int data) {
    Node* newNode = new Node(data); // Create a new node
    newNode->link = head; // New node points to current head
    head = newNode; // Update head to new node
}


// -------------------- INSERT LAST --------------------
void insertLast(int data) {
    Node* newNode = new Node(data); // Create a new node
    if (head == nullptr) { // If list is empty
        head = newNode; // New node becomes head
        return;
    } else {
        Node* current = head; // Start from head
        while (current->link != nullptr) { // Traverse to last node
            current = current->link;
        }
        current->link = newNode; // Attach new node at the end
    }
}

// -------------------- INSERT AT A POSITION --------------------
void insertAt(int data, int position) {
    if (position < 0) { // Invalid position check
        cout << "Invalid position." << endl;
        return;
    } else if (position == 0) { // Insert at beginning
        insertFirst(data);
        return;
    } else {
        Node* newNode = new Node(data);
        Node* current = head; // Start from head
        int currentPosition = 0;

        // Traverse until reaching the node before the desired position
        while (current != nullptr && currentPosition < position - 1) {
            current = current->link;
            currentPosition++;
        }
        // If current becomes NULL, position is out of range
        if (current == nullptr) {
            cout << "Position exceeds the length of the list. Node not inserted." << endl;
            delete newNode; // Delete unused node
            return;
        } else {
            // Insert newNode between current and current->link
            newNode->link = current->link;
            current->link = newNode;
        }
    }
}

// -------------------- DELETE FIRST --------------------
void deleteFirst() {
    if (head == nullptr) { // Empty list
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    } else {
        Node* temp = head;  // Store current head
        head = head->link; // Move head to next node
        delete temp;  // Delete old head
    }
}

// -------------------- DELETE LAST --------------------
void deleteLast() {
    if (head == nullptr) {  // Empty list
        cout << "The list is empty. Nothing to delete." << endl;
        return;
    } else if (head->link == nullptr) { // Only one node
        delete head;
        head = nullptr; // List becomes empty
        return;
    } else {
        Node* current = head;
        // Traverse until reaching the second last node
        while (current->link->link != nullptr) {
            current = current->link;
        }
        delete current->link; // Delete last node
        current->link = nullptr; // Update second last node
    }
}

// -------------------- DELETE A SPECIFIC ITEM --------------------
void deleteItem(int item) {
    Node* current = head; // Start from head
    Node* prev = nullptr; // Previous pointer

    while (current != nullptr) {  // Traverse list
        if (current->data == item) { // Item found
            if (prev != nullptr) { // Node is not the first node
                prev->link = current->link; // Bypass current node
            } else {
                head = current->link; // Item is in the first node
            }
            delete current; // Delete node
            return;
        } else {
            prev = current; // Move prev
            current = current->link; // Move current forward
        }
    }
    cout << "Item not found. Node not deleted." << endl;
}

// -------------------- SEARCH ITEM --------------------
int searchItem(int item) {
    Node* current = head; // Start from head
    int position = 0; // Track index
    while (current != nullptr) {
        if (current->data == item) { // Item found

            return position;
        } else {
            current = current->link; // Move to next node
            position++;
        }
    }
    return -1; // Item not found
}

void printList() {
    Node* current = head; // Start from head
    cout << "Linked list: ";
    while (current != nullptr) {
        cout << current->data << " -> "; // Print data
        current = current->link; // Move forward
    }
    cout << "NULL" << endl; // End of list
}

int main() {
    int option, data, position, item;

    while (true) {
        cout << "\n!!!  MENU  !!!\n";
        cout << "1. Insert First\n";
        cout << "2. Insert Last\n";
        cout << "3. Insert At\n";
        cout << "4. Delete First\n";
        cout << "5. Delete Last\n";
        cout << "6. Delete Item\n";
        cout << "7. Print the list\n";
        cout << "8. Search\n";
        cout << "9. Quit\n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter data to insert at the beginning: ";
                cin >> data;
                insertFirst(data);
                break;
            case 2:
                cout << "Enter data to insert at the end: ";
                cin >> data;
                insertLast(data);
                break;
            case 3:
                cout << "Enter data to insert: ";
                cin >> data;
                cout << "Enter position to insert at: ";
                cin >> position;
                insertAt(data, position);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                cout << "Enter the item to delete: ";
                cin >> item;
                deleteItem(item);
                break;
            case 7:
                printList();
                break;
            case 8:
                cout << "Enter the item to search: ";
                cin >> item;
                position = searchItem(item);
                if (position != -1) {
                    cout << "Item found at position " << position << "." << endl;
                } else {
                    cout << "Item not found in the list." << endl;
                }
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid option. Please select a valid option." << endl;
        }
    }

    return 0;
}

