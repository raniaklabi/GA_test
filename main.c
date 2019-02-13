#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include<time.h>
#include <unistd.h>
#define NT 200 //nbre maximal de targets
#define NC 300 //nbre maximal de capteurs
#define SR 100 // maximum senssing range
#define B 50 /*budget fixe*/
#define GMAX 1000 /*nombre maximal de génération*/
typedef struct Capteur
{
    int id; // Identifiant du capteur
    double rayon;//Le rayon du capteur
    double duree;//La duree du capteur
    double distance[NT];//c'est un tableau qui contient les differentes distances qu sépare un capteur donnee
    double prix;//Le prix du capteur
    char typeSurveillance;//type de surveillance du capteur

} Capteur;

typedef struct
{
	int lignes[NC];
	double dureeSol;
	double prixSol;
	int tailleSol;
} Solution;
void jeuxInstance(int N,int M,int Emax,int Emin,int prix,float P[],int area,int range,float E[] ,float RS[],float XS[],float YS[],float XT[],float YT[],double Distance[NC][NT],char *S)
{FILE* fichier = NULL;
fichier = fopen(S, "w");
char c;
char line[10000];
int delta[NC][NT];
int K1=N/4;//K-Coverage:par exemple: chaque cible est au moins couvert par 1 capteurs
int K2=0;// chaque capteurs couvre au moins k2 cibles
int s=0;
int ok1=0,ok2=0;
if (fichier != NULL)
{//srand(time(NULL));
    printf("*********************************entref1\n*************************");
    /* printf ("Rentrez la zone a couvrir area = ");
     scanf ("%d", &area);
     printf ("Rentrer le nombre de capteurs N =");
     scanf ("%d", &N);*/
     fputs("Nombre des capteurs:\n", fichier);
     sprintf (line, "%d", N);
     printf("*********************************entref2\n*************************");
     //printf("line %s", line);
     // c=(char)N+'0';
     fputs(line,fichier);
     fputs("\n",fichier);
     // printf("%c\n",c);
    /* printf ("Energie maximale d'un capteur =");
     scanf ("%d", &Emax);
     printf ("le prix maximal maximale d'un capteur =");
     scanf ("%f", &prix);
     printf ("Rentrer le nombre de targets M =");
     scanf ("%d", &M);*/
     //c=(char)M+ '0';
    fputs("Nombre des targets:\n", fichier);
    sprintf (line, "%d", M);
    printf("*********************************entref3\n*************************");
    fputs(line,fichier);
    fputs("\n",fichier);
    fputs("Nombre de type de surveillance:\n",fichier);
    fputs("1\n",fichier);
    fputs("\n",fichier);
    fputs("Caracteristiques:\n",fichier);
   // printf ("area");
    // scanf ("%d", &range);*
     printf("\n");
     //printf("*****************n %d********************",area);
       for(int i=0; i < N;i++)
   {
       XS[i]=HAS_Float(area);
       YS[i]=HAS_Float(area);
   }

   printf( "XS= ");
      for(int i=0; i < N;i++)
    {
       printf( "%f |  ",XS[i]);
    }
    printf("\n");
    printf( "YS= ");
      for(int i=0; i < N;i++)
    {
       printf( "%f |  ",YS[i]);
    }
     for(int i=0; i < N;i++)
   {
       RS[i]=HAS_Float(range)+100;
   }
   printf("\n");
   printf( "RS= ");
     for(int i=0; i < N;i++)
    {
       printf( "%f |  ",RS[i]);
    }
    printf("\n");

     printf( "E= ");
     for(int i=0; i < N;i++)
   {
       E[i]=HAS_Float(Emax-Emin)+Emin;

   }
    for(int i=0; i < N;i++)
    {
       printf( "%f |  ",E[i]);
    }
    printf("\n");
        printf("\n");
     printf( "P= ");
     for(int i=0; i < N;i++)
   {
       P[i]=HAS_Float(prix)+1;
   }
    for(int i=0; i < N;i++)
    {
       printf( "%f |  ",P[i]);
    }
    printf("\n");
while (ok2==0)
{
for(int h=0; h < M;h++)
   {ok1=0;
       while(ok1==0)
       {

       XT[h]=HAS_Float(area);
       YT[h]=HAS_Float(area);
printf("********N=%d********",N);
    for(int i=0;i<N;i++)
    {
//printf("1********%d********XT=%f*****YT=%f*******",i,XT[0],YT[0]);
 Distance[i][h]=sqrt(((XS[i]-XT[h])*(XS[i]-XT[h]))+((YS[i]-YT[h])*(YS[i]-YT[h])));
// printf("2********%d********XT=%f*****YT=%f*******",i,XT[0],YT[0]);
      //  printf( "%lf |  ",Distance[i][j]);

       // printf("\n");
      // getchar();
      // getchar();
    }
    /**********************************/
     for(int i=0;i<N;i++)
    {

            if(Distance[i][h]<=RS[i])
            {
                delta[i][h]=1;
            }
            else
            {
                delta[i][h]=0;
            }

        }

    printf("\n");
      s=0;
        for(int i=0;i<N;i++)
        {
            if (delta[i][h]==1) {s=s+1;}
        }

        if(s>=K1) {ok1=1;}
    }
   }
    for(int i=0;i<N;i++)
    {   s=0;
        for(int j=0;j<M;j++)
        {
            if (delta[i][j]==1) {s=s+1;

                                 }
        }

        if(s>=K2)  {ok2=1;}
        else {
                i=N;
        ok2=0;}
    }
}

    /****************************************/

     printf("\n");
  for(int i=0;i<N;i++)
     {
         for(int j=0;j<M;j++)
    {
        printf("%d",delta[i][j]);
    }
    printf("\n");
     }
      printf( "XT=");
   for(int i=0; i < M;i++)
    {
       printf( "%f |  ",XT[i]);
    }
    printf("\n");
    printf( "YT=  ");
      for(int i=0; i < M;i++)
    {
       printf( "%f |  ",YT[i]);
    }
    printf("\n");
    printf("\n");
    printf("Distance= \n");
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
        printf( "%lf |  ",Distance[i][j]);
        }
        printf("\n");
    }

  for(int i=0;i<N;i++)
    {
        sprintf(line,"%f", RS[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        sprintf (line,"%f", E[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        sprintf (line,"%f", P[i]);
        fputs(line,fichier);
        fputs(" ",fichier);
        fputs("a ",fichier);
        for(int j=0;j<M;j++)
        {
           sprintf (line,"%lf", Distance[i][j]);
           fputs(line,fichier);
           fputs(" ",fichier);
        }
        fputs("\n",fichier);
    }
    fputs("Type de surveillance de chaque endroit(target):tab[nombre de target]\n",fichier);
    for (int i=0;i<M;i++)
    {
        fputs("a ",fichier);
    }

}
fclose(fichier);
}

void lire_Data(Capteur Cap[],int *N,int *M,char *S ,char *survTarget,int *nbreDeTypeDeSur)
{
    // Role:
    //cette fonction permet de lire toutes  les donnees necessaires pour la simulation a partir d'un fichier S

   int i,j,k,L,C;
   FILE *file = NULL; // fichier pour lire les données


   file =fopen ( S, "r" );
   if ( file != NULL )
   {//printf("entrer");
      char line [ 100028 ]; /* or other suitable maximum line size */
      char S[100000];
      fgets ( line, sizeof line, file );  /* read a line */
      fgets ( line, sizeof line, file );
      *N = atoi(line);
     // printf("***************N=%d\n",*N);
       fgets ( line, sizeof line, file );
       fgets ( line, sizeof line, file );
       *M = atoi(line);
      // printf("***************M=%d\n",*M);
        fgets ( line, sizeof line, file );
       fgets ( line, sizeof line, file );
       *nbreDeTypeDeSur = atoi(line);
       //printf("***************=%d\n",*nbreDeTypeDeSur);
     //  printf("N  %d\n",*N);
       //  printf("N  %d\n",*M);
      fgets ( line, sizeof line, file );
      fgets ( line, sizeof line, file );
        // Remplir les capteurs

      for( L = 0; L < *N; L++)
      {

         k=0;
         C=0;
         i=0;
         fgets ( line, sizeof line, file );
         for( j = 0; line[j]!='\n'; j++)
         {
             if( line[j]!= ' ')
             {
                 S[k] = line[j];
                 k++;
             }
             else
             {

                S[k]='\0';
                k=0;
                C++;
                if(C==1)
                {
                    Cap[L].rayon = atof(S);
                     // printf("rayon %d  %lf ",L, Cap[L].rayon);
                }
                else if(C==2)
                {
                    Cap[L].duree = atof(S);
                    //printf("duree  %lf ", Cap[L].duree);
                }
                else if(C==3)
                {
                    Cap[L].prix = atof(S);
                     //printf("prix  %lf ", Cap[L].prix);
                }
                else if(C==4)
                {
                    Cap[L].typeSurveillance = S[0];
                }
                else{
                    Cap[L].distance[i] = atof(S);
                     //printf("D%d  %lf ",i, Cap[L].distance[i]);
                    i++;
                }

             }

         }

         S[k] = '\0';

         //Cap[L].distance[i]= atoi(S);
         //printf("D%d  %lf ",i, Cap[L].distance[i]);
         Cap[L].id=L;
      }
printf("\n");
            k=0;

         i=0;
        fgets ( line, sizeof line, file );
        fgets ( line, sizeof line, file );
         for( j = 0; line[j]!='\n'; j++)
         {
             if( line[j]!= ' ')
             {
                 S[k] = line[j];
                 k++;
             }
             else
             {

                S[k]='\0';
                k=0;
                    survTarget[i]= S[0];
                    i++;
             }

         }
      S[k] = '\0';
      survTarget[i]= S[0];
      fclose ( file );
   }
   else
   {
       printf("Error !!! \n");
      perror ( S ); /* why didn't the file open? */
   }

}
void Affiche(Capteur C[],int N,int M)
{
    // Role:
    //Afficher les caracteristiques des capteurs

    int i,j;

    for(i=0; i < N;i++)
    {
        printf("*** Capteur %d *** : \n",i);
         printf("\n");
        printf("Rayon %lf\n", C[i].rayon);
        printf("Duree  %lf\n", C[i].duree);
        printf("Prix  %lf\n", C[i].prix);
        for(j=0; j<M;j++)
        {
            printf("Distance %d : %lf\n",j+1, C[i].distance[j]);
        }
        printf("\n");
    }
}
void duree_capteur_combinaison( Capteur C[],double tab_duree[NC],int nbre_ligne_sommer,int ligne[NC])
{
    //Role :
    //chaque combinaison est composée par un ensemble des capeurs  et qui permet avec eux de couvrir toutes les cibles
    //Retourne un tableau "tab_duree" qui contient les  differentes durées de vie d'une combinaison particuliere
    //chaque case du tableau "tab_duree" contient la durée de vie d'un capteur qui fait partie d'une combinaison particuliere
int i;
//printf("D:\n");
for(i=0;i<nbre_ligne_sommer;i++)
{
    tab_duree[i]=C[ligne[i]].duree;
    //printf("%lf ",tab_duree[i]);
}
//printf("\n");
}
void prix_capteur_combinaison( Capteur C[],double tab_prix[NC],int nbre_ligne_sommer,int ligne[NC])
{
     //Role :
    //chaque combinaison est composée par un ensemble des capeurs  et qui permet avec eux de couvrir toutes les cibles
    //Retourne un tableau "tab_prix" qui contient les  differents prix d'une combinaison particuliere
    //chaque case du tableau "tab_prix" contient le prix d'un capteur qui fait partie d'une combinaison particuliere
int i;
//printf("P:\n");
for(i=0;i<nbre_ligne_sommer;i++)
{
    tab_prix[i]=C[ligne[i]].prix;
    //printf("%lf ",tab_prix[i]);
}
//printf("\n");
}
void ID_capteur_combinaison( Capteur C[],int tab_ID[NC],int nbre_ligne_sommer,int ligne[NC])
{
     //Role :
    //chaque combinaison est composée par un ensemble des capeurs  et qui permet avec eux de couvrir toutes les cibles
    //Retourne un tableau "tab_prix" qui contient les  differents prix d'une combinaison particuliere
    //chaque case du tableau "tab_prix" contient le prix d'un capteur qui fait partie d'une combinaison particuliere
int i;
printf("ID:\n");
for(i=0;i<nbre_ligne_sommer;i++)
{
    tab_ID[i]=C[ligne[i]].id;
    printf("%d ",tab_ID[i]+1);
}
printf("\n");
}


void Calculer_delta(Capteur C[],int delta[NC][NT], char typeTarget[NT],int N,int M)
{
    //Role:
    //A partir de les diffrentes distances d'un capteur particulier on peut construire une ligne de delta.
    //Retourne la matrice "delta" .
    //Les lignes de la matrice presente les capteurs.
    //les colonnes de la matrice presente les targets.
    //losqu'on met par exemple 1 dans la case(1,1)  c'est_a_dire le capteur un couvre la target 1 .

    int i,j;

    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            if((  C[i].distance[j]<=C[i].rayon)&&(C[i].typeSurveillance==typeTarget[j]))
            {
                delta[i][j]=1;
            }
            else
            {
                delta[i][j]=0;
            }

        }

    }

}

