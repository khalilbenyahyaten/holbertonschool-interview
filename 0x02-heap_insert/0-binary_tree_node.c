#include "binary_trees.h"
/**
 * binary_tree_node - create a binary tree node
 *@value:  value
 *@parent: pointer
 *Return: binary_tree_t
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *node;
node = malloc(sizeof(binary_tree_t));
if (node == NULL)
{
return (0);
}
node->parent = parent;
node->n = value;
node->left = NULL;
node->right = NULL;
return (node);
}
