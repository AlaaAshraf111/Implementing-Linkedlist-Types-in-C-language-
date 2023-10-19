/*@Amgad Diploma_C20-Linkedlist_11October2023*/
/*Single_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       3October2023
**LastUpdate: 11October2023*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "Linkedlist.h"


/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/

Node_t * Insertion_at_Beginning(u16 info, Node_t * list){
    //Create the inserted node in the list
    Node_t * temp =(Node_t*) malloc(sizeof(Node_t));
    temp->info =info;
    temp->link=list;                  /*Make the new node points to the previous first node*/
    list=temp;                        /*Update the reference to the list*/
    return list;
}


/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the new start of the list after adding the node*/

Node_t * Insertion_at_Empty_List(u16 info, Node_t * list){
    //Create the inserted node in the list
    Node_t * temp =(Node_t*) malloc(sizeof(Node_t));
    
    temp->info =info;
    temp->link=list;             /*Make the new node points to the previous first node[which in empty list is null]*/
    list=temp;                   /*Update the reference to the list*/
    return list;
}





/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
* Return:       void*/

void Insertion_at_End(u16 info, Node_t * list){
    Node_t * p= list;
    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        while (p->link != NULL)  //p->link (the last Node)
        {
            //Traverse
            p=p->link;
        }
        //Create the inserted node in the list
        Node_t * temp =(Node_t*) malloc(1*sizeof(Node_t));
        temp->info =info;
        //Out of this loop with p points to the last Node
        // p->link=temp;
        // temp ->link =NULL;
        //OR 
        temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
        p->link = temp;
        
    }
}



/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the start of the created list */

Node_t * Create_List(void){
    //Create pointer start points to the empty list
    Node_t * start = NULL;

    u32 Node_Count;
    printf("Enter the number of wanted Nodes in the linkedlist : ");
    scanf("%d",&Node_Count);

    if(Node_Count != 0){
        u32 data;
        printf("Enter the data of the node no. %d : " ,1);
        scanf("%d",&data);
    

        //insert it in the empty list
        start = Insertion_at_Beginning(data,start);

        for(u16 i=1; i<Node_Count ; i++){

        printf("Enter the data of the node no. %d : " ,i+1);
        scanf("%d",&data);
        Insertion_at_End(data,start);

        }
    }else{
        /*Do Nothing*/
    }

    
    return start;
}


/******************************************************************************************************************************/
/*Function:     Displaying the data of Linkedlist
* Parameters:   -list[Node_t*]: a pointer to the start of the list
* Return:       void*/
void Display_List(Node_t * list){
    if(list==NULL)
	{
		printf("List is empty\n");
	}
	
	else
	{
    Node_t * p=list;
    u16 i=1;
    while(p != NULL){
        printf("The node no. %d and its data is %d\n", i++ , p->info);
        p=p->link;
    }
    }
}

/******************************************************************************************************************************/
/*Function:     Searching for a given data in a Linkedlist
* Parameters:  -data[u16]:    the data wanted to search for in the list
*              -list[Node_t*]: a pointer to the start of the list
* Return:       [s16] the result of searching [EMPTY_LIST,NOT_FOUND,OR the position of data]*/
s16 Search_for_Node(u16 data , Node_t * list){

    //Make position signed integer to check on [EMPTY_LIST,NOT_FOUND] results and found poistion in the same variable
    s16 position=1;

    if(list==NULL)           //Check on EMPTY_LIST
 	{
        position = EMPTY_LIST;
	}
	
	else
	{
    Node_t * p=list;
    
    while(p != NULL){
       if(p->info == data){
            break;
       }else{/*Do Nothing*/}
        position++;
        p=p->link;
    }
    if (p==NULL){ position = NOT_FOUND;}   //Check on NOT_FOUND
    else{/*Do Nothing*/}   
    
    }
    return position;
}



/******************************************************************************************************************************/
/*Function:     Displaying the data of the Particular Position in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to display its data 
* Return:       void*/
void Display_Node_at_Particular_Position(Node_t * list, u16 position){
    Node_t * p= list;
    u16 count=1;
    enum finding_result Check;
    while (p != NULL)  //p->link (the Node before the last Node)
    {
        //Using enum to check on the reason of break
        Check=NOT_FOUND;
        //Check on position
        if(count == position){
            Check=FOUND;
            break;
        }
        //Traverse
        p=p->link;
        count++;
        
    }

    //Out of this loop with p points to the last Node OR p points to the Node in the particular position
    //Check if position is found or not
    if(Check == FOUND){
        //the position if found
        //Display the node
         printf("The node no. %d and its data is %d\n", position , p->info);
    }
    else{
        printf("\nThe node at position %d is NOT_FOUND\n",position);
    }
    
}


/******************************************************************************************************************************/
/*Function:     Counting Nodes in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
* Return:       Number of Nodes*/
u16 Count_Nodes(Node_t * list){
    u16 Count=0;

    Node_t * p=list;

    while(p != NULL){
       
        Count++;
        p=p->link;
    }
    return Count;

}