int HAS_INT(int max)
/*
Rôle : choisit aléatoirement un entier entre 0 et max-1
Paramètres :
	max : définit la borne sup à ne pas dépasser
Résultat : le nombre choisi aléatoirement
*/
{
	int a;
	a=((int) (rand()%1000)*max/1000);
	return(a);
}
void initialiserPopulation(Solution pop[],Solution sol,int nbreSol,int nbre_ligne_sommer)
{
    int i,k,d,j;
    int solCopie[nbre_ligne_sommer];
   // printf("solution 0: ");
    for(i=0;i<nbre_ligne_sommer;i++)
    {
        pop[0].lignes[i]=sol.lignes[i];
       // printf("%d ",pop[0].lignes[i]);

    }

    pop[0].dureeSol=sol.dureeSol;
    pop[0].dureeSol=sol.prixSol;
    pop[0].tailleSol=sol.tailleSol;

    i=1;
printf("\n");
    while(i<nbreSol)
    {// printf("solution %d: ",i);
        j=0;

    for(k=0;k<nbre_ligne_sommer;k++)
        solCopie[k]=sol.lignes[k];

        while(j<nbre_ligne_sommer)
        {
             d=HAS_INT(nbre_ligne_sommer);
           // printf("d=%d ",d);
             if(solCopie[d]!=-1)
             {
                 pop[i].lignes[j]=solCopie[d];
               // printf("%d  ",pop[i].lignes[j]);
                 j++;
                 solCopie[d]=-1;
             }
        }

        pop[i].dureeSol=0;
        pop[i].prixSol=0;
        pop[i].tailleSol=nbre_ligne_sommer;
        i++;
        //printf("\n");
        //getchar();
        //getchar();
    }


}
void Evaluation(double D[NC],double P[NC],int ID[NC],int delta[NC][NT],int N,int M,double *prix_total,double *duree_vie,int *nbreCoverSet)
{
    double P1[NC];
    double D1[NC];
    int ID1[NC];
    int ST[NT];
    int coveredTarget=0;
    *nbreCoverSet=0;
    double mini;
    int a,s,i,j,h=0,l;//nbre de cible qu'on peut couvrir dans chaque ligne
    int R[NC];//tableau qui contient les numero de lignes
    *duree_vie=0;
    *prix_total=0;
    *nbreCoverSet=0;
    mini= 100000000;
    printf("The Different Free Disjoint Set Covers :\n");
printf("\n");
    //printf("\n");
      for(a=0;a<N;a++)
                {
                    P1[a]=P[a];
                    D1[a]=D[a];
                    ID1[a]=ID[a];
                }
            l=0;
          for(i=0;i<N;i++)
          {
              if(D1[i]!=0)
                 {
                    R[l]=i;
                    l++;
                   for(j=0;j<M;j++)
                    {
                        if(delta[i][j]==1)
                        {
                            if (existe_tab(ST,j,h)==0)
                            {ST[h]=j;
                            h++;
                                 coveredTarget=coveredTarget+1;
                            }

                        }

                    }//printf(" capteur %d couvre\n",h);
                    if (coveredTarget==M) {

                            *nbreCoverSet=*nbreCoverSet+1;

                            coveredTarget=0;
                            h=0;
                            printf("cover set C%d=",*nbreCoverSet);
                for(s=0;s<l;s++)
                {
                        if(D1[R[s]]<mini)
                        {
                            mini= D1[R[s]];
                        }
                 printf("s%d ",ID1[R[s]]+1);

                }
 printf(":%lf \n",mini);
                for(s=0;s<l;s++)
                {
                       *prix_total=*prix_total+P1[R[s]];

                        P1[R[s]]=0;
                }
                  //mise a jour de la durée de vie de chaque capteur
                for(s=0;s<l;s++)
                {
                    if(D1[R[s]]!=0)
                    {
                        D1[R[s]]=0;
                       // D1[R[s]]=D1[R[s]]-mini;
                       // printf("duree restante du capteur%d :%lf\n",R[s],D[R[s]]);
                    }
                }
                *duree_vie= *duree_vie+mini;
                l=0;
                    }
                 }
            }
            printf(" The HWSN Lifetime of this cover set is :%lf\n",*duree_vie);
}
    int existe_tab(int T[NT+1],int element,int N)
{
    /* Role : Tester si le nombre n existe dqns le tqbleaux T */
    int i;
    for(i=0;i<N;i++)
        if(T[i]==element)
        return 1;
    return 0;

}


