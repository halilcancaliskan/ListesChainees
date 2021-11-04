#include <iostream>
#include <string.h>
#include <String>
using namespace std;

struct Article {
    int id;
    int stock;
    float prix;
    string description;
    Article* suivant;
};
//typedef Article* listeArticle;

struct Item {
    int quantite;
    Article* article;
    Item* suivant;
};
//typedef Item* listeItem;

struct Commande {
    int id;
    Item* item;
    Commande* suivant;
};
//typedef Commande* listeCommande;

void AjouterArticle(Article &L, string description, int stock, float prix){
	Article *s= new Article;
	s->description=description;	
	static int cpt=1;
	s->stock =stock;
	s->prix =prix;
	if(cpt==1)
	{
		s->suivant=NULL;
	}
	else
	{
		s->suivant= &L;
	}
	s->id=cpt;
	cpt++;
};

void afficherArticle(Article Li){
	Article *tmp = &Li;
	while(tmp->suivant != NULL){
		cout <<"\t\t id: " <<tmp->id <<" description: "<< tmp->description <<" stock: "<< tmp->stock <<" prix: "<<tmp->prix<<"\t"<<endl;
		tmp->suivant = tmp;
	}
}

int EnterStock(int numArt, int qte, Article art){
		Article *curr = &art;
		
		while(curr != NULL)
		{
			if(curr->id == numArt)
			{
				curr->stock = qte;
				art = *curr;
				
				return 1;
			}
			curr = curr->suivant;
		}
		return 0;
		
		
}

void InsertCommande(Commande &cde, Article art, int numArticle, int Qte){
	Item *newItem = new Item;
	newItem->quantite = Qte;
	newItem->article = &art;
	newItem->suivant = NULL;
	if (cde.suivant == NULL){
		cde.id = numArticle;
		cde.item = newItem;
		cde.suivant = NULL;
	}
	
		
}

void PrintCdesArt(Article art, Commande cde){
	Commande tmp = cde;
	int sumQte = 0;
	while(tmp.suivant != NULL){
		if(art.id == tmp.id){
			sumQte += tmp.item->quantite;
		}
		tmp.suivant = tmp.suivant;
	}
	cout<<sumQte<<endl;
}

checkstock(int numcde, Commande cde){
	
}

FactureCommande(int numcde, Commande cde){
	
}




int main()
{	
	Article L;
	Commande Lc;
	

	AjouterArticle(L,"Pomme",56,50);
	AjouterArticle(L,"Poire",15,40);
	AjouterArticle(L,"Cerise",42,30);
	AjouterArticle(L,"Fraise",23,20);
	AjouterArticle(L,"Raisin",12,10);
	AjouterArticle(L,"Banane",10,5);
	cout<<endl<<"(----Affichage Article----)"<<endl<<endl;
	afficherArticle(L);
	
	EnterStock(2,30,L);
	cout<<endl<<"(----Affichage stock modifie----)"<<endl<<endl;
	afficherArticle(L);	
	
	InsertCommande(Lc,L,6,30);
	
	//PrintCdesArt();
	cout<<endl<<"(----Affichage Commande----)"<<endl<<endl;
	afficherArticle(L);
	

	//cout<<endl<<"//////////////Afficher enter stock /////////////"<<endl<<endl;


	
    return 0;
}
