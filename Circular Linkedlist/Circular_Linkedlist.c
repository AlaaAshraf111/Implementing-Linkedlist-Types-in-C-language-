/*@Amgad Diploma_C21-Circular_Linkedlist_17October2023*/
/*Circular_Linkedlist_Driver*/
/*Auther:     Alaa Ashraf
**Date:       3October2023
**LastUpdate: 19October2023*/

#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "Circular_Linkedlist.h"


/******************************************************************************************************************************/
/*Function:     Insertion a Node at Beginning of a Circular Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/

void Insertion_at_Beginning(u16 info, Circular_Node_t * Last){
    //Create the inserted node in the list
    Circular_Node_t * temp =(Circular_Node_t*) malloc(sizeof(Circular_Node_t));
    temp->info =info;
    temp->link=Last->link;                  /*Make the new node points to the previous first node*/
    Last->link=temp;                        /*Update the reference the Last*/
   
}


/******************************************************************************************************************************/
/*Function:     Insertion a Node to an Empty Circular Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list after adding the node*/

Circular_Node_t * Insertion_at_Empty_List(u16 info, Circular_Node_t * Last){
    //Create the inserted node in the list
    Circular_Node_t * temp =(Circular_Node_t*) malloc(sizeof(Circular_Node_t));
    
    temp->info =info;
    //Note: the order is important, as at frist the Last is NULL and has no link    
    Last=temp;                   /*Update the reference to the list*/
    Last->link=temp;          /*Make the new node points to itself*/
    return Last;
}





/******************************************************************************************************************************/
/*Function:     Insertion a Node at end of a Circular Linkedlist
* Parameters:  -info[u16]:     the data wanted to be stored in the node
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list after adding the node*/

Circular_Node_t * Insertion_at_End(u16 info, Circular_Node_t * Last){

    if(Last == NULL){
        printf("\nThe list is Empty\n");
    }else{
        //Here there is no traverse, as Last points to the last node in the list
        //Create the inserted node in the list
        Circular_Node_t * temp =(Circular_Node_t*) malloc(1*sizeof(Circular_Node_t));
        temp->info =info;

        temp->link=Last->link;    /*Make the new node points to the previous first node*/
        Last->link = temp;          /*Make the previous last node points to temp(new last node)*/

        Last=temp; /*Update the reference to the end of list*/
        
    }

    return Last;
}



/******************************************************************************************************************************/
/*Function:     Create a Linkedlist
* Parameters:   void
* Return:       a pointer to the end of the created list */

Circular_Node_t * Create_List(void){
    //Create pointer Last points to the empty list
    Circular_Node_t * Last = NULL;

    u32 Node_Count;
    printf("Enter the number of wanted Nodes in the linkedlist : ");
    scanf("%d",&Node_Count);

    if(Node_Count != 0){
        u32 data;
        printf("Enter the data of the node no. %d : " ,1);
        scanf("%d",&data);
    

        //insert it in the empty list
        Last = Insertion_at_Empty_List(data,Last);
        for(u16 i=1; i<Node_Count ; i++){

        printf("Enter the data of the node no. %d : " ,i+1);
        scanf("%d",&data);
        Last =Insertion_at_End(data,Last);

        }
    }else{
        /*Do Nothing*/
    }

    
    return Last;
}


/******************************************************************************************************************************/
/*Function:     Displaying the data of Circular Linkedlist
* Parameters:   -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/
void Display_List(Circular_Node_t * Last){
    if(Last==NULL)
	{
		printf("List is empty\n");
	}
	
	else
	{
    Circular_Node_t * p=Last->link;
    u16 i=1;
    /*Using do{}while(); to enter the loop with condition while(p != Last->link)*/
    do{            //Note: using this condition while(p != Last) will not display the last info
        printf("The node no. %d and its data is %d\n", i++ , p->info);
        p=p->link;
    }while(p != Last->link);  //Return to the frist node means passing through whole list
    }
}

/******************************************************************************************************************************/
/*Function:     Searching for a given data in a Linkedlist
* Parameters:  -data[u16]:    the data wanted to search for in the list
*              -list[Circular_Node_t*]: a pointer to the end of the list
* Return:       [s16] the result of searching [EMPTY_LIST,NOT_FOUND,OR the position of data]*/
s16 Search_for_Node(u16 data , Circular_Node_t * Last){

    //Make position signed integer to check on [EMPTY_LIST,NOT_FOUND] results and found poistion in the same variable
    s16 position=1;  //Initialize poistion with 1

    if(Last==NULL)           //Check on EMPTY_LIST
 	{
        position = EMPTY_LIST;
	}
	
	else
	{
    Circular_Node_t * p=Last->link;
    
    do{
        if(p->info == data){
            break;
        }else{/*Do Nothing*/}
        position++;   //In 1st Pass, poistion will be 1 and increases to 2, So there is a need to initialize it with 1
        p=p->link;
    }while(p != Last->link);  //Return to the frist node means passing through whole list

    if ((p==Last->link) && (position > 1))   //Check on NOT_FOUND & (position>1) means passing through whole list
    { 
        position = NOT_FOUND;
    }else{/*Do Nothing*/}   
    
    }
    return position;
}