void CROISEMENT(Solution pere1, Solution pere2, Solution *enfant1, Solution *enfant2, int N)
/*
Rôle : réalise un croisement entre deux parents pour donner naissance à deux enfants.
	   Une position d’échange est aléatoirement fixée. La première partie du premier
	   enfant est directement obtenue à partir du premier parent. La deuxième partie
	   est obtenue en respectant l’ordre des tâches restantes comme elles apparaissent
	   dans le second parent. On fait de même pour le second enfant en inversant les
	   parents
Paramètres :
	parent1, parent2 : les deux parents pour réaliser le croisement
	enfant1, enfant2 : les deux enfants issus du croisement
	n : nombre de gènes (de tâches) dans chaque chromosone (chaque séquence)
Résultat : aucun
*/
{


int B1[NC];
int B2[NC];
int i,j,a;

for (i=0; i<N; i++)
 {
	B1[i]=pere1.lignes[i];
	B2[i]=pere2.lignes[i];
	}

a=HAS_INT(N);
for(i=0;i<a;i++) (*enfant1).lignes[i]=pere1.lignes[i];

for(i=0;i<N;i++)
  	{
   	for(j=0;j<a;j++)
	{if (B2[i]==(*enfant1).lignes[j]) B2[i]=-1;}
	}
j=a;
for(i=0;i<N;i++)
{if(B2[i]!=-1) {(*enfant1).lignes[j]=B2[i]; j++;};}


for(i=0;i<a;i++) (*enfant2).lignes[i]=pere2.lignes[i];

	for(i=0;i<N;i++)
	{
		for(j=0;j<a;j++)
		if(B1[i]==(*enfant2).lignes[j]) B1[i]=-1;
	}

j=a;
for(i=0;i<N;i++)
if(B1[i]!=-1) {(*enfant2).lignes[j]=B1[i]; j++;};



}

