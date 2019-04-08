#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef  struct record {
    char  title[50];
    char  author[50];
    char publisher[50];
    int publishyear;
    float price;
    int quantity;
    struct record *link;
       } Node;

int choice = 0;
int isEmpty(Node *);
int searchList(char [50], Node **);
int searchList_a (char author[50], Node **);
int searchList_p (char publisher[50], Node **);
int searchList_y (int publishyear, Node **);
int deletenode(char [50], Node **);
void order_q(Node**);
void searchBook(void);
void instructions(void);
void printlist(Node **);
void addBook (char[50], char[50], char[50], int, float, int, Node **);

int main ()
{
    Node *Head=NULL;
    char  title[50];
    char  author[50];
    char publisher[50];
    int publishyear;
    float price;
    int quantity;
    
     do{
        instructions();
        scanf("%d",&choice);
        switch (choice){
            case 1://Add book
                printf("\nEnter the title of book: ");
                scanf("%s", &title);
                printf("Enter the author of \"%s\": ",title);
                scanf("%s", &author);
                printf("Enter the publisher of \"%s\": ",title);
                scanf("%s", &publisher);
                printf("Enter the year of publish of \"%s\": ",title);
                scanf("%d", &publishyear);
                printf("Enter the price of \"%s\": $",title);
                scanf("%f", &price);
                printf("Enter the quantity of \"%s\": ",title);
                scanf("%d", &quantity);
                addBook(title, author, publisher,publishyear, price, quantity, &Head);
                
                break;
            case 2://Delete book
                if ( !isEmpty( Head ) ) 
				{ 
                   printf( "\nEnter the title of the book you want to delete: " );
				   scanf( "%s", &title );
                    if ( deletenode(title, &Head) ) { 
                       printf( "\n%s is deleted.\n", title );
                     }
                    else
                       printf( "\n%s is not exist.\n\n", title );
                }
                else
                     printf( "\nList is empty.\n\n" );
                break;
            case 3://Display
                printlist(&Head);
                break;
            case 4://Search
				if ( !isEmpty( Head ) ) 
				searchBook();
				else
					printf( "\nList is empty.\n\n" );
                break;
            case 5:
				order_q(&Head);
                break;
            case 6://order
                break;
			case 7://search
				if ( !isEmpty( Head ) ) 
                { 
                    printf( "\nEnter the title of the book you want to search: " );
                    scanf( "%s", &title );
                   if ( searchList(title, &Head) == 1) 
                      printf( "\n%s is found.\n", title );
                   else
                      printf( "\n%s is not in the list.\n\n", title );
                }
                else
                  printf( "\nList is empty.\n\n" );
				
            default:
                   printf("\nInvalid input\n");
                   break;
        }
     }while (choice != 6);

return 0;
}


void searchBook(void)
{
	Node *Head=NULL;
	char  title[50];
    char  author[50];
    char publisher[50];
	int choice_s;
	int publishyear;
	
	
		printf("\n~~~~~ Search Book ~~~~~");
					printf(
						"\n          1.     Search by title"
						"\n          2.     Search by author"
						"\n          3.     Search by publisher"
						"\n          4.     Search by year of publish"
						"\n          5.     Cancel\n");
					scanf("%d",&choice_s);
					if (choice_s == 1){
                       
                            printf( "\nEnter the title of the book you want to search: " );
                            scanf( "%s", &title );
                            if ( searchList(title, &Head) ) {
                               printf( "\n%s is found.\n", title );
							 }
                            else
                               printf( "\n %s is not in the list.\n\n", title );
					}

					else if (choice_s == 2){
						
                            printf( "\nEnter the author of the book you want to search: " );
                            scanf( "%s", &author );
                            if ( searchList_a(author, &Head) ) {
                               printf( "\nBook of %s is found.\n", author );
				            }
                            else
                               printf( "\nBook of %s is not in the list.\n\n", author );
					}

					else if (choice_s == 3){
						 
                            printf( "\nEnter the publisher of the book you want to search: " );
                            scanf( "%s", &publisher );
                            if ( searchList_p(publisher, &Head) ) {
                               printf( "\nBook published by %s is found.\n", publisher );
				            }
                            else
                               printf( "\nBook published by %s is not in the list.\n\n", publisher );
					}

					else if (choice_s == 4){
					
                            printf( "\nEnter the publish year of the book you want to search: " );
                            scanf( "%s", &publishyear );
                            if ( searchList_y(publishyear, &Head) ) {
                               printf( "\nBook published in %d is found.\n", publishyear );
				            }
                            else
                               printf( "\nBook published in %d is not in the list.\n\n", publishyear );
					}
	                    
}

void addBook (char title[50], char author[50],char publisher[50], int publishyear, float price, int quantity, Node **Head)
{
    Node *pQt;
    pQt = (Node *) malloc(sizeof(Node));
    strcpy(pQt->title,title);
	strcpy(pQt->author,author);
	strcpy(pQt->publisher,publisher);
    pQt->publishyear = publishyear;
    pQt->price = price;
    pQt->quantity = quantity;
    pQt->link = NULL;

    if (*Head == NULL) 
	{
		*Head = pQt;
    } 
	else 
	{ 
        pQt->link = *Head;
        *Head = pQt;
    }
}



void printlist(Node **Head)
{
    Node *tmp;
    tmp = *Head;
    int i = 0;

    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
    
    while (tmp != NULL) 
	{
        i = i + 1;
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            i, tmp->title, tmp->author, tmp->price, tmp->quantity, tmp->publisher, tmp->publishyear);

    tmp = tmp->link;
    }
}


