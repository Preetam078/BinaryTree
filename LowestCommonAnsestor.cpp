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


Node* LCA(Node* node, int n1, int n2){

    if(node == NULL){
        return NULL;
    }

   if(node->data == n1 || node->data == n2){
       return node;
   }

   Node* leftLCA = LCA(node->left, n1, n2);
   Node* rightLCA = LCA(node->right, n1, n2);

   if(leftLCA && rightLCA){
       return node;
   }
   if(leftLCA != NULL){
       return leftLCA;
   }
   else{
       return rightLCA;
   }
   return NULL;
}


int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    int n1 = 60, n2 = 70;

    Node* temp = LCA(root,n1,n2);

    if(temp == NULL){
        cout<<"LCA does not exist"<<endl;
    } 
    else{
        cout<<"LCA "<<temp->data<<endl;
    }

    return 0;
}