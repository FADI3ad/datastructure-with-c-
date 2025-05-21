#include <bits/stdc++.h>
using namespace std;
#define el endl
#define ll long long
#define str string
#define dl double
#define ch char
#define What_F() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class node {
public:
    int  value;
    node * next_address;
};

void insert_begin(node *&head , int val) {
    node* newnode= new node();
    newnode->value=val;
    newnode->next_address=head;
    head=newnode;
}

void insert_after_value(node* head  ,   int target_value  , int  val) {


    while (head != nullptr && head->value != target_value) {
        head = head->next_address;
    }

    if (head == nullptr) return;

    node* newnode = new node();
    newnode->value = val;

    newnode->next_address = head->next_address;
    head->next_address = newnode;
}


void  insert_end(node *& head  , int  val ) {
    node  * newnode =  new node();
    newnode->value=val;
    newnode->next_address=NULL;
    if (head==nullptr) {
        head=newnode;
        return;
    }

    node  * temp=head;
    while (temp->next_address!=NULL) {
        temp=temp->next_address;
    }
    temp->next_address=newnode;
}



void delete_begin(node*& head) {
    if (head == nullptr) return;
    node* temp = head;
    head = head->next_address;
    delete temp;
}


void delete_after_value(node*& head, int target_value) {

    node* temp = head;

    while (temp != nullptr && temp->value != target_value) {
        temp = temp->next_address;
    }

    if (temp == nullptr || temp->next_address == nullptr) return;

    node* node_to_delete = temp->next_address;
    temp->next_address = node_to_delete->next_address;
    delete node_to_delete;
}


void delete_end(node *&head) {
    if (head == nullptr) return;
    if (head->next_address == NULL) {

        delete head;
        head = NULL;
        return;
    }
    node   * temp  =head;
    while (temp->next_address->next_address!=NULL) {
        temp=temp->next_address;
    }
    delete temp->next_address;
    temp->next_address=NULL;
}


bool search(node* head, int target_value) {
    while (head != nullptr) {
        if (head->value == target_value) {
            return true;
        }
        head = head->next_address;
    }
    return false;
}


void print_list(node *  head) {

    while (head!=NULL) {
        cout<<head->value<<" ";
        head=head->next_address;
    }
}


int main() {
    What_F();


    node * head = nullptr;

    insert_begin(head,2);
    insert_begin(head,1);
    insert_end(head,3);
    insert_end(head,4);
    insert_end(head,5);
    insert_end(head,6);
    insert_end(head,7);
    insert_end(head,8);
    insert_end(head,8);
    insert_after_value(head,6,7);
    delete_after_value(head,5);
    delete_begin(head);
    delete_end(head);
    print_list(head);
    cout<<el;
    if (search(head,6)) {
        cout<<"yes"<<el;
    }
    else {
        cout<<"no";
    }




}