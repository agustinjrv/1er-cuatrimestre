/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);
int ll_len(LinkedList* this);
Node* test_getNode(LinkedList* this, int nodeIndex);///si exite ese indice de nodo
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);///para testear si se puede agragar un elemento a la lista
int ll_add(LinkedList* this, void* pElement);///agrega un elemento a la linkedlist
void* ll_get(LinkedList* this, int index); ///devuleve un elemento
int ll_set(LinkedList* this, int index,void* pElement);///modifica un elemento
int ll_remove(LinkedList* this,int index);
int ll_clear(LinkedList* this);///pone todo en 0
int ll_deleteLinkedList(LinkedList* this);
int ll_indexOf(LinkedList* this, void* pElement);///
int ll_isEmpty(LinkedList* this);///me dice si esta vacio o no la lista
int ll_push(LinkedList* this, int index, void* pElement);
void* ll_pop(LinkedList* this,int index);
int ll_contains(LinkedList* this, void* pElement);///confirmar si un elemento esta dentro o no,se fija si estan en la misma direccion de memoria
int ll_containsAll(LinkedList* this,LinkedList* this2);///devuelve 1 si estan todos los elemento 0 sin falta alguno
LinkedList* ll_subList(LinkedList* this,int from,int to);///form inclusivo,to exlusivo.copia parte de la lista
LinkedList* ll_clone(LinkedList* this);///crea una nueva lista con los mismos datos pero en disitinta direccion de memoria
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//0 o 1