void MUTATION(Solution parent, Solution *enfant, int N)
/*
Rôle : muter un chromosome en un nouveau chromosome en permuttant aléatoirement
       deux positions.
Paramètres :
	parent : séquence à muter
	enfant : nouvelle séquence issue de la mutation de <parent>
	n : nombre de gènes (taille de la séquenve)
Résultat : aucun
*/
{
int i,j, aux;
	for(i=0;i<N;i++) (*enfant).lignes[i]=parent.lignes[i];
	i=HAS_INT(N); j=HAS_INT(N);
	aux=(*enfant).lignes[i];
	(*enfant).lignes[i]=(*enfant).lignes[j];
	(*enfant).lignes[j]=aux;



}


void mutation_Population(Solution *pop1, Solution *pop2, int N, int NP, int taux_mut)
{
int i,k;

for(k=0;k<taux_mut;k++)
{
    MUTATION(pop1[NP-1-k], &(pop2[NP-1-k]), N);

}
}

void crossover_Population(Solution *pop1, Solution *pop2, int N, int taux_cro)
{
int i, k;

for(k=0;k<taux_cro/2;k++)
{
    CROISEMENT(pop1[k],pop1[k+taux_cro/2], &(pop2[k]), &(pop2[k+taux_cro/2]), N);

}
}
void constuire_combinaison(int combinaison[NC][NT],int nbre_ligne_sommer,int ligne[NC],int M,int delta[NC][NT])
{
//Role:
// cette fonction construire une combinaison "combinaison" a partir de la matrice "delta".

int i;
int j;
for(i=0;i<nbre_ligne_sommer;i++)
{
    for(j=0;j<M;j++)
    {
        combinaison[i][j]=delta[ligne[i]][j];

        //printf("%d ",combinaison[i][j]);
    }
   // printf("\n");
}
}

