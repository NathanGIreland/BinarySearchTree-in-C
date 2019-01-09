
/******************************************************************************
authour: Nathan Ireland
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  char * word;
  struct node * left;
  struct node * right;
} treeNode;

treeNode * head = NULL;

treeNode * addNode (treeNode * h, char * s) {
  
  if(h == NULL){
    h = (treeNode *) malloc(sizeof(treeNode));;
    h->word = s;
  }else if(strcmp(s , h->word) <= 0){
    h->left = addNode((h->left), s);
  }else{
    h->right = addNode((h->right), s);        
  }
  
  return h;  
}

 void traverse (treeNode * h) {
 //postorder traversal

 if(h != NULL){			//this allows traverse to ignore empty lists
   traverse(h -> left);
   printf("%s", h->word);
   printf("\n");
   traverse(h -> right);
 }  
 }
  

int main()
{
	
	//traversing an empty list does nothing
	printf("TEST CASE 1: EMPTY LIST\n");
	traverse(head);												
	printf("\n\n");
	
	//add some nodes, check to see if they are in alphabetical order
	printf("TEST CASE 2: ADDING NODES IN ORDER\n");
    head = addNode(head, "a");
    head = addNode(head, "b");
    head = addNode(head, "c");
    head = addNode(head, "j");
    head = addNode(head, "m");
    head = addNode(head, "z");
    head = addNode(head, "y");
    head = addNode(head, "x");
    traverse(head);
    printf("\n\n");
    
    //add more, see if they are still traversed correctly.
    //i.e. new letters are printed in correct alphabetical order with old list
    printf("TEST CASE 3: ADDING MORE NODES (WITH DUPLICATES) OUT OF ORDER\n");
    head = addNode(head, "f");
    head = addNode(head, "o");
    head = addNode(head, "d");
    head = addNode(head, "l");
    head = addNode(head, "w");
    head = addNode(head, "o");
    traverse(head);
  
    return 0;
}