/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert after it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -list[Node_t*]: a pointer to the start of the list
* Return:       void*/
void Insertion_after_a_Node(u16 info, Node_t * list, u16 new_info){
    Node_t * p= list;

    if(list == NULL){

        printf("\nThe list is Empty\n");
    }else{
        enum finding_result Check;
        while (p!= NULL)  //p->link (the Node before the NULL)
        {
            //Using enum to check on the reason of break
            Check=NOT_FOUND;
            //Check on position
            if(p->info == info){
                Check=FOUND;
                break;
            }
            //Traverse
            p=p->link;
        
            
        }

        //Out of this loop with p points to the last Node OR p points to the Node has info
        //Check if the Node has info is found or not
        if(Check == FOUND){
            //the position if found
            //Create the inserted node in the list
            Node_t * temp =(Node_t*) malloc(1*sizeof(Node_t));
            temp->info =new_info;
            temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
            p->link = temp;
        }
        else{
            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        }
    }
    
}





/************************************************************************************************before'******************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert before it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the new list*/
Node_t* Insertion_before_a_Node(u16 info, Node_t * list, u16 new_info){

    Node_t * list_after_adding_node=NULL;     //Returning pointer
    
    if(list == NULL){

            printf("\nThe list is Empty\n");

    }else{
        Node_t * p= list;
        
        enum finding_result Check=NOT_FOUND;
        
        while (p->link!= NULL)  //p->link (the Node before the NULL)
        {
            //Using enum to check on the reason of break
            Check=NOT_FOUND;

            if((p->link)->info == info){            //We need the place before the node has the info so, stop at the node preivous the node with info
                Check=FOUND;

                //the node with info if found
                //Create the inserted node in the list
                Node_t * temp =(Node_t*) malloc(1*sizeof(Node_t));
                temp->info =new_info;
                temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
                p->link = temp;
                list_after_adding_node=list;            //As the return pointer in all cases is list_after_adding_node 
                break;

            }else if(p->info == info){
                Check=FOUND;
                list_after_adding_node = Insertion_at_Beginning(new_info,list);

                break;
            }
            //Traverse
            p=p->link;
        
            
        }

        if(Check == NOT_FOUND){

            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
            list_after_adding_node = list;
        }else{
            /*Do Nothing*/
        }

    }
    return list_after_adding_node;
    
}




/******************************************************************************************************************************/
/*Function:     Insertion a Node at Particular Position in a Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to add the node in 
* Return:       a pointer to the start of the new list*/
Node_t* Insertion_at_Particular_Position(u16 info, Node_t * list, u16 position){
    Node_t * list_after_adding_node=list;     //Returning pointer

    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        Node_t * p= list;
        u16 count=1;
        enum finding_result Check;

        //In case the position wanted to insert at is the first poition in list
        if(count == position){
            Check=FOUND;
            list_after_adding_node = Insertion_at_Beginning(info,list);
        }else{
            while (p->link != NULL)  //p->link (the Node before the last Node)
            {
                //Using enum to check on the reason of break
                Check=NOT_FOUND;
                //Check on position
                if(count == (position-1)){   //makes p points to the node before the particular position to insert the selected node at position
                    Check=FOUND;
                    break;
                }
                //Traverse
                p=p->link;
                count++;
                
            }
            //Out of this loop with p points to the last Node OR p points before the particular position
            //Check if position is found or not
            if(Check == FOUND){
                //the position if found
                //Create the inserted node in the list
                Node_t * temp =(Node_t*) malloc(1*sizeof(Node_t));
                temp->info =info;
                temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
                p->link = temp;
            }
            else{
                printf("\nThe position %d is NOT_FOUND\n",position);

            }
        }
    }
    
    return list_after_adding_node;
}



/******************************************************************************************************************************/
/*Function:     Delete a Node from Particular Position in a Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
*              -position[u16]: the position wanted to delete the node from 
* Return:       a pointer to the start of the list after deletion*/
Node_t* Delete_from_Particular_Position( Node_t * list, u16 position){
    Node_t * list_after_delete_node=list;     //Returning pointer

    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        Node_t * p= list;
        u16 count=1;
        enum finding_result Check;

        //In case the deleted node is the first node in list
        if(count == position){
            Check=FOUND;
            list_after_delete_node=p->link;
            free(p);

        }else{
            while (p->link != NULL)  //p->link (the Node before the last Node)
            {
                //Using enum to check on the reason of break
                Check=NOT_FOUND;
                //Check on position
                if(count == (position-1)){
                    Check=FOUND;
                    break;
                }
                //Traverse
                p=p->link;
                count++;
                
            }
            //Out of this loop with p points to the last Node OR p points to the Node before the particular position
            //Check if position is found or not
            if(Check == FOUND){
                //the position if found
                //Create a node used in deletion operation
                Node_t * temp =(Node_t*) malloc(1*sizeof(Node_t));
                temp = p->link;
                p->link=temp->link;    //makes p points to the next node skipping the deleted node
                free(temp);
            }
            else{
                printf("\nThe position %d is NOT_FOUND\n",position);

            }
        }
    }
    
    return list_after_delete_node;
}


/******************************************************************************************************************************/
/*Function:     Reversing a Single Linkedlist
* Parameters:  -list[Node_t*]: a pointer to the start of the list
* Return:       a pointer to the start of the list after reversing*/
Node_t * Reverse_List(Node_t* list){
    if(list == NULL){
        printf("\nThe list is Empty\n");
    }else{
        Node_t * prev=NULL;
        Node_t * ptr = list;
        Node_t * next= NULL;
        while(ptr != NULL){
            next = ptr->link;
            ptr->link =prev;    //Reverse
            //Traverse
            prev = ptr;
            ptr = next;
        }
        list =prev;
    }
    return list;
}
