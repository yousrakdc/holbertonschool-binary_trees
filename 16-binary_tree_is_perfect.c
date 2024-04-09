#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: Pointer to the tree.
 * Return: If tree is NULL, the function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	if (tree->left != NULL)
		left_height = binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_height = binary_tree_height(tree->right);

	return (left_height >= right_height ? (left_height + 1) : right_height + 1);
}


/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer of the tree
 * Return: If tree is NULL, your function must return 0
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if ((!tree->left) && (!tree->right))
		return (1);

	if (binary_tree_height(tree->left) != (binary_tree_height(tree->right)))
		return (0);
	return (binary_tree_is_perfect(tree->left) &&
		(binary_tree_is_perfect(tree->right)));
}
