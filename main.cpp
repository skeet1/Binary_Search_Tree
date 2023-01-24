/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarim <mkarim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:44:49 by mkarim            #+#    #+#             */
/*   Updated: 2023/01/24 17:15:28 by mkarim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.hpp"

int main()
{
    BST<int> bst;
    
    bst.insert(20);
    bst.insert(10);
    bst.insert(40);
    bst.insert(5);
    bst.insert(2);
    bst.insert(15);
    bst.insert(50);
    bst.insert(30);
    bst.insert(100);

    bst.remove(20);
    bst.remove(30);
    // bst.remove(50);
    // bst.remove(100);
    // bst.remove(5);

    bst.printTree();

    // std::cout << (bst.balanced() == true ? "Yes, it's balanced" : "No, it's not") << std::endl;
    // std::cout << (bst.found(370) == true ? "Yes, we found it" : "No, it's not exist") << std::endl;
    // bst.print_inorder();
    // bst.print_preorder();
    // bst.print_postorder();
    // system("leaks a.out");
    return 0;
}