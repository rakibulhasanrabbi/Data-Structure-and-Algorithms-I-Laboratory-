#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    int price;
    Node* next;

    Node(string n, int p) {
        name = n;
        price = p;
        next = nullptr;
    }
};


void insertFirst(Node*& head, string name, int price) {
    Node* newNode = new Node(name, price);
    newNode->next = head;
    head = newNode;
}


int displayCart(Node* head) {
    int total = 0;
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->name << " - " << temp->price << endl;
        total += temp->price;
        temp = temp->next;
    }
    cout << "Total: " << total << " Taka\n";
    return total;
}


bool deleteItem(Node*& head, string item) {
    if (head == nullptr) return false;

    if (head->name == item) {
        Node* del = head;
        head = head->next;
        delete del;
        return true;
    }

    Node* curr = head;
    while (curr->next != nullptr) {
        if (curr->next->name == item) {
            Node* del = curr->next;
            curr->next = del->next;
            delete del;
            return true;
        }
        curr = curr->next;
    }
    return false;
}

void runTestCase(
    vector<pair<string, int>> items,
    string removeItem,
    bool emptyInput = false
) {
    Node* head = nullptr;

    for (auto& item : items) {
        insertFirst(head, item.first, item.second);
    }

    cout << "\nCart Items:\n";
    int beforeTotal = displayCart(head);

    if (emptyInput) {
        cout << "\nProduct name cannot be empty!\n";
        cout << "Cart items remained unchanged.\n";
        cout << "Cart Items:\n";
        displayCart(head);
        return;
    }

    cout << "\nProduct to remove: " << removeItem << endl;

    bool removed = deleteItem(head, removeItem);

    if (removed) {
        cout << "\n" << removeItem << " Removed Successfully!\n";
        cout << "Updated Cart:\n";
        displayCart(head);
    } else {
        cout << "\nItem '" << removeItem << "' not found in cart!\n";
        cout << "Cart remains unchanged:\n";
        displayCart(head);
    }
}

int main() {

    runTestCase(
        {
            {"Monitor",15000},
            {"USB Cable",500},
            {"Monitor",12000},
            {"Keyboard",3500},
            {"Mouse",1200}
        },
        "Monitor"
    );

    runTestCase(
        {
            {"Laptop",50000},
            {"Phone",25000},
            {"Headphones",3000},
            {"Charger",1500}
        },
        "Headphones"
    );

    runTestCase(
        {
            {"Router",8500},
            {"Modem",6000},
            {"Switch",4000}
        },
        "",
        true
    );

    runTestCase(
        {
            {"Camera",45000},
            {"Speaker",8000},
            {"Microphone",5000},
            {"Stand",2000}
        },
        "Stand"
    );

    runTestCase(
        {
            {"Router",8500},
            {"Modem",6000},
            {"SSD",12000},
            {"RAM",4500}
        },
        "Printer"
    );

    return 0;
}

