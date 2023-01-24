/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:20:05 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/24 15:23:51 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
#define BST_HPP

# include <iostream>
# include <algorithm>
# include <queue>

template <class T>
class   BST {
    private:
        struct Node
        {
            T       data;
            Node*   left;
            Node*   right;
            Node*   parent;
            int     height;
        };
        Node*       root;

    public:
        BST()
        {
            root = NULL;
        }

        Node*   newNode(const T& value)
        {
            Node* newNode = new Node;

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;
            newNode->parent = NULL;
            newNode->height = 0;
            return newNode;
        }

        void    insert(T data)
        {
            root = insert(root, data);
        }

        Node*   insert(Node* node, T data)
        {
            if (node == NULL)
                return newNode(data);
            if (node->data > data)
            {
                node->left = insert(node->left, data);
                node->left->parent = node;
                node->height = node->left->height + 1;
            }
            else if (node->data < data)
            {
                node->right = insert(node->right, data);
                node->right->parent = node;
                node->height = node->right->height + 1;
            }
            return node;
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
        
        bool found(const T& val)
        {
            return found(root, val);
        }

        bool found(Node* root, const T& val)
        {
            if (root == NULL)
                return false;
            if (root->data > val)
                return found(root->left, val);
            if (root->data < val)
                return found(root->right, val);
            return true;
        }

        void    remove(T val)
        {
            root = remove(root, val);
        }

        Node*    remove(Node*& node, T val)
        {
            if (!node)
                return nullptr;
            if (node->data > val)
                node->left = remove(node->left, val);
            else if (node->data < val)
                node->right = remove(node->right, val);
            else
            {
                node = remove_node(node);
            }
            return node;
        }

        Node*   remove_node(Node*& node)
        {
            if (node->left == NULL && node->right == NULL)
                return NULL;
            else if (node->left == NULL)
            {
                node->parent->right = node->right;
                return node;
            }
            if (node->right == NULL)
            {
                node->parent->left = node->left;
                return node;
            }
            Node* succ = find_successor(node->right);
            node->data = succ->data;
            node->right = remove(node->right, succ->data);
            return node;
        }

        Node*   find_successor(Node* root)
        {
            while (root->left != NULL)
                root = root->left;
            return root;
        }
        
        int     max_of_height(Node*& n1, Node*& n2)
        {
            if (!n1 && !n2) return 0;
            if (!n1) return n1->height;
            if (!n2) return n2->height;
            return std::max(n1->height, n2->height);
        }
        
        void    printTree()
        {
            printTree(root, 0);
        }

        void printTree(Node* root, int depth) {
            if (root == NULL)
                return ;
            printTree(root->right, depth+1);
            for (int i = 0; i < depth; i++)
                std::cout << "            ";
            std::cout << root->data;
            if (root->parent)
                std::cout << ", P : " << root->parent->data;
            else
                std::cout << " i am the root";
            std::cout << std::endl << std::endl;
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

#endif
