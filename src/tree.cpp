#include"tree.h"

CNode* find_or_add_el(CNode *root, int v) {
  while (root) {
    if (root->inf == v) {
      return root;
    } else if (root->inf < v) {
      if (!root->right) {
        root->right = new CNode(v);
        return root->right;
      } else if (root->right) {
        root = root->right;
      }
    } else if (root->inf > v) {
      if (!root->left) {
        root->left = new CNode(v);
        return root->left;
      } else if (root->inf > v) {
        root = root->left;
      }
    }
  }
  return 0;
}

/* void print_recursion(CNode* root,int& size) {
 	printf("%i", root->inf);
 	if (root->right) {
 		printf(" - ");
 		size++;
 		print_recursion(root->right, size);
 	}
 	if (root->left) {
 		if (root->right) {
 			printf("\n");
 		}
 		int buf = size;
 		if (size > 1) {
 			while ((--buf) != 0) {
 					printf("|   ");
 			}
 			printf("  \\");
 			printf("\n");
 			buf = --size;
 			while ((buf--) > 0) {
 				printf("|   ");
 			}
 			printf("   ");
 		}
 		else if (size <= 1) {
 			if (!root->right) {
 				printf("\n");
 			}
 			printf("|");
 			printf("\n");
 		}
 		print_recursion(root->left, size);
 		if (!root->right) {
 			printf("\n");
 		}
 		
 	}
 	else if (!root->left && root->right) {
 		size--;
 	}
 
 }
 
 void CNode:: print_tree() {
 	CNode* root = this;
 	int size = 1;
 	if (root) {
 		printf("%i", root->inf);
 		if (root->right) {
 			printf(" - ");
 			print_recursion(root->right, size);
 		}
 		else if (!root->left) {
 			printf(" - *");
 			printf("\n");
 			printf("|");
 		}
 		size --;
 		printf("\n");
 		if(root->left) {
 			printf("|");
 			printf("\n");
 			print_recursion(root->left, size);
 			printf("\n");
 		}
 		else if (!root->left) {
 			printf("|");
 			printf("\n");
 			printf("*");
 		}
 
 	}
 		//1 - 2 - 3
 		//|     \ 
 		//|	     4
 		//|
 		//5 - 6
 		//|	  \ 
 		//|    7
 		//8 - 9
 		//|
 		// 10	
 }
 
 void input_recursion(CNode* root) {
 	int flag = 0;
 	printf("Are you input right branch to %i? (1 - yes, 0 - no) ", root->inf);
 	printf("\n");
 	scanf("%i", &flag);
 	if (flag) {
 		root->right = new CNode;
 		printf("Input right branch - ");
 		scanf("%i", &root->right->inf);
 		input_recursion(root->right);
 		printf("\n");
 	}
 	else if (!flag) {
 		root->right = 0;
 	}
 	flag = 0;
 	printf("Are you input left branch to %i? (1 - yes, 0 - no) ", root->inf);
 	printf("\n");
 	scanf("%i", &flag);
 	if (flag) {
 		root->left = new CNode;
 		printf("Input left branch - ");
 		scanf("%i", &root->left->inf);
 		input_recursion(root->left);
 	}
 	else if (!flag) {
 		root->left = 0;
 	}
 }
 
 void CNode:: input_tree() {
 	printf("Input root tree - ");
 	scanf("%i", &this->inf);
 	printf("\n");
 	input_recursion(this);
 } */
