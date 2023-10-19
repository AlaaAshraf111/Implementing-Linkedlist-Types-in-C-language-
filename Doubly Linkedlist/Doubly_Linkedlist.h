/*@Amgad Diploma_C20-Doubly_Linkedlist_17October2023*/
/*Doubly_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       17October2023
**LastUpdate: 17October2023*/


#ifndef    __DOUBLY_LINKEDLIST_H__
#define    __DOUBLY_LINKEDLIST_H__

enum finding_result{
    EMPTY_LIST=-2,NOT_FOUND=-1,FOUND
};
typedef struct Node
{
    u32 info;
    struct Node * next;
    struct Node * prev;
}Doubly_Node_t;

/******************************************************************************************************************************/
/*Function:     Displaying the data of Linkedlist
* Parameters:   -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
void Display_List(Doubly_Node_t * list);

/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Linkedlist
* Parameters:  -info[u32]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/
Doubly_Node_t * Insertion_at_Beginning(u32 info, Doubly_Node_t * list);

/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Linkedlist
* Parameters:  -info[u32]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/
Doubly_Node_t * Insertion_at_Empty_List(u32 info, Doubly_Node_t * list);


/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Linkedlist
* Parameters:  -info[u32]:     the data wanted to be stored in the node
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_at_End(u32 info, Doubly_Node_t * list);



/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u32]:     the data of Node wanted to insert after it
*              -new_info[u32]:     the data of Node wanted to be insert 
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_after_a_Node(u32 info, Doubly_Node_t * list, u32 new_info);


/******************************************************************************************************************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u32]:     the data of Node wanted to insert before it
*              -new_info[u32]:     the data of Node wanted to be insert 
*              -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the new list*/
Doubly_Node_t * Insertion_before_a_Node(u32 info, Doubly_Node_t * list, u32 new_info);


/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the start of the created list */
Doubly_Node_t * Create_List(void);


/******************************************************************************************************************************/
/*Function:     Delete a Node with Particular data in a Linkedlist
* Parameters:  -list[Doubly_Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to delete the node from 
* Return:       a pointer to the start of the list after deletion*/
Doubly_Node_t* Delete_A_Node( Doubly_Node_t * list, u32 data);


/******************************************************************************************************************************/
/*Function:     Reversing a Single Linkedlist
* Parameters:  -list[Doubly_Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the list after reversing*/
Doubly_Node_t * Reverse_List(Doubly_Node_t* list);


#endif