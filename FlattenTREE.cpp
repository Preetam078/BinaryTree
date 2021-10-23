#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void flatten(Node* node){
  if(node == NULL || (node->left == NULL && node->right == NULL)){
      return;
  }

   if(node->left != NULL){
       flatten(node->left);

       Node* temp = node->right;
       node->right = node->left;
       node->left = NULL;

       Node* t = node->right;

       while(t->right != NULL){
          t = t->right;
       }

       t->right = temp;
    }
      
   flatten(node->right);
   
}

void inorder(Node* node){

    if(node == NULL){
        return;
    }

    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);


    flatten(root);
    inorder(root);
    cout<<endl;


    return 0;
}