void Afficher_duree_capteur_total(Capteur C[],double D[NC],int N,int M)
{
    //Role:
    //On met dans le tableau D  toutes les durees de vie de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("D:\n");
    for(i=0;i<N;i++)
    {
        D[i]=C[i].duree;
        printf( "%lf  ",D[i]);
    }
    printf("\n");
}
void Afficher_prix_capteur_total(Capteur C[],double P[NC],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("Prix:\n");
    for(i=0;i<N;i++)
    {
        P[i]=C[i].prix;
        printf( "%lf  ",P[i]);
    }
    printf("\n");
}
void Afficher_typesurv_capteur_total(Capteur C[],char typesurveillance[NC],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("type de surveillance:\n");
    for(i=0;i<N;i++)
    {
        typesurveillance[i]=C[i].typeSurveillance;
       printf( "%c  ",typesurveillance[i]);
    }
    printf("\n");
}
void Afficher_typesurv_target_total(Capteur C[],char typesurveillanceTarget[NT],int N,int M)
{
    //Role:
    //On met dans le tableau P touts les prix de toutes les capteurs.
    // Puis on les affiche.
    int i;
    printf("type de surveillance de chaque target:\n");
    for(i=0;i<M;i++)
    {

       printf( "%c  ",typesurveillanceTarget[i]);
    }
    printf("\n");
}


