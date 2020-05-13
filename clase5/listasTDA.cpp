#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

void print_list(Node *head) {
    int count = 0;
    if (head == NULL) {
        cout << "Empty list!" << endl;
        return;
    }
    for (Node *it = head; it != NULL; it = it -> next) {
        cout << "Node " << count << ": " << it->data << endl;
        count++;
    }
}

int list_size(Node *head) {
    //Returns length of list starting at head
    int size = 0;
    for (Node *it = head; it != NULL; it = it-> next) {
        size++;
    }
    return size;
}

void list_add_first(Node *&head, int x) {
    //Inserts a node before the node head. New head is pointing to the new node
    Node *new_head = new Node;
    new_head->data = x;
    new_head->next = head;
    head = new_head;
}

void list_insert_after(Node *&node, int x) {
    //Inserts node after the node passed as argument.
    Node *new_node = new Node;
    new_node->data = x;
    new_node->next = node->next;
    node->next = new_node;
}

Node* list_search(Node *head, int x) {
    Node *it = head;
    while (it != NULL && it->data != x) {
        it = it->next;
    }
    return it;
}

Node* list_iloc(Node *head, int index) {
    Node *it = head;
    for (int i = 0; i < index; i++) {
        it = it->next;
    }
    return it;
}

void list_remove_first(Node *&head) {
    Node *to_remove = head;
    head = head->next;
    delete to_remove;
}

void list_remove_after(Node *&node) {
    Node *to_remove = node->next;
    node->next = to_remove->next;
    delete to_remove;
}

void delete_list(Node *&head) {
    while(head != NULL) {
        Node *to_remove = head;
        head = head->next;
        delete to_remove;
    }
}

void delete_list_v2(Node *&head) {
    while (head != NULL) {
        list_remove_first(head);
    }
}

int main(int argc, char** argv) {
    Node *node = NULL;
    list_add_first(node, 10);
    list_add_first(node, 5);
    list_insert_after(node, -5);
    print_list(node);
    cout << list_search(node, 10)->data << endl;
    cout << list_iloc(node, 2)->data << endl;
    list_remove_first(node);
    print_list(node);
    delete_list(node);
    print_list(node);
    return 0;
}