#include <iostream>
#include <string.h>

using namespace std;


struct Article {
public:    
    int id;
    int stock;
    float prix;
    string description;
    Article* suivant;
};


struct Item {
public:
    int quantite;
    Article* article;
    Item* suivant;
};

struct Commande {
public:
    int id;
    Item* item;
    Commande* suivant;
};


/**
 * Créer un nouvel article et l'ajouter a la liste des articles.
*/
void AjouterArticle(Article &art, string description, int stock, float prix){
    
    Article *newArt = new Article;
    
    static int id_cpt = 1;
    
    newArt->description = description;
    newArt->stock = stock;
    newArt->prix = prix;
    

    if( art.suivant == NULL ){
        newArt->id = id_cpt;
        art = *newArt;
    }else{
        newArt->id = art.suivant->id+1;
        newArt->suivant = &art;
    }

   //cout <<"\t\t id: " <<art->id <<" description: "<< art->description <<" stock: "<< art->stock <<" prix: "<<art->prix<<"\t"<<endl;


    cout <<"\t\t id: " <<art.id <<" description: "<< art.description <<" stock: "<< art.stock <<" prix: "<<art.prix<<"\t"<<endl;



};

/**
 * Afficher les articles présent dans la liste des articles.
*/
void afficherArticle(Article L){
    
    Article *tmp = NULL;
    tmp = &L;

    while(tmp->suivant != NULL){
        cout <<"\t\t id: " <<tmp->id <<" description: "<< tmp->description <<" stock: "<< tmp->stock <<" prix: "<<tmp->prix<<"\t"<<endl;
        tmp = tmp->suivant; 
    }
}

/**
 * Changer la quantité du stock d'un article identifier par son ID.
*/
int EnterStock(int numArt, int qte, Article art){
        
    Article *curr = &art;
        
    while(curr != NULL){
        if(curr->id == numArt){
            curr->stock = qte;
            art = *curr;
            return 1;
        }
        curr = curr->suivant;
    }
    return 0; 
}

/**
 * Insert une nouvelle commande en queue de liste.
*/
void InsertCommande(Commande &cde, Article art, int numArticle, int Qte){
    
    Item *newItem = new Item();
    Commande currCde = cde;
    
    newItem->quantite = Qte;
    newItem->article = &art;
    newItem->suivant = NULL;
    
    while( currCde.suivant != NULL ){
        //Itérer dans la liste des commande pour atteindre la dernière commande.
    }
    
    // 
    if (currCde.item->suivant == NULL){
        currCde.id = numArticle;
        currCde.item = newItem;
        currCde.suivant = NULL;
    }else{
        currCde.id = numArticle;
        currCde.item->suivant = newItem;
        currCde.suivant = NULL;
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

/*
checkstock(int numcde, Commande cde){
    
}

FactureCommande(int numcde, Commande cde){
    
}
*/

int main()
{
    
   

    Article * art = NULL;
    Commande * cde = NULL;
    art = new Article;
    cde = new Commande; 
    

    AjouterArticle(*art,"Pomme",56,50);
    AjouterArticle(*art,"Poire",15,40);
    AjouterArticle(*art,"Cerise",42,30);
    AjouterArticle(*art,"Fraise",23,20);
    AjouterArticle(*art,"Raisin",12,10);
    AjouterArticle(*art,"Banane",10,5);
    cout<<endl<<"(----Affichage Article----)"<<endl<<endl;
    afficherArticle(*art);
    
    //EnterStock(2,30,*art);
    cout<<endl<<"(----Affichage stock modifie----)"<<endl<<endl;
    //afficherArticle(*art);
    
    //InsertCommande(*cde,*art,6,30);
    
    //PrintCdesArt();
    cout<<endl<<"(----Affichage Commande----)"<<endl<<endl;
    //afficherArticle(*art);
    

    //cout<<endl<<"//////////////Afficher enter stock /////////////"<<endl<<endl;


    
    return 0;
}
