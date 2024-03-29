#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "bst.h"
#include "rb.h"
const int Rep = 32;
const int MaxLen = 128;

void preorder_string_avl(const struct avl_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->avl_data));
	if(node->avl_link[0] != NULL || node->avl_link[1] != NULL)
	{
		putchar('(');
		preorder_string_avl(node->avl_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_avl(node->avl_link[1]);
		putchar(')');
	}
}

void preorder_string_bst(const struct bst_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->bst_data));
	if(node->bst_link[0] != NULL || node->bst_link[1] != NULL)
	{
		putchar('(');
		preorder_string_bst(node->bst_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_bst(node->bst_link[1]);
		putchar(')');
	}
}

void preorder_string_rb(const struct rb_node *node)
{
	if(node == NULL)
		return;
	printf("%s ", ((char*)node->rb_data));
	if(node->rb_link[0] != NULL || node->rb_link[1] != NULL)
	{
		putchar('(');
		preorder_string_rb(node->rb_link[0]);
		putchar(',');
		putchar(' ');
		preorder_string_rb(node->rb_link[1]);
		putchar(')');
	}
}

int string_cstyle_compare(const void *pa, const void *pb, void *param)
{
	const char* a = (const char*)pa;
	const char* b = (const char*)pb;
	if     (strcmp(a,b)<0)	return -1;
	else if(strcmp(a,b)>0)	return +1;
	else                    return 0;
}

int main()
{
	struct avl_table *avl_tree;
	struct bst_table *bst_tree;
	struct rb_table  *rb_tree;
	avl_tree = avl_create(string_cstyle_compare, NULL, NULL);
	bst_tree = bst_create(string_cstyle_compare, NULL, NULL);
	rb_tree  = rb_create(string_cstyle_compare, NULL, NULL);
	for(int i=0; i<Rep; i++)
	{
		char* a = (char*)malloc(sizeof(char) * MaxLen);
		char* b = (char*)malloc(sizeof(char) * MaxLen);
		char* c = (char*)malloc(sizeof(char) * MaxLen);
		scanf("%s",a);
		strcpy(b,a);
		strcpy(c,a);
		void **p = avl_probe(avl_tree, a);
		void **p2= bst_probe(bst_tree, b);
		void **p3= rb_probe (rb_tree,  c);
	}
	preorder_string_avl(avl_tree->avl_root);
	printf("\n");
	preorder_string_bst(bst_tree->bst_root);
	printf("\n");
	preorder_string_rb(rb_tree->rb_root);
	printf("\n");
	return 0;
}
