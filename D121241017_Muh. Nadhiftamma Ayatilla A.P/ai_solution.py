'''
Binary Tree Height Analysis

Based on the screenshots provided, I'll explain how to calculate the height of a binary tree.
Understanding the Problem

The height of a binary tree is defined as:

    The number of edges between the root node and the furthest leaf node

    A tree with only one node (the root) has height 0

Example from the Screenshots

The sample explanation shows:

    A path with nodes 1 → 2 → 3 → 4 → 5 → 6 → 7

    4 nodes connected by 3 edges → height = 3

(Note: There seems to be a discrepancy in the explanation - 7 nodes connected by 6 edges would actually make height = 6, but the output says height = 3. This might be a typo in the sample.)
Solution Approach

To implement the getHeight or height function:

    If the root is null, return -1 (as there are no nodes)

    Recursively calculate the height of the left and right subtrees

    Return the maximum of the left and right subtree heights, plus 1
'''

class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def height(root):
    if root is None:
        return -1
    left_height = height(root.left)
    right_height = height(root.right)
    return max(left_height, right_height) + 1

'''
How It Works

    For a leaf node (both children are None), it returns max(-1, -1) + 1 = 0

    For each level up the tree, we add 1 to the height of the taller subtree

    The base case handles empty subtrees by returning -1, which ensures correct counting when we add 1

Note on Binary Search Tree Construction

The problem mentions that nodes are inserted into a BST before the root is passed to your function:

    Left child nodes have values less than the parent

    Right child nodes have values greater than the parent

However, your function only needs to calculate the height and doesn't need to handle the BST construction.

This implementation will correctly calculate the height of any binary tree according to the given definition.
'''
