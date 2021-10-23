#include<bits/stdc++.h>
using namespace std;

struct Node{

    int Data;
    Node*left;
    Node*right;

     Node(int data, Node* left, Node* right){

        Data = data;
        this->left = left;
        this->right = right;
        
    }
};

Node* leftClonedTree(Node* node){

    if(node == NULL){
        return node;
    }

    Node* lcl = leftClonedTree(node->left);
    Node* lcr = leftClonedTree(node->right);

    Node* newNode = new Node(node->Data, lcl, NULL);
    node->left = newNode;
    node->right = lcr;



    return node;
}

//this function is to transform the left cloned tree into the normal form 
Node* transformNormal(Node* node){

    if(node == NULL){
        return node;
    }

    Node* lf = transformNormal(node->left->left);
    Node* rt = transformNormal(node->right);

    node->left = lf;
    node->right = rt;

    return node;
}

void inorder(Node* node){
   
   if(node == NULL){
       return;
   }

   inorder(node->left);
   cout<<node->Data<<" ";
   inorder(node->right);

   
}

int main(){
  Node* root = new Node(50,NULL, NULL);
  root->left = new Node(100,NULL, NULL);
  root->right = new Node(60,NULL,NULL);
  root->left->left = new Node(10,NULL,NULL);
  root->left->right = new Node(40,NULL,NULL);
  root->right = new Node(70,NULL,NULL);
  root->right->left = new Node(30,NULL,NULL);
  root->right->right = new Node(90,NULL,NULL);

  Node*temp = leftClonedTree(root);
  inorder(temp);
  cout<<endl;

  Node* normal = transformNormal(temp);
  inorder(normal);
  cout<<endl;

}