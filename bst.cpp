/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:20:05 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/09 11:57:26 by mkarim           ###   ########.fr       */
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
            int     height;
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
            newNode->height = 0;
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
            {
                node->left = insert(node->left, data);
                node->height = node->left->height + 1;
            }
            else if (node->data < data)
            {
                node->right = insert(node->right, data);
                node->height = node->right->height + 1;
            }
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
            std::cout << root->data << " - " << root->height << std::endl;

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

        bool    balanced()
        {
            return balanced(root);
        }

        bool    balanced(Node* root)
        {
            if (root == NULL || (root->left == NULL && root->right == NULL))
                return true;
            if (root->left && root->right == NULL)
            {
                if (root->left->height > 1) return false;
                return (balanced(root->left));
            }
            if (root->right && root->left == NULL)
            {
                if (root->right->height > 1) return false;
                return (balanced(root->right));
            }
            return (abs(root->right->height - root->left->height) <= 1);
        }
};

int main()
{
    BST bst;

    // bst.insert(1);
    // bst.insert(10);
    // bst.insert(100);
    // bst.insert(1000);
    
    bst.insert(20);
    bst.insert(10);
    bst.insert(40);
    bst.insert(0);
    bst.insert(15);
    bst.insert(50);
    bst.insert(30);
    bst.insert(100);
    bst.insert(10000);

    bst.printTree();
    std::cout << (bst.balanced() == true ? "Yes, it's balanced" : "No, it's not") << std::endl;
    // bst.print_inorder();
    // bst.print_preorder();
    // bst.print_postorder();
    return 0;
}