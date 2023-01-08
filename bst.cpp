/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:20:05 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/08 21:41:47 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <queue>

class   BST {
    private:
        struct Node
        {
            int     data;
            Node*   left;
            Node*   right;
        };
        Node*       root;

    public:
        BST()
        {
            root = NULL;
            i = 10;
        }

        Node*   newNode(const int& value)
        {
            Node* newNode = new Node;

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        void    insert(int data)
        {
            root = insert(root, data);
        }

        Node*   insert(Node* node, int data)
        {
            if (node == NULL)
                return newNode(data);
            if (node->data > data)
                node->left = insert(node->left, data);
            else if (node->data < data)
                node->right = insert(node->right, data);
            return node;
        }
        
        void    printTree()
        {
            printTree(root, 0);
        }

        void printTree(Node* root, int depth) {
            if (!root)
                return ;

            printTree(root->right, depth+1);

            for (int i = 0; i < depth; i++) {
                std::cout << "   ";
            }
            std::cout << root->data << std::endl;

            printTree(root->left, depth+1);
        }
};

int main()
{
    BST bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    bst.printTree();
    return 0;
}