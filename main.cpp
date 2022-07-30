#include <iostream>
#include <time.h>

using namespace std;

struct Card{
                 int key;       //1, 2, ... or 52
                 int suit;      //cupa, romb, trefla or pica
                 int rank;      //1, 2, ... or 13
                 Card *next=nullptr;
                 };

class CardDeck{
      private:
             struct Card *head;
             struct Card *temp;
             int numberOfCards;
//se adauga in lista nula cu 52 de noduri, variantele de carti in ordine aleatorie;
             void shuffleDeck(){
                 //cream variantele posibile in vectori;
                  int suit [52];
                  int rank [52];
                int j=1;
                int s=1;

                  for(int i=52;i>0;i--)
                  {
                      if(j>13)
                      {
                          j=1;
                          s++;
                      }
                      rank[i]=j;
                      suit[i]=s;
                      j++;
                  }

                  //verificare vectori
               // for(int i=1;i<=52;i++)
                  //{
                      //cout<<i<<"."<<suit[i]<<" "<<rank[i]<<endl<<endl;
                 // }
                //se amesteca valorile in vectori incat sa nu se repete
                srand(time(0));
                 for(int i=1;i<=52;i++)
                 {
                     //setam time 0 pentru a genera alte valori de fiecare data;

                     int x=rand() % 52+1;
                     swap(rank[i],rank[x]);
                     swap(suit[i],suit[x]);

                 }
                 //se atribuie valorile amestecate listei;
                 struct Card *el=head;
                 for(int i=1;i<=52;++i)
                 {
                  el->key=i;
                  el->rank=rank[i];
                  el->suit=suit[i];
                  el=el->next;


                 }
                  }

      public:
          //se creaza o lista cu 52 de noduri goale
             CardDeck(){
                    numberOfCards = 52;

                    //prima carte nula din lista;
                    Card *el=new Card;
                        el->key= 0;
                        el->rank= 0;
                        el->suit= 0;
                        head=el;
                        temp=el;

                    //restul de 50 de carti nule din lista;
                    for(int i=0;i<51;i++)
                    {

                         Card *el=new Card;
                         el->key=0;
                         el->rank=0;
                         el->suit=0;
                         temp->next=el;
                         temp=temp->next;
                    }
                    //ultima carte din lista 52;
                    Card *e=new Card;
                    e->key=0;
                    e->rank=0;
                    e->suit=0;
                    temp->next=e;
                    e->next=NULL;
                    temp=temp->next;


                    shuffleDeck();

                       /* while(head->next!=NULL)
                    {
                        cout<<head->key<<"."<<head->rank<<" ";
                        if(head->suit==1)
                        {
                            cout<<"cupa"<<endl;
                        }else if(head->suit==2)
                        {
                            cout<<"romb"<<endl;
                        }else if(head->suit==3)
                        {
                            cout<<"trefla"<<endl;
                        }else if(head->suit==4)
                        {
                            cout<<"pica"<<endl;
                        }

                        head=head->next;
                    } */




             }
             //stergerea listei
             ~CardDeck(){
                       delete head;
                     }
//se scoate o carte din pachet eliminand legatura dintre nodul prim si mutandu l la urmatorul nod
             Card *popCard(Card *&el){
                    el=el->next;
                    return el;
                  }
// se verifica daca se mai pot extrage doua carti
             bool isEmpty(Card *el){
                    if(el->next->next!=NULL)
                    {
                        return 0;
                    }else
                    {
                        return 1;
                    }


                  }

                  Card * gethead()
                  {
                      return head;
                  }

                  void afiseaza(Card *el)
                  {

                      if(el->rank==1)
                      {
                          cout<<"A ";
                      }else if(el->rank==11)
                      {
                          cout<<"J ";
                      }
                      else if(el->rank==12)
                      {
                          cout<<"Q ";
                      }
                      else if(el->rank==13)
                      {
                          cout<<"K ";
                      }else
                      {
                          cout<<el->rank<<" ";
                      }

                      if(el->suit==1)
                      {
                          cout<<"of Hearts";
                      }else if(el->suit==2)
                      {
                          cout<<"of Diamonds";
                      }else if(el->suit==3)
                      {
                          cout<<"of Club";
                      }else if(el->suit==4)
                      {
                          cout<<"of Spades";
                      }


                  }

};


