#include <bits/stdc++.h>
using namespace std;


// Node structure (using struct + constructor)

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


// Traversal Functions


// Inorder: Left -> Root -> Right (BST prints sorted order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder: Root -> Left -> Right
void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder: Left -> Right -> Root
void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Level Order: BFS
void levelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front(); q.pop();
        cout << cur->data << " ";

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}

// Print BST level by level
void printBST_LevelWise(Node* root) {
    if (!root) {
        cout << "BST is empty\n";
        return;
    }

    queue<Node*> q; //stores pointers to Node objects.
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();   // number of nodes at current level
        cout << "Level " << level << ": ";

        for (int i = 0; i < size; i++) {
            Node* cur = q.front();
            q.pop();

            cout << cur->data << " ";

            if (cur->left) q.push(cur->left); //Insert left child (if exists)
            if (cur->right) q.push(cur->right); //Insert right child (if exists)
        }
        cout << endl;
        level++;
    }
}


// BST INSERT (recursive)
// Returns the (possibly new) root pointer
Node* insertBST(Node* root, int x) {
    // If tree is empty, create first node
    if (!root) return new Node(x);

    // Go left if smaller
    if (x < root->data)
        root->left = insertBST(root->left, x);

    // Go right if larger
    else if (x > root->data)
        root->right = insertBST(root->right, x);

    // If duplicate, do nothing
    return root;
}


// BST SEARCH (iterative)

bool searchBST(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->data == key) return true;
        else if (key < cur->data) cur = cur->left;
        else cur = cur->right;
    }
    return false;
}


// Find minimum node in a subtree (leftmost node)

Node* findMin(Node* root) {
    while (root && root->left) // loop runs until root is not null and root->left exists
        root = root->left;
    return root;
}


// BST DELETE (recursive)
// Returns the (possibly new) root pointer

Node* deleteBST(Node* root, int key) {
    // If tree is empty
    if (!root) return nullptr;

    // Search in left subtree
    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    }
    // Search in right subtree
    else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    }
    // Node found
    else {
        // Case 1: Leaf node (no children)
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        // Case 2: Only right child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // Case 3: Only left child
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 4: Two children
        else {
            // Replace with inorder successor (min of right subtree)
            Node* succ = findMin(root->right);
            root->data = succ->data;

            // Delete the successor node from right subtree
            root->right = deleteBST(root->right, succ->data);
        }
    }
    return root;
}


// Delete whole tree (free memory)

void deleteTree(Node*& root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
    root = nullptr;
}


// MAIN MENU (everything in one menu)

int main() {
    Node* root = nullptr;
    int choice, x;

    while (true) {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Delete\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Level Order Traversal\n";
        cout << "8. Print BST\n";
        cout << "9. Clear BST\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                root = insertBST(root, x);
                break;

            case 2:
                cout << "Enter key: ";
                cin >> x;
                cout << (searchBST(root, x) ? "Found\n" : "Not Found\n");
                break;

            case 3:
                cout << "Enter key: ";
                cin >> x;
                root = deleteBST(root, x);
                break;

            case 4:
                if (!root) cout << "BST is empty\n";
                else { inorder(root); cout << "\n"; }
                break;

            case 5:
                if (!root) cout << "BST is empty\n";
                else { preorder(root); cout << "\n"; }
                break;

            case 6:
                if (!root) cout << "BST is empty\n";
                else { postorder(root); cout << "\n"; }
                break;

            case 7:
                if (!root) cout << "BST is empty\n";
                else { levelOrder(root); cout << "\n"; }
                break;

            case 8:
                printBST_LevelWise(root);
                break;

            case 9:
                deleteTree(root);
                cout << "BST cleared\n";
                break;

            case 0:
                deleteTree(root);
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}
