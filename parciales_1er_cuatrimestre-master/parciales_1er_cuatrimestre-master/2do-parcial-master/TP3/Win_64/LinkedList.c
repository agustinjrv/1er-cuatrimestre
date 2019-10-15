#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)calloc(1,sizeof(LinkedList));

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this!= NULL)
    {
        returnAux=ll_get_Size(this);
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    int tam=ll_len(this);
    int i;
    Node* pNodo=NULL;

    if(this!=NULL && nodeIndex<tam && nodeIndex>=0)
    {

        if(nodeIndex==0)
        {
            pNodo=ll_get_firstNode(this);

        }
        else
        {
            pNodo=ll_get_firstNode(this);

            for(i=1; i<=nodeIndex; i++)
            {
                pNodo=ll_get_NextNode(pNodo);
            }
        }
    }

    return pNodo;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int tam=ll_len(this);


    Node* pNuevoNodo=(Node*)malloc(sizeof(Node));
    Node* pAnteriorNodo=(Node*)malloc(sizeof(Node));
    Node* pAuxNode=(Node*)malloc(sizeof(Node));

    int i;


    if(this!=NULL && nodeIndex<=tam && nodeIndex>=0)
    {

        ll_set_NodeElement(pNuevoNodo,pElement);
        ll_setNextNode(pNuevoNodo,NULL);


        if(nodeIndex==0)
        {
            ll_setNextNode(pNuevoNodo,ll_get_firstNode(this));
            ll_setFirstNode(this,pNuevoNodo);
        }
        else
        {
            pAnteriorNodo=this->pFirstNode;
            pAuxNode=this->pFirstNode;;

            for(i=1;i<=nodeIndex;i++)
            {
                pAuxNode=pAuxNode->pNextNode;

                if(i==nodeIndex-1)
                {
                    pAnteriorNodo=pAuxNode;
                }
            }
            pNuevoNodo->pNextNode=pAnteriorNodo->pNextNode;
            pAnteriorNodo->pNextNode=pNuevoNodo;
        }

        this->size++;
        returnAux=0;
    }



    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam=ll_len(this);

    if(this!=NULL)
    {
        addNode(this,tam,pElement);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* unNodo;

    unNodo=getNode(this,index);
    if(unNodo!=NULL)
    {
        returnAux=ll_get_NodeElement(unNodo);

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNodo=NULL;

    pNodo=getNode(this,index);

    if(pNodo!=NULL)
    {
        pNodo->pElement=pElement;
        returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* pNodoAnterior=NULL;
    Node* pNodoRemover=NULL;

    if(index==0)
    {
        pNodoRemover=getNode(this,index);

        if(pNodoRemover!=NULL)
        {
            this->pFirstNode=pNodoRemover->pNextNode;
            free(pNodoRemover);
            this->size--;
            returnAux=0;

        }

    }
    else
    {
        pNodoAnterior=getNode(this,index-1);
        pNodoRemover=getNode(this,index);

        if(pNodoAnterior!=NULL && pNodoRemover !=NULL)
        {
            pNodoAnterior->pNextNode=pNodoRemover->pNextNode;
            free(pNodoRemover);
            this->size--;
            returnAux=0;
        }
    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int i;
    int tam=ll_len(this);
    int sePudo=0;

    if(this!=NULL)
    {

        for(i=0;i<tam;i++)
        {
            if(sePudo!=-1)
            {
               sePudo=ll_remove(this,i);
            }
            else
            {
                break;
            }
        }

        if(sePudo!=-1)
        {
            returnAux = 0;
        }

    }



    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        returnAux=0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;

    if(this!=NULL)
    {
        int tam=ll_len(this);
        void* unElemento;


        for(i=0;i<tam;i++)
        {
            unElemento=ll_get(this,i);

            if(unElemento==pElement)
            {
                returnAux=i;
                break;
            }

        }

    }




    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        if(this->size==0 )
        {
            returnAux = 1;
        }
        else
        {
            returnAux=0;
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    returnAux=addNode(this,index,pElement);

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int tam=ll_len(this);

    if(this!=NULL && index<=tam && index>=0)
    {
        returnAux=ll_get(this,index);
        ll_remove(this,index);
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* pAuxElemento=NULL;

    if(this!=NULL)
    {
        int tam=ll_len(this);
        returnAux=0;

        if(pElement!=NULL)
        {
              for(i=0;i<=tam;i++)
              {
                 pAuxElemento=ll_get(this,i);

                 if(pElement==pAuxElemento)
                 {
                     returnAux=1;
                     break;
                 }
              }
        }


    }



    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    void* pElement;
    int i;

    if(this!=NULL &&this2!=NULL)
    {
        int tam=ll_len(this2);

        returnAux=0;

        for(i=0;i<tam;i++)
        {
            pElement=ll_get(this2,i);

            if(pElement!=NULL)
            {
                returnAux=ll_contains(this,pElement);
                if(returnAux==0)
                {
                    break;
                }
            }
        }
    }



    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int tam=ll_len(this);
    int i;
    void* pElement;

    if(this!=NULL && from>=0 && to<=tam && from<to)
    {
        cloneArray=ll_newLinkedList();

        for(i=from;i<=to;i++)
        {
            pElement=ll_get(this,i);
            ll_add(cloneArray,pElement);
        }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    int tam=ll_len(this);

    cloneArray=ll_subList(this,0,tam);

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    void* pElement1 ;
    int i,j;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
        for(i = 0; i < (ll_len(this)-1); i++)
        {
            for( j = i+1; j < ll_len(this); j++)
            {
                if(order == 1 && pFunc(ll_get(this,i), ll_get(this,j)) > 0)
                {
                    pElement1 = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,pElement1);
                }
                else if(order == 0 && pFunc(ll_get(this,i), ll_get(this,j)) < 0)
                {
                    pElement1 = ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,pElement1);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

int ll_increase_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size +=1;
        retVal = 0;
    }
    return retVal;
}

int ll_decrease_size(LinkedList* this)
{
    int retVal = -1;
    if (this!=NULL)
    {
        this->size--;
        retVal = 0;
    }
    return retVal;
}


int ll_setFirstNode(LinkedList* this, Node* pNode)
{
    int retorno = -1;

    if(this !=NULL && pNode != NULL)
    {
        this->pFirstNode = pNode;
        retorno = 0;
    }
    return retorno;
}


int ll_setNextNode(Node* this, Node* nextNode)
{
    int retorno = -1;

    if(this !=NULL)
    {
        this->pNextNode = nextNode;
        retorno = 0;
    }
    return retorno;
}


int ll_set_NodeElement(Node* this, void* pElement)
{
    int retorno = -1;
    if (this!=NULL)
    {
        this->pElement = pElement;
        retorno = 0;
    }
    return retorno;
}

int ll_set_Size(LinkedList* this, int size)
{
    int retorno = -1;

    if (this!=NULL)
    {
        this->size = size;
        retorno = 0;
    }
    return retorno;
}


Node* ll_get_firstNode(LinkedList* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pFirstNode;
    }
    return retornoNode;

}


Node* ll_get_LastNode(LinkedList* this)
{

    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        if (ll_isEmpty(this)==0)
        {
            Node* lastNode = ll_get_firstNode(this);
            while (lastNode!=NULL)
            {
                retornoNode = lastNode;
                lastNode = ll_get_NextNode(retornoNode);
            }
        }
    }
    return retornoNode;
}


Node* ll_get_NextNode(Node* this)
{
    Node* retornoNode = NULL;
    if (this!=NULL)
    {
        retornoNode = this->pNextNode;
    }
    return retornoNode;


}


Node* ll_get_NodeElement(Node* this)
{
    void* ret = NULL;
    if (this!=NULL)
    {
        ret = this->pElement;
    }
    return ret;


}

int ll_get_Size(LinkedList* this)
{
    int retorno = 0;
    if (this!=NULL)
    {
        retorno = this->size;
    }
    return retorno;
}

int ll_map(LinkedList* lista,int (*pFunc)(void*))
{
    if(lista!=NULL)
    {
        int len = ll_len(lista);
        int i;
        for(i=0; i < len; i++)
        {
            Employee* aux = (Employee*)ll_get(lista, i);

            pFunc(aux);
        }
    }
    return 1;
}

int laQueMapea(void* unEmpleado)
{
    int horasTrabajadas;
    employee_getHorasTrabajadas(unEmpleado,&horasTrabajadas);

    if(horasTrabajadas>0 && horasTrabajadas <=200)
    {
        employee_setDedicacion(unEmpleado,"estandar");
    }
    else if(horasTrabajadas<=300)
    {
        employee_setDedicacion(unEmpleado,"sobre la media");
    }
    else
    {
        employee_setDedicacion(unEmpleado,"excesivo");
    }

    return 1;

}
