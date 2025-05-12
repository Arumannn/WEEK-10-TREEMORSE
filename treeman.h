#ifndef TREEMAN_H
#define TREEMAN_H

#include <stdio.h>
#include "boolean.h"

#define nil NULL
#define Info(P) ((P)->info)

typedef char infotype;
typedef struct tElmtList *address;

typedef struct tElmtList {
    infotype info;
    address left;
    address right;
} ElmtList;

typedef struct {
    address Head;
} Isi_Tree;

/***************************/
/* KONSTRUKTOR & UTILITAS */
/***************************/
void Create_Tree(Isi_Tree *X);
address Alokasi(infotype X);
boolean IsEmpty(Isi_Tree P);

/************ TRAVERSAL ************/
void PreOrder(Isi_Tree P);
void InOrder(Isi_Tree P);
void PostOrder(Isi_Tree P);
void Level_order(Isi_Tree P);
void PrintTree(Isi_Tree P);

/************ SEARCH ************/
boolean Search(Isi_Tree P, infotype X);

/************ FUNGSI LAIN ************/
int nbElmt(Isi_Tree P);
int nbDaun(Isi_Tree P);
int Level(Isi_Tree P, infotype X);
int Depth(Isi_Tree P);
int Max(infotype Data1, infotype Data2);

/************ MORSE FUNCTION ************/
void getKodeMorse(Isi_Tree T, char target);
/* Menampilkan kode Morse dari huruf target */

void konversiStringKeMorse(Isi_Tree T, const char *kalimat);
/* Mengonversi string menjadi Morse */

boolean cariKodeMorse(address P, char target, char *hasil, int depth);
/* Mencari rute huruf di pohon dan mengisi hasil kode Morse */

void PohonMorse(Isi_Tree *T);
/* Membentuk struktur pohon Morse */

void bacaKalimatDariFile(const char *filename, char *kalimat);
void tulisKeFile(const char *filename, const char *morse);
#endif
