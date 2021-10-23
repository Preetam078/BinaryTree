#include<bits/stdc++.h>
using namespace std;

struct Node {

int Data;
Node* left;
Node* right;
  
 Node(int Data, Node* left, Node* right){

     this->Data = Data;
     this->left = left;
     this->right = right;
 }


};


void singleChildNode(Node* node, Node* parent){
   
   if(node == NULL){
       return ;
   }

   if(parent != NULL && parent->left == node && parent->right ==NULL){
       cout<<node->Data<<" ";
   }else if(parent != NULL && parent->right == node && parent->left == NULL){
       cout<<node->Data<<" ";
   }
   singleChildNode(node->left, node);
   singleChildNode(node->right, node);
}

int main(){
    
  Node* root = new Node(50,NULL, NULL);
  root->left = new Node(100,NULL, NULL);
  root->right = new Node(60,NULL,NULL);
  root->left->left = new Node(10,NULL,NULL);
  root->right = new Node(70,NULL,NULL);
  root->right->left = new Node(30,NULL,NULL);
  

  singleChildNode(root,NULL);

    return 0;
}