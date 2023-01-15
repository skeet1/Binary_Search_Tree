/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:20:05 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/15 09:15:11 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
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
                std::cout << "        ";
            }
            std::cout << root->data << ", h : " << root->height << std::endl << std::endl;

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
        
        bool found(const int& val)
        {
            return found(root, val);
        }

        bool found(Node* root, const int& val)
        {
            if (root == NULL)
                return false;
            if (root->data > val)
                return found(root->left, val);
            if (root->data < val)
                return found(root->right, val);
            return true;
        }

        void    remove(int val)
        {
            remove(root, val);
        }

//         void    remove(Node*& root, int val)
//         {
//             if (root == NULL)
//                 return ;
//             if (root->data == val)
//             {
//                 if (root->left == NULL && root->right == NULL)
//                 {
//                     delete root;
//                     root = nullptr;
//                 }
//                 else if (root->left == NULL && root->right)
//                 {
//                     root->data = root->right->data;
//                     root->left = root->right->left;
//                     root->right = root->right->right;
//                     root->height = root->right->height;
//                     delete root->right;
//                     root->right = nullptr;
//                 }
//                 else if (root->left && root->right == NULL)
//                 {
//                     root->data = root->left->data;
//                     root->right = root->left->right;
//                     root->left = root->left->left;
//                     root->height = root->height;
//                     delete root->left;
//                     root->left = nullptr;
//                 }
//                 else
//                 {
//                     Node* before = root->right;
//                     Node* tmp = root->right;
//                     while (tmp)
//                     {
//                         before = tmp;
//                         tmp = tmp->left;
//                     }
//                     root->data = before->data;
//                     delete before;
//                     before = nullptr;
//                 }
//             }
//             else if (root->data > val)
//                 remove(root->left, val);
//             else
//                 remove(root->right, val);
//         }
// };

        Node* findMin(Node* root)
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
        void remove(Node*& root, int val)
        {
            if (root == NULL) return;

            if (val < root->data)
                remove(root->left, val);
            else if (val > root->data)
                remove(root->right, val);
            else 
            {
                if (root->left == NULL && root->right == NULL)
                {
                    delete root;
                    root = nullptr;
                }
                else if (root->left == NULL)
                {
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if (root->right == NULL)
                {
                    Node* temp = root;
                    root = root->left;
                    delete temp;
                }
                else
                {
                    Node* temp = findMin(root->right);
                    root->data = temp->data;
                    remove(root->right, temp->data);
                }
            }
            if (root != NULL)
            {
                if (root->left == NULL && root->right == NULL)
                    root->height = 0;
                else if (root->left == NULL)
                    root->height = root->right->height + 1;
                else if (root->right == NULL)
                    root->height = root->left->height + 1;
                else
                    root->height = std::max(root->left->height, root->right->height) + 1;
            }
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

    bst.remove(20);
    bst.remove(100);
    bst.remove(10000);
    bst.remove(50);
    bst.remove(40);

    bst.printTree();

    // std::cout << (bst.balanced() == true ? "Yes, it's balanced" : "No, it's not") << std::endl;
    // std::cout << (bst.found(370) == true ? "Yes, we found it" : "No, it's not exist") << std::endl;
    // bst.print_inorder();
    // bst.print_preorder();
    // bst.print_postorder();
    return 0;
}