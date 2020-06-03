#include <iostream>
#include <queue>
using namespace std;

struct BinaryTreeNode {
    int data;
    BinaryTreeNode *left = NULL;
    BinaryTreeNode *right = NULL;
};

void pre_order(BinaryTreeNode *root) {
    if (root != NULL) {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void post_order(BinaryTreeNode *root) {
    if (root != NULL) {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}

void in_order(BinaryTreeNode *root) {
    if (root != NULL) {
        post_order(root->left);
        cout << root->data << " ";
        post_order(root->right);
    }
}

void level_order(BinaryTreeNode *root) {
    queue<BinaryTreeNode*> levels;
    if (root != NULL) {
        levels.push(root);
    }
    while (!levels.empty()) {
        BinaryTreeNode * curr_node = levels.front();
        levels.pop();
        cout << curr_node->data << " ";
        if (curr_node->left != NULL) {
            levels.push(curr_node->left);
        }
        if (curr_node->right != NULL) {
            levels.push(curr_node->right);
        }
    }
}

void add_node_BST(BinaryTreeNode *&root, int x) {
    if (root == NULL) {
        root = new BinaryTreeNode;
        root->data = x;
        return;
    }

    if (x < root->data) {
        add_node_BST(root->left, x);
    }
    else if (x > root->data) {
        add_node_BST(root->right, x);
    }
}

BinaryTreeNode * search_BST(BinaryTreeNode *root, int x) {
    if (root != NULL) {
        if (root->data == x) {
            return root;
        }
        else if (x < root->data) {
            return search_BST(root->left, x);
        }
        else {//x > root->data
            return search_BST(root->right, x);
        }
    }
    return NULL;
}

void delete_tree(BinaryTreeNode *&root) {
    if (root != NULL) {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

int main() {
    BinaryTreeNode *root = NULL;
    root = new BinaryTreeNode;
    root->data = 1;
    root->left = new BinaryTreeNode;
    root->left->data = 2;
    root->right = new BinaryTreeNode;
    root->right->data = 3;
    root->left->left = new BinaryTreeNode;
    root->left->left->data = 4;
    root->right->right = new BinaryTreeNode;
    root->right->right->data = 5;

    pre_order(root);
    cout << endl;
    post_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    level_order(root);
    cout << endl;

    delete_tree(root);

    root = NULL;
    add_node_BST(root, 5);
    add_node_BST(root, 10);
    add_node_BST(root, 2);
    add_node_BST(root, -1);
    add_node_BST(root, 9);
    pre_order(root);
    cout << endl;

    BinaryTreeNode * search = search_BST(root, 10);
    if (search != NULL) cout << search->data << endl;
    else cout << "No ta el 10" << endl;

    search = search_BST(root, 3);
    if (search != NULL) cout << search->data << endl;
    else cout << "No ta el 3" << endl;

    delete_tree(root);
    return 0;



}