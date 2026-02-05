#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string name;
    int runs;
    Node* next;

    Node(string n, int r) {
        name = n;
        runs = r;
        next = nullptr;
    }
};

void insertFirst(Node*& head, string name, int runs) {
    Node* newNode = new Node(name, runs);
    newNode->next = head;
    head = newNode;
}

void displayTopPerformers(Node* head) {
    bool found = false;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->runs > 20) {
            cout << temp->name << " - " << temp->runs << " runs\n";
            found = true;
        }
        temp = temp->next;
    }

    if (!found) {
        cout << "No one!\n";
    }
}

void runTestCase(vector<pair<string,int>> players) {
    Node* head = nullptr;

    for (auto& p : players) {
        insertFirst(head, p.first, p.second);
    }

    cout << "\nTop Performers (Runs > 20):\n";
    displayTopPerformers(head);
}

int main() {

    runTestCase({
        {"Sakib",45},{"Tamim",18},{"Mushfiqur",32},{"Afif",15},{"Litton",28}
    });

    runTestCase({
        {"Virat",50},{"Rohit",35},{"Pant",22},{"Bumrah",5}
    });

    runTestCase({
        {"Kane",19},{"Smith",17},{"Warner",20}
    });

    runTestCase({
        {"Raina",35},{"Dhoni",35},{"Yuvraj",28},{"Sehwag",28},{"Kumble",10}
    });

    runTestCase({
        {"Arafat",67},{"Mustafiz",8},{"Taskin",12},{"Shoriful",19},
        {"Fizzy",31},{"Hasan",24},{"Mahmud",15},{"Tanzim",22},
        {"Rishad",28},{"Hridoy",35}
    });

    return 0;
}

