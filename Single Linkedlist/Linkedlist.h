/*@Amgad Diploma_C20-Linkedlist_11October2023*/
/*Single_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       3October2023
**LastUpdate: 11October2023*/

#ifndef    __LINKEDLIST_H__
#define    __LINKEDLIST_H__


enum finding_result{
    EMPTY_LIST=-2,NOT_FOUND=-1,FOUND
};
typedef struct Node
{
    u16 info;
    struct Node * link;
}Node_t;


/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/
Node_t * Insertion_at_Beginning(u16 info, Node_t * list);



/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/
Node_t * Insertion_at_Empty_List(u16 info, Node_t * list);

/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_at_End(u16 info, Node_t * list);



/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the start of the created list */
Node_t * Create_List(void);


/******************************************************************************************************************************/
/*Function:     Displaying the data of Linkedlist
* Parameters:   -list[Node_t*]: a pointer to the start of the list
* Return:       void*/
void Display_List(Node_t * list);


/******************************************************************************************************************************/
/*Function:     Searching for a given data in a Linkedlist
* Parameters:  -data[u16]:    the data wanted to search for in the list
*              -list[Node_t*]: a pointer to the start of the list
* Return:       [s16] the result of searching [EMPTY_LIST,NOT_FOUND,OR the position of data]*/
s16 Search_for_Node(u16 data , Node_t * list);



/******************************************************************************************************************************/
/*Function:     Displaying the data of the Particular Position in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to display its data 
* Return:       void*/
void Display_Node_at_Particular_Position(Node_t * list, u16 position);


/******************************************************************************************************************************/
/*Function:     Counting Nodes in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
* Return:       Number of Nodes*/
u16 Count_Nodes(Node_t * list);

/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert after it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -list[Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_after_a_Node(u16 info, Node_t * list, u16 new_info);


/************************************************************************************************before'******************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert before it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the new list*/
Node_t* Insertion_before_a_Node(u16 info, Node_t * list, u16 new_info);




/******************************************************************************************************************************/
/*Function:     Insertion a Node at Particular Position in a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to add the node in 
* Return:       a pointer to the start of the new list*/
Node_t* Insertion_at_Particular_Position(u16 info, Node_t * list, u16 position);




/******************************************************************************************************************************/
/*Function:     Delete a Node from Particular Position in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to delete the node from 
* Return:       a pointer to the start of the list after deletion*/
Node_t* Delete_from_Particular_Position( Node_t * list, u16 position);



/******************************************************************************************************************************/
/*Function:     Reversing a Single Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the list after reversing*/
Node_t * Reverse_List(Node_t* list);




#endif