void jocnou()
{
        string player1;
        string player2;
        int p1=0;
        int p2=0;
        int runda=1;
        cout<<".%%...%%...%%%%...%%%%%............%%%%....%%%%...%%...%%..%%%%%%."<<endl;
        cout<<".%%...%%..%%..%%..%%..%%..........%%......%%..%%..%%%.%%%..%%....."<<endl;
        cout<<".%%.%.%%..%%%%%%..%%%%%...........%%.%%%..%%%%%%..%%.%.%%..%%%%..."<<endl;
        cout<<".%%%%%%%..%%..%%..%%..%%..........%%..%%..%%..%%..%%...%%..%%....."<<endl;
        cout<<"..%%.%%...%%..%%..%%..%%...........%%%%...%%..%%..%%...%%..%%%%%%."<<endl;
        cout<<".................................................................."<<endl;

        cout<<"Press ENTER to start the game..";
        cin.get();
        system("CLS");
        cout<<"Player 1 name:"<<endl;
        cin>>player1;
        cout<<"Player 2 name:"<<endl;
        cin>>player2;
        cout<<"Press ENTER to continue..."<<endl;
        cin.get();
        system("CLS");
        //obiect creat
        CardDeck joc;
        //cream pachetul de carti
        CardDeck();
        //restabilim primul element din pachetul de carti
        Card * prim=joc.gethead();
        Card * pc1=prim;
        Card * pc2=joc.popCard(prim);
        //runda 1
        cout<<"Round"<<runda<<endl;
        cout<<"===================="<<endl;

        joc.afiseaza(pc1);
        cout<<" Vs ";
        joc.afiseaza(pc2);
        cout<<endl<<endl;
        if(pc1->rank>pc2->rank)
        {
            p1++;
            cout<<"*"<<player1<<" win this round "<<runda<<"*"<<endl;
            cout<<endl<<pc1->rank<<" > "<<pc2->rank;
        }else if(pc1->rank<pc2->rank)
        {
            p2++;
            cout<<"*"<<player2<<" win this round "<<runda<<"*"<<endl;
            cout<<endl<<pc2->rank<<" > "<<pc1->rank;
        }else
        {
            cout<<pc1->rank<<" = "<<pc2->rank<<endl;
            cout<<"DRAW";
        }
        runda++;
        cout<<endl<<"**************************"<<endl;
        cout<<player1<<" Vs "<<player2<<endl;
        cout<<"____________________"<<endl;
        cout<<endl<<"*SCORE*"<<endl;
        cout<<p1<<" : "<<p2<<endl;
        cout<<endl<<"Press ENTER to next round..."<<endl;
        cin.get();
        //runda 2
        while(joc.isEmpty(prim)!=1)
        {
            system("CLS");
            pc1=joc.popCard(prim);
            pc2=joc.popCard(prim);
            cout<<"Round"<<runda<<endl;
        cout<<"===================="<<endl;

        joc.afiseaza(pc1);
        cout<<" Vs ";
        joc.afiseaza(pc2);
        cout<<endl;
        cout<<endl;
        if(pc1->rank>pc2->rank)
        {
            p1++;
            cout<<"*"<<player1<<" win this round "<<runda<<"*"<<endl<<endl;
            cout<<pc1->rank<<" > "<<pc2->rank;
        }else if(pc1->rank<pc2->rank)
        {
            p2++;
            cout<<"*"<<player2<<" win this round "<<runda<<"*"<<endl<<endl;
            cout<<pc2->rank<<" > "<<pc1->rank;
        }else
        {
            cout<<pc1->rank<<" = "<<pc2->rank<<endl<<endl;
            cout<<"DRAW";
        }
        runda++;
        cout<<endl<<"**************************"<<endl;
        cout<<player1<<" Vs "<<player2<<endl;
        cout<<"____________________"<<endl;
        cout<<endl<<"*SCORE*"<<endl;
        cout<<p1<<" : "<<p2<<endl;
        cout<<endl<<"Press ENTER to next round..."<<endl;
        cin.get();

       }
         system("CLS");



       if(p1>p2)
       {
            cout<<" #     # ### #     # #     # ####### ######  "<<endl;
            cout<<" #  #  #  #  ##    # ##    # #       #     # "<<endl;
            cout<<" #  #  #  #  # #   # # #   # #       #     # "<<endl;
            cout<<" #  #  #  #  #  #  # #  #  # #####   ######  "<<endl;
            cout<<" #  #  #  #  #   # # #   # # #       #   #   "<<endl;
            cout<<" #  #  #  #  #    ## #    ## #       #    #  "<<endl;
            cout<<"  ## ##  ### #     # #     # ####### #     # "<<endl<<endl;
               cout<<"!!!"<<player1<<" WON!!!"<<endl;
               cout<<"*******"<<endl;
               cout<<"*SCORE*"<<endl;
               cout<<"*******"<<endl;
               cout<<p1<<" : "<<p2<<endl;

       }else if(p2>p1)
       {
            cout<<" #     # ### #     # #     # ####### ######  "<<endl;
            cout<<" #  #  #  #  ##    # ##    # #       #     # "<<endl;
            cout<<" #  #  #  #  # #   # # #   # #       #     # "<<endl;
            cout<<" #  #  #  #  #  #  # #  #  # #####   ######  "<<endl;
            cout<<" #  #  #  #  #   # # #   # # #       #   #   "<<endl;
            cout<<" #  #  #  #  #    ## #    ## #       #    #  "<<endl;
            cout<<"  ## ##  ### #     # #     # ####### #     # "<<endl<<endl;
               cout<<"!!!"<<player2<<" WON!!!"<<endl;
           cout<<"*******"<<endl;
           cout<<"*SCORE*"<<endl;
           cout<<"*******"<<endl;
           cout<<p2<<" : "<<p1<<endl;
       }else
       {
           cout<<" ######  ######     #    #     #    "<<endl;
            cout<<"#     # #     #   # #   #  #  #    "<<endl;
            cout<<"#     # #     #  #   #  #  #  #    "<<endl;
            cout<<"#     # ######  #     # #  #  #    "<<endl;
            cout<<"#     # #   #   ####### #  #  #    "<<endl;
            cout<<"#     # #    #  #     # #  #  #    "<<endl;
            cout<<"######  #     # #     #  ## ##     "<<endl;
            cout<<"*******"<<endl;
           cout<<"*SCORE*"<<endl;
           cout<<"*******"<<endl;
           cout<<p2<<" : "<<p1<<endl;

       }
       int v;
       cout<<"Press 1 for a new game!"<<endl;
       cout<<"Press 2 for exit game!"<<endl;
       cin>>v;
       if(v==1)
       {
           jocnou();
       }


}

int main(){

    jocnou();

    return 0;
}