void Afficher_delta(int delta [NC][NT], int N, int M)
{
    //Role:
    //Affiche la matice delta.
    int i,j;

    printf("Delta: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
          printf("%d ",delta[i][j]);
        }
         printf("\n");
    }
}
int HAS_Float(int max)
/*
Rôle : choisir aléatoirement un entier entre 0 et max-1
Paramètres :
	max : définit la borne sup à ne pas dépasser
Résultat : le nombre choisi aléatoirement
*/
{
	float a;
	a=((float) (rand()%1000)*max/1000);
	return(a);
}

void TRIER(Solution *pop, int nbreSol)
/*
Rôle: trie une population selon les retards de ses solutions
Paramètres:
	retards : retards pour chaque solution, c'est le critère de tri
	pop : population à trier
	np : la population à trier
Résultat : aucun
*/
{
	int i,j, aux;
	Solution au;

	for(i=0;i<nbreSol-1;i++)
	{
		for(j=i+1;j<nbreSol;j++)
		if(pop[i].dureeSol<pop[j].dureeSol)
		{
		    au=pop[i]; pop[i]=pop[j]; pop[j]=au;
		}
		if(pop[i].dureeSol==pop[j].dureeSol)
		{
		   if(pop[i].prixSol>pop[j].prixSol)

		    au=pop[i]; pop[i]=pop[j]; pop[j]=au;
		}

	}
}

void affiche_combinaison(int combinaison[NC][NT],int nbre_ligne_sommer,int M)
//Role:
//Cette fonction permet d'afficher une combinaison "combinaison".
{
    int l,h;
    for(l=0;l<nbre_ligne_sommer;l++)
    {
        for(h=0;h<M;h++)
        {
            printf("%d ",combinaison[l][h]);
        }
        printf("\n");
    }
}

