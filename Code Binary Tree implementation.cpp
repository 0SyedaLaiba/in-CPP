#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Binary Tree class
class BinaryTree {
public:
    Node* root;
    
    BinaryTree() {
        root = nullptr;
    }

    // Insert a node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }
    
    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    
    void inorder() {
        inorder(root);
        cout << endl;
    }
    
    // Preorder Traversal (Root, Left, Right)
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    
    void preorder() {
        preorder(root);
        cout << endl;
    }
    
    // Postorder Traversal (Left, Right, Root)
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    
    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Inorder Traversal: ";
    tree.inorder();
    
    cout << "Preorder Traversal: ";
    tree.preorder();
    
    cout << "Postorder Traversal: ";
    tree.postorder();
    
    return 0;
}