/******************************************************************************************************************************/
/*Function:     Insertion after a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert after it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -list[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the new end of the list*/
Circular_Node_t * Insertion_after_a_Node(u16 info, Circular_Node_t * Last, u16 new_info){
    Circular_Node_t * p= Last->link;

    if(Last == NULL){

        printf("\nThe list is Empty\n");
    }else{
        enum finding_result Check;

        do{
            //Using enum to check on the reason of break
            Check=NOT_FOUND;
            //Check on position
            if(p->info == info){
                Check=FOUND;
                break;
            }
            //Traverse
            p=p->link;
        }while(p != Last->link);  //Return to the frist node means passing through whole list

        //Out of this loop with p points to the Last->link Node (frist node) OR p points to the Node has info
        //Check if the Node has info is found or not
        if(Check == FOUND){

            //the position if found
            //Create the inserted node in the list
            Circular_Node_t * temp =(Circular_Node_t*) malloc(1*sizeof(Circular_Node_t));
            temp->info =new_info;
            temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
            p->link = temp;

            if(p == Last)  /*If the Node has info is last node*/
            {
                //Update the reference Last to the new last node
                Last = temp;
            }else{/*Do Nothing*/}

        }
        else{
            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        }
    }
    return Last;
}





/************************************************************************************************before'******************************/
/*Function:     Insertion before a Node in a Linkedlist
* Parameters:  -info[u16]:     the data of Node wanted to insert before it
*              -new_info[u16]:     the data of Node wanted to be insert 
*              -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       void*/
void Insertion_before_a_Node(u16 info, Circular_Node_t * Last, u16 new_info){
    
    if(Last == NULL){

            printf("\nThe list is Empty\n");

    }else{
        Circular_Node_t * p= Last->link;
        
        enum finding_result Check=NOT_FOUND;

        do{
            //Using enum to check on the reason of break
            Check=NOT_FOUND;

            if((p->link)->info == info){            //We need the place before the node has the info so, stop at the node preivous the node with info
                Check=FOUND;

                //the node with info if found
                //Create the inserted node in the list
                Circular_Node_t * temp =(Circular_Node_t*) malloc(1*sizeof(Circular_Node_t));
                temp->info =new_info;
                temp->link=p->link;    //makes link in temp points to the next node AND link in p (selected node) points to temp
                p->link = temp;
                break;

            }else if(p->info == info){
                Check=FOUND;
                Insertion_at_Beginning(new_info,Last);

                break;
            }
            //Traverse
            p=p->link;
            
        }while(p != Last->link);  //Return to the frist node means passing through whole list

        if(Check == NOT_FOUND){
            printf("\nThe Node has the %d is NOT_FOUND in the list\n",info);
        }else{
            /*Do Nothing*/
        }

    }

    
}



/******************************************************************************************************************************/
/*Function:     Delete a Node with Particular Data in a Linkedlist
* Parameters:  -Last[Circular_Node_t*]: a pointer to the end of the list
*              -data[u16]: the data wanted to delete its node  
* Return:       a pointer to the end of the list after deletion*/
Circular_Node_t* Delete_with_Particular_Data( Circular_Node_t * Last, u16 data){

    /*The list is Empty*/
    if(Last == NULL){
        printf("\nThe list is Empty\n");
    }
    /*Delete the ONLY node*/
    else if((Last->link == Last)){
        //if the only node has the wanted data
        if((Last->info == data)){
            Circular_Node_t * temp =(Circular_Node_t*) malloc(1*sizeof(Circular_Node_t));
            temp = Last;
            Last = NULL;
            free(temp);
        }else{
            printf("\nThe Node has data %d is NOT_FOUND\n",data);
        }
    
    }
    /*Delete Node in between*/
    /*and Delete the Last Node*/
    else{
        Circular_Node_t * p= Last->link;

        enum finding_result Check;
        do{
            //Using enum to check on the reason of break
            Check=NOT_FOUND;
            //Check on data
            if((p->link)->info == data){
                Check=FOUND;
                break;
            }
            //Traverse
            p=p->link;

        }while(p != Last->link);  //Return to the frist node means passing through whole list

        //Out of this loop with p returns pointing to the frist Node OR p points to the Node before that has the particular data
        //Check if data is found or not
        if(Check == FOUND){
            //the Node has data if found

            //Deleted the Last node in list 
            if(p->link == Last){
                Last=p;  //Update the reference Last with its pervious node (the new last node) 
            }else{/*Do Nothing*/}

            //Create a node used in deletion operation
            Circular_Node_t * temp =(Circular_Node_t*) malloc(1*sizeof(Circular_Node_t));
            temp = p->link;
            p->link=temp->link;    //makes p points to the next node skipping the deleted node
            free(temp);
        }
        else{
            printf("\nThe Node has data %d is NOT_FOUND\n",data);
        }

    }
    
    return Last;
}


/******************************************************************************************************************************/
/*Function:     Reversing a Circular Linkedlist
* Parameters:  -Last[Circular_Node_t*]: a pointer to the end of the list
* Return:       a pointer to the end of the list after reversing*/
Circular_Node_t * Reverse_List(Circular_Node_t* Last){

    if(Last == NULL){
        printf("\nThe list is Empty\n");
    }else if((Last->link == Last)){            //The list has ONLY node the Last
        /*Do Nothing*/
        /*As the Last points to itself and with reversing or without*/
    }else{
        Circular_Node_t * prev=Last;
        Circular_Node_t * ptr = Last->link;
        Circular_Node_t * next= NULL;
        do{
            next = ptr->link;
            ptr->link =prev;    //Reverse
            //Traverse
            prev = ptr;
            ptr = next;

        }while(prev != Last );  //With prev pointer returning to the Last node means passing through whole list

        Last =ptr;    //Update the reference Last with the pervious frist node (the new last node after Reversing)
    }
    return Last;
}
