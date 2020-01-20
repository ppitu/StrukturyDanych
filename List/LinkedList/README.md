# Linked List

**Why Linked List**  
We select the Linked Distance List that the arrays have the following restrictions:  
**1.** The size of the array is constant: so we need to know the upper limit of the number of elements in advance. Moreover, an array always occupies the same amount of memory regardless of the number of elements in it.   
**2.** Inserting a new element is expensive because it requires moving the rest of the elements. The same goes for the removal of an element.   

**Advantages over arrays**  
**1.** Dynamic size  
**2.** Ease of insertion / deletion  

**Drawbacks**  
**1.** Random access is not allowed. We have to access elements sequentially starting from the first node.  
**2.** Extra memory space for a pointer is required.  
**3.** Not cache friendlly.  

**Representation**  
A linked list is represented by a pointer to the first node of linked list. If the linked list is empty, then the value of the head is NULL. Each node in a list consists od at least two parts:  
1. Data  
2. Pointer to the next node  

In C, we can represent a nod using structures. In other programming language (C++, Java, Python) we use class.  

**Functions**  

**`void push(T data)`**

The function added an elemets before the head. Newly added node becomes the new
 head of Linked List. In C functions has a special Node*\* argumnet `void push(Node** headref, T data)` that passes the reference to the function.  

**`void deleteNode(t data)`**  
  
The function delete an elements from linked list.  
