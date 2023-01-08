/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:20:05 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/08 21:57:52 by mkarim           ###   ########.fr       */
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

        void    print_inorder()
        {
            print_inorder(root);
            std::cout << std::endl;
        }
        
        void    print_inorder(Node* root)
        {
            if (root == NULL)
                return ;
            print_inorder(root->left);
            std::cout << root->data << " ";
            print_inorder(root->right);
        }

        void    print_preorder()
        {
            print_preorder(root);
            std::cout << std::endl;
        }
        
        void    print_preorder(Node* root)
        {
            if (root == NULL)
                return ;
            std::cout << root->data << " ";
            print_preorder(root->left);
            print_preorder(root->right);
        }

        void    print_postorder()
        {
            print_postorder(root);
            std::cout << std::endl;
        }

        void    print_postorder(Node* root)
        {
            if (root == NULL)
                return ;
            print_postorder(root->left);
            print_postorder(root->right);
            std::cout << root->data << " ";
        }
};

int main()
{
    BST bst;

    bst.insert(20);
    bst.insert(10);
    bst.insert(40);
    bst.insert(0);
    bst.insert(15);
    bst.insert(50);
    bst.insert(30);

    bst.printTree();
    bst.print_inorder();
    bst.print_preorder();
    bst.print_postorder();
    return 0;
}