void instructions(void){
    printf("\n*****HKBU & SCE BookShop System (Please choose the Service) *****\n"
        "     1.     Add a new book into the current book list\n"
        "     2.     Delet a book from the book list\n"
        "     3.     Display the book list\n"
		"     4.     Search a book(type search)\n"
		"     5.     Change type of redering(uncomplete)\n"
        "     6.     Exit\n"
		"     7.     Search a book(title,perfect)\n"
        "\n"
        "-----------------------------------------------------------------------\n"
        "What is your choice? ");
}



int deletenode(char title[50], Node **Head)
{ 
   Node  *pPre, *pLoc;
   char title_1[50];
   pLoc = * Head;
   strcpy(title_1,pLoc->title);
   
   if ( strcmp( title , title_1) == 0 ) 
   { 
      pLoc = * Head;
      * Head = ( * Head)->link;  
      free( pLoc ); 
      return 1;
   }
   else 
   { 
      pPre = * Head;
      pLoc = ( * Head )->link;

      while ( pLoc != NULL && strcmp(title_1 , title) != 0 ) 
	  { 
         pPre = pLoc;          
         pLoc = pLoc->link;  
	     strcpy(title_1, pLoc->title);
      }

      if ( pLoc != NULL ) 
	  { 
         pPre->link = pLoc->link;
         free( pLoc);
         return 1;
      }                                                        
   }
   return 0;
}

int isEmpty(Node *Head)
{
    return Head == NULL;
}


int searchList (char title[50], Node **Head)
{ 
   Node  *pPre, *pLoc;
   char title_1[50];
   pLoc = *Head;
   strcpy(title_1, pLoc->title);

   if ( strcmp( title , title_1) == 0 )
   {
	   pLoc = * Head;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   else
   {
	   pPre = * Head;
       pLoc = ( * Head )->link;
       while ( pLoc != NULL && strcmp(title_1 , title) != 0 ) 
       {     
	       pPre = pLoc;
           pLoc = pLoc->link;  
	       strcpy(title_1, pLoc->title);
        }

   if (pLoc != NULL)
   {
        pPre = pLoc;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   }
   return 0;
}

int searchList_a (char author[50], Node **Head)
{ 
   Node  *pPre, *pLoc;
   char author_1[50];
   pLoc = *Head;
   strcpy(author_1, pLoc->author);

   if ( strcmp( author , author_1) == 0 )
   {
	   pLoc = * Head;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   else
   {
	   pPre = * Head;
       pLoc = ( * Head )->link;
       while ( pLoc != NULL && strcmp(author_1 , author) != 0 ) 
       {     
	       pPre = pLoc;
           pLoc = pLoc->link;  
	       strcpy(author_1, pLoc->author);
        }

   if (pLoc != NULL)
   {
        pPre = pLoc;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   }
   return 0;
}

int searchList_p (char publisher[50], Node **Head)
{ 
   Node  *pPre, *pLoc;
   char publisher_1[50];
   pLoc = *Head;
   strcpy(publisher_1, pLoc->publisher);

   if ( strcmp( publisher , publisher_1) == 0 )
   {
	   pLoc = * Head;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   else
   {
	   pPre = * Head;
       pLoc = ( * Head )->link;
       while ( pLoc != NULL && strcmp(publisher_1 , publisher) != 0 ) 
       {     
	       pPre = pLoc;
           pLoc = pLoc->link;  
	       strcpy(publisher_1, pLoc->publisher);
        }

   if (pLoc != NULL)
   {
        pPre = pLoc;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   }
   return 0;
}

int searchList_y (int publishyear, Node **Head)
{ 
   Node  *pPre, *pLoc;
   int publishyear_1;
   pLoc = *Head;

   if ( publishyear == publishyear_1 )
   {
	   pLoc = * Head;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   else
   {
	   pPre = * Head;
       pLoc = ( * Head )->link;
       while ( pLoc != NULL && publishyear_1 != publishyear ) 
       {     
	       pPre = pLoc;
           pLoc = pLoc->link;  
        }

   if (pLoc != NULL)
   {
        pPre = pLoc;
	    printf(
        "\nNo.   TITLE            AUTHOR            PRICE       QUANTITY\n"
        "      (PUBLISHER     YEAR OF PUBLISH    )\n"
        "----------------------------------------------------------------\n");
        printf(
            "%d   \t %s      \t%s             $%7.2f \t    %d \t  \n     ( %s    %d )   \n",
            1, pLoc->title, pLoc->author, pLoc->price, pLoc->quantity, pLoc->publisher, pLoc->publishyear);

      return 1;
   }
   }
   return 0;
}

/*
int order_q(Node **Head)
{
	Node *pLoc, *pPer, *pQt;
	pLoc = (Node *) malloc(sizeof(Node));
	pPer = (Node *) malloc(sizeof(Node));
	pQt = (Node *) malloc(sizeof(Node));
	pLoc = * Head;

	while (pLoc != NULL && pLoc->quantity >= pPer->quantity)
	{
	pPer = pLoc;
	pLoc = pLoc->link;
	if (pLoc->quantity < pPer->quantity)
	{
		pPer->link = pLoc->link;
		pLoc->link = pPer;
		*Head = pLoc;
	}
	}
	return 1;
}*/


 
void order_q(Node **Head)
{
	Node *pLoc, *pPer, pQt;
	pLoc = (Node *) malloc(sizeof(Node));
	pPer = (Node *) malloc(sizeof(Node));
	pLoc = * Head;
	int S = 0;
	while ( pLoc != NULL) 
       {  
           pLoc = pLoc->link;
		   S = S+1;
        }
    int i,j;
    for(i=0; i<(S-1); i++)
    {
        for(j=0; j<(S-(i+1)); j++)
        {
            {
                if (pLoc->quantity < pPer->quantity)
	            {
		         pPer->link = pLoc->link;
		         pLoc->link = pPer;
		         *Head = pLoc;
	            }
            }
 
        }
    }
}