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


void rightView(Node* node){

   if(node == NULL){
       return;
   }
    
   queue<Node*>q;
   q.push(node);

   while (!q.empty())
   {
       int n = q.size();
       for(int i = 0;i<n;i++){
           Node * curr = q.front();
           q.pop();

           if( i == n-1){
               cout<<curr->data<<endl;
           }
           if(curr->left != NULL){
               q.push(curr->left);
           }
           if(curr->right != NULL){
               q.push(curr->right);
           }
       }
   }
   
}

int main(){

    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

   rightView(root);

    return 0;
}