double timevaldiff(struct timeval *starttime, struct timeval *finishtime)
{
  double msec;

  msec=(finishtime->tv_sec-starttime->tv_sec)*1000;
  msec+=(finishtime->tv_usec-starttime->tv_usec)*1.0/1000;
  //double m =  (finishtime->tv_sec-starttime->tv_sec) + (finishtime->tv_usec-starttime->tv_usec)*1.0/1000000;
 // printf("%lf \n",msec);
  return msec;
}
int main(int argc, char *argv[])
{printf("*******1*****");
int taux_mut=10; /*j'ai défini ce taux pour éviter d'alourdir cette version de code, sinon on doit la fixer au taux des solutions qui ne sont pas bonnes*/
	int taux_cro=90;//taux de croisement
	int nbreSol=100;//npmbre de solution dans lapopulation initiale.
    int nbreGene=20;//nombre se génératon.
    Capteur C[NC];
    int delta[NC][NT];
    double D[NC];
    double P[NC];
    char typesur[NC];
    double msec;
    struct timeval start, finish;
    int N;//Nombre de capteurs.
    int M;//Nombre de targets.
    int area;
    int range;
    int prix;
    int Emax;
    int Emin;
    int average;
    float RS[NC];
    float E[NC];
    float PR[NC];
    int XS[NC];
    float YS[NC];
    float XT[NT];
    float YT[NT];
    float Distance[NC][NT];
    char survTarget[NT];
    char line[10000];
    Solution population[nbreSol];
    Solution pop_aux[nbreSol];
    Solution pop[2*nbreSol];
    int combinaison[NC][NT];
    Solution solution;

    double tab_duree[NC];//
    double tab_prix[NC];
    int tab_ID[NC];
    double dureMoyenneGeneral;
    int nbreTypSur;//Nombre de type de surveillance
    int k=0;
    int itera_generation;
    double duree_vie;//durée de vie.
    double prix_total;//prix total.
    int nbreCoverSet;//nombre de cover set.
    double max=-1;
    int ligne[NC];
    int z;
    double nbreDeSolGeneral;
    double averageenergie=0;
    double dureMin=10000;
    double averagemsec=0;
    double dureMoyenne;
    double L[200];
    int graine;
//    double averagemsec=0;
    //static const char filename2[] = "exemple10.txt";
    //static const char filename[] = "test7Heterogene.txt";
    //static const char filename[] = "exemple10.txt";
    static const char result[] = "resultGA.txt";
   //static const char filename[] = "test7Heterogene.txt";
   static const char *filename[100];
    /* fichier  pour lire les donnees */
    graine=atoi(argv[1]);

   N=atoi(argv[2]);
    M=atoi(argv[3]);
    Emax=atoi(argv[4]);
    Emin=atoi(argv[5]);
    area=atoi(argv[6]);
    range=atoi(argv[7]);
    prix=atoi(argv[8]);
    filename[0]= argv[9];
    average=atoi(argv[19]);
    dureMoyenneGeneral=0;
    //srand(graine);
    printf("*******2*****");
   FILE* fichier = NULL;
    fichier = fopen(result , "a+");
     printf("*******2*****");
    for( z=0;z<average;z++)
    { filename[0]= argv[9+z];
    //jeuxInstance(N,M,Emax,Emin,prix,PR,area,range,E,RS,XS,YS,XT,YT,Distance,filename[0]);
    lire_Data(C,&N,&M,filename[0],&survTarget,&nbreTypSur);
    printf("Nombre de capteurs:  %d\n",N);
    printf("Nombre de cibles:  %d\n",M);
    printf("\n");
    for(int j=0; j < N; j++)
    {
      averageenergie=averageenergie+C[j].duree;
    }
     averageenergie=averageenergie/N;
    Affiche(C,N,M);
    Calculer_delta(C,delta,survTarget,N,M);
    Afficher_delta(delta,N,M);
    printf(" Nombre de type de surveillance: %d\n",nbreTypSur);
    printf("\n");
    Afficher_duree_capteur_total(C,D,N,M);
    printf("\n");
    Afficher_prix_capteur_total(C,P,N,M);
    printf("\n");
    Afficher_typesurv_capteur_total(C,typesur,N,M);
    Afficher_typesurv_target_total(C,survTarget,N,M);
    printf("\n");

     gettimeofday(&start, NULL);
          for(k=0;k<N;k++)
        {
            solution.lignes[k]=k;

        }
        solution.dureeSol=0;
        solution.prixSol=0;
        solution.tailleSol=N;
        initialiserPopulation(population,solution,nbreSol,N);//construire la population initiale.

        itera_generation=0;
        nbreDeSolGeneral=0;
        dureMoyenne=0;
        while(itera_generation<nbreGene)
        {
        crossover_Population(population,pop_aux, N, taux_cro);
        mutation_Population(population,pop_aux, N,nbreSol, taux_mut);

	for(k=0;k<nbreSol;k++) pop[k]=population[k];
	for(k=0;k<nbreSol;k++) pop[k+nbreSol]=pop_aux[k];
    for(k=0;k<2*nbreSol;k++)
            {

                constuire_combinaison(combinaison,N,pop[k].lignes,M,delta);
                duree_capteur_combinaison(C,tab_duree,N,pop[k].lignes);
                prix_capteur_combinaison(C,tab_prix,N,pop[k].lignes);
                ID_capteur_combinaison(C,tab_ID,N,pop[k].lignes);
                Evaluation(tab_duree,tab_prix,tab_ID,combinaison,N,M,&prix_total,&duree_vie,&nbreCoverSet);
                pop[k].dureeSol=duree_vie;
                pop[k].prixSol=prix_total;
                dureMoyenne=dureMoyenne+pop[k].dureeSol;

                //if(pop[k].dureeSol<dureMin)  {dureMin=pop[k].dureeSol;}
            }

          nbreDeSolGeneral=nbreDeSolGeneral+(2*nbreSol);
         TRIER(pop,2*nbreSol);
         for(k=0;k<nbreSol;k++) {population[k]=pop[k];}
         itera_generation++;

        }
        gettimeofday(&finish, NULL);
        msec = timevaldiff(&start, &finish);
        dureMoyenne=dureMoyenne/nbreDeSolGeneral;
        L[z]=population[0].dureeSol;
       // printf("la duree de vie moyenne par rapport au nombre de genération est %lf",dureMoyenne);

       // printf("La durée de vie %d est: %lf \n ",z,population[0].dureeSol);
        dureMoyenneGeneral=dureMoyenneGeneral+dureMoyenne;

       // msec = msec+timevaldiff(&start, &finish);
       // printf("la duree de vie moyenne par rapport au nombre de genération est %lf",dureMoyenne);

       // printf("La durée de vie %d est: %lf \n ",z,population[0].dureeSol);
        //dureMoyenneGeneral=dureMoyenneGeneral+dureMoyenne;



}
if (fichier != NULL)
    {
     //fputs("Graine=", fichier);
     //sprintf (line, " %d;", graine);
     //fputs(line,fichier);
     fputs("Number of sensors=", fichier);
     sprintf (line, " %d;", N);
     fputs(line,fichier);
     fputs("Number of targets=", fichier);
     sprintf (line, " %d;", M);
     fputs(line,fichier);
     fputs("The average energy=", fichier);
     sprintf (line, " %f;", averageenergie);
     fputs(line,fichier);
     fputs("The number of cover set=", fichier);
     sprintf (line, " %d;", nbreCoverSet);
     fputs(line,fichier);
     fputs("The HWSN lifetime=", fichier);
     sprintf (line, " %f;", L[0]);
     fputs(line,fichier);
     fputs("The average HWSN lifetime=", fichier);
     sprintf (line, " %f;", dureMoyenneGeneral/average);
     fputs(line,fichier);
     fputs("The execution times=", fichier);
     sprintf (line, " %f;", msec/1000);
     fputs(line,fichier);
     fputs("The average=", fichier);
     sprintf (line, " %d;",average);
     fputs(line,fichier);
     fputs("\n",fichier);
     fclose(fichier);
    }
//printf("**************The Genetic Algorithm gives as result:**********************\n");
//printf("The maximum Lifetime is %lf\n",population[0].dureeSol);
//printf("The minimum Lifetime is %lf\n",dureMin);
//printf("The average lifetime is %lf\n",dureMoyenneGeneral/10);
//printf("temps d'execution =%lf seconde \n",(msec/10)/1000);


   printf("*****************The end ******************************* \n");
    printf("the  average HWSN lifetime is %lf\n",dureMoyenneGeneral/average);
    printf("The average The execution timesexecution times =%lf seconde \n",(averagemsec/average)/1000);

    return EXIT_SUCCESS;



}
