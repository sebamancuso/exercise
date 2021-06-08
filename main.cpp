using namespace std;
#include "node.h"
#include <iostream>
#include "list.h"

int main()
{
/*
    Node<int> n1(1);
    Node<int> n2(2);
    Node<int> n3(3);
    Node<int> n4(4);
    Node<int> n5(5);

    list<int> list;

    list.insertTail(&n1);
    list.insertTail(&n2);
    list.insertTail(&n3);
    list.insertTail(&n4);
    list.insertTail(&n5);

    //cout<<list.search(1)<<" -> value = 1"<<endl;
    //cout<<list.search(2)<<" -> value = 2"<<endl;
    //cout<<list.search(3)<<" -> value = 3"<<endl;
    //cout<<list.search(4)<<" -> value = 4"<<endl;
    //cout<<list.search(5)<<" -> value = 5"<<endl;

    cout<<endl;

    cout<<"lista completa: ";
    list.printList();
    cout<<endl<<"--------------------------------------"<<endl<<endl;

    cout<< "remove di: "<<list.remove(3)<<endl<<endl;

    cout<<"lista dopo il remove: ";
    list.printList();
*/

    
    list<int> list;

    while (true)
    {
        int i;

        cout<<"inserici un valore: ";
        cin >> i;
        cout<<endl;

        if (i == 0)
        {
            break;
        }

        list.insertTail(new Node<int>(i));

        cout<<list.search(i)<<" -> value = "<< i <<endl;
        cout<<endl;

        list.printList();
        cout<<endl;
    }

    cout<<"----------------------------------------"<<endl;
    cout<<endl;
    cout<<"lista completa finale: ";
    list.printList();
    cout<<endl;

    if (list.isEmpty())
    {
        return 0;
    }

    while(true)
    {
        if (list.isEmpty())
        {
            cout<<endl;
            return 0;
        }
        
        int i;
        cout<<"inserici un valore da rimuovere: ";
        cin >> i;

        if(i == 0)
        {
            break;
        }

        cout<<"l'indirizzo e il valore del nodo da rimuovere sono: "<< list.search(i)<<" -> value = "<< i <<endl;
        list.remove(i);
        cout<<endl;

        cout<<"lista dopo il remove: ";
        list.printList();
    }
    return 0;
}
