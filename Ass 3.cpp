#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    Node* prev;
    Node* next;

    Node(string n) {
        name = n;
        prev = next = nullptr;
    }
};

void insertEnd(Node*& head, Node*& tail, string name) {
    Node* newNode = new Node(name);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "(Empty)\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->name;
        if (temp->next != nullptr)
            cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

int countQueue(Node* head) {
    int cnt = 0;
    while (head != nullptr) {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void removeAtPosition(Node*& head, Node*& tail, int pos) {
    if (pos <= 0) {
        cout << "Position must be greater than 0!\n";
        return;
    }

    Node* temp = head;
    int idx = 1;

    while (temp != nullptr && idx < pos) {
        temp = temp->next;
        idx++;
    }

    if (temp == nullptr) {
        cout << "No such position !\n";
        return;
    }

    cout << "Customer called for table: " << temp->name << endl;

    if (temp == head) head = temp->next;
    if (temp == tail) tail = temp->prev;

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
}

void runTestCase(vector<string> names, int pos) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (auto& n : names) {
        insertEnd(head, tail, n);
    }

    cout << "\nUpdated waiting list:\n";
    removeAtPosition(head, tail, pos);
    displayList(head);
    cout << "Queue size: " << countQueue(head) << " customers waiting\n";
}

int main() {
    runTestCase({"Karim","Fatima","Hasan","Aisha","Rashid","Nura"},3);
    runTestCase({"Jamal","Sana","Riyad","Nazia","Imran"},8);
    runTestCase({"Arif","Nasrin","Karim","Mehnaz","Samir","Joya"},6);
    runTestCase({"Faisal"},1);
    runTestCase({"Rashed","Hafsa","Nasim","Sumaya","Farah"},0);

    return 0;
}

