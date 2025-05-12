#include "treeman.h"
#include "queue.h"
#include <malloc.h>
#include <ctype.h>
#include <stdio.h>


/***************************/
/* S P E S I F I K A S I */
/***************************/
// Create Non Binary Tree sebanyak Jml_Node
// Tujuan mengentrykan Non Binary Tree ke array Isi_Tree dengan pola Level Order
// Jml Node adalah banyaknya elemen dalam Tree yang menjadi parameter input
void Create_Tree(Isi_Tree *X) {
    (*X).Head = nil;
}

// Mengecek apakah pohon kosong
boolean IsEmpty(Isi_Tree P) {
    return (P.Head == nil);
}

/************ TRAVERSAL ************/

void PreOrderTraversal(address P) {
    if (P != nil) {
        printf("%c ", Info(P));
        PreOrderTraversal(P->left);
        PreOrderTraversal(P->right);
    }
}

void PreOrder(Isi_Tree P) {
    PreOrderTraversal(P.Head);
}

void InOrderTraversal(address P) {
    if (P != nil) {
        InOrderTraversal(P->left);
        printf("%c ", Info(P));
        InOrderTraversal(P->right);
    }
}

address Alokasi(infotype X) {
    address P = (address) malloc(sizeof(ElmtList));
    if (P != nil) {
        P->info = X;
        P->left = nil;
        P->right = nil;
    }
    return P;
}


void InOrder(Isi_Tree P) {
    InOrderTraversal(P.Head);
}

void PostOrderTraversal(address P) {
    if (P != nil) {
        PostOrderTraversal(P->left);
        PostOrderTraversal(P->right);
        printf("%c ", Info(P));
    }
}

void PostOrder(Isi_Tree P) {
    PostOrderTraversal(P.Head);
}


void Level_order(Isi_Tree T) {
    if (T.Head == nil) return;

    Queue Q;
    initQueue(&Q);
    endQueue(&Q, T.Head);  // T.Head adalah address

    while (!isQueueEmpty(&Q)) {  // sebelumnya salah: isQueueEmpty(Q)
        address curr = deQueue(&Q);
        printf("%c ", curr->info);

        if (curr->left != nil) endQueue(&Q, curr->left);
        if (curr->right != nil) endQueue(&Q, curr->right);
    }
}

/************ UTILITIES ************/

void PrintTree(Isi_Tree P) {
    printf("PreOrder: ");
    PreOrder(P);
    printf("\n");

    printf("InOrder: ");
    InOrder(P);
    printf("\n");

    printf("PostOrder: ");
    PostOrder(P);
    printf("\n");

    printf("LevelOrder: ");
    Level_order(P);
    printf("\n");
}

boolean SearchNode(address P, infotype X) {
    if (P == nil) return false;
    if (P->info == X) return true;
    return SearchNode(P->left, X) || SearchNode(P->right, X);
}

boolean Search(Isi_Tree P, infotype X) {
    return SearchNode(P.Head, X);
}

int nbElmtNode(address P) {
    if (P == nil) return 0;
    return 1 + nbElmtNode(P->left) + nbElmtNode(P->right);
}

int nbElmt(Isi_Tree P) {
    return nbElmtNode(P.Head);
}

int nbDaunNode(address P) {
    if (P == nil) return 0;
    if (P->left == nil && P->right == nil) return 1;
    return nbDaunNode(P->left) + nbDaunNode(P->right);
}

int nbDaun(Isi_Tree P) {
    return nbDaunNode(P.Head);
}

int LevelNode(address P, infotype X, int level) {
    if (P == nil) return -1;
    if (P->info == X) return level;

    int l = LevelNode(P->left, X, level + 1);
    if (l != -1) return l;

    return LevelNode(P->right, X, level + 1);
}

int Level(Isi_Tree P, infotype X) {
    return LevelNode(P.Head, X, 0);
}

int DepthNode(address P) {
    if (P == nil) return 0;
    int leftDepth = DepthNode(P->left);
    int rightDepth = DepthNode(P->right);
    return 1 + Max(leftDepth, rightDepth);
}

int Depth(Isi_Tree P) {
    return DepthNode(P.Head);
}

int Max(infotype Data1, infotype Data2) {
    return (Data1 > Data2) ? Data1 : Data2;
}

boolean cariKodeMorse(address P, char target, char *hasil, int depth) {
    if (P == NULL) return false;

    if (P->info == toupper(target)) {
        hasil[depth] = '\0';
        return true;
    }

    // Coba kiri (.)
    hasil[depth] = '.';
    if (cariKodeMorse(P->left, target, hasil, depth + 1)) return true;

    // Coba kanan (-)
    hasil[depth] = '-';
    if (cariKodeMorse(P->right, target, hasil, depth + 1)) return true;

    // Kembali (backtrack)
    return false;
}

void getKodeMorse(Isi_Tree T, char target) {
    char hasil[10];  // asumsi morse tidak lebih dari 10 simbol
    target = toupper(target);

    if (cariKodeMorse(T.Head, target, hasil, 0)) {
        printf("%s ", hasil);
    } else {
        printf("? ");  // jika tidak ditemukan
    }
}

void konversiStringKeMorse(Isi_Tree T, const char *kalimat) {
    printf("Memulai konversi string\n");
    for (int i = 0; kalimat[i] != '\0'; i++) {
        if (kalimat[i] == ' ') {
            printf(" ..-- ");  
        } else {
            getKodeMorse(T, kalimat[i]);
        }
    }
    printf("\n");
}

void PohonMorse(Isi_Tree * T){
    printf("Kamus telah dibuat\n");
    T->Head = Alokasi('\0');
    address root = T->Head;

    //Level 1 
    root->left = Alokasi('A');
    root->right = Alokasi('B');
    
    printf("Level 1 Selesai\n");

    //Level 2

    root->left->left = Alokasi('C');
    root->left->right = Alokasi('D');
    root->right->left = Alokasi('E');
    root->right->right = Alokasi('F');
    
    printf("Level 2 Selesai\n");
    //Level 3

    root->left->left->left = Alokasi('G');
    root->left->left->right = Alokasi ('H');
    root->left->right->left = Alokasi('I');
    root->left->right->right = Alokasi('J');
    root->right->left->left = Alokasi('K');
    root->right->left->right = Alokasi('L');
    root->right->right->left = Alokasi('M');
    root->right->right->right = Alokasi('N');
    
    printf("Level 3 Selesai\n");
    //Level 4
    root->left->left->left->left = Alokasi('O');
    root->left->left->left->right = Alokasi('P');
    root->left->left->right->right = Alokasi(' ');
    root->left->right->left->left = Alokasi('Q');
    root->left->right->left->right = Alokasi('\0');
    root->left->right->right->left = Alokasi('R');
    root->left->right->right->right = Alokasi('S');
    root->right->left->left->left = Alokasi('T');
    root->right->left->left->right = Alokasi('U');
    root->right->left->right->left = Alokasi('V');
    root->right->left->right->right = Alokasi('W');
    root->right->right->left->left = Alokasi('X');
    root->right->right->left->right = Alokasi('Y');
    root->right->right->right->left = Alokasi('Z');
    root->right->right->right->right = Alokasi('\0');

    printf("Level 4 Selesai\n");
    //Level 5
    root->left->left->left->left->left = Alokasi('0');
    root->left->left->left->left->right = Alokasi('1');
    root->left->left->left->right->right = Alokasi('2');
    root->left->left->right->right->right = Alokasi('3');
    root->left->right->left->right->right = Alokasi('4');
    root->left->right->right->right->right = Alokasi('5');
    root->right->left->left->left->left = Alokasi('6');
    root->right->right->left->left->left = Alokasi('7');
    root->right->right->right->left->left = Alokasi('8');
    root->right->right->right->right->right = Alokasi('9');
 
    printf("Level 5 Selesai\n");
    printf("Pohon Selesai dibuat\n");


}

// Fungsi untuk membaca kalimat dari file
void bacaKalimatDariFile(const char *filename, char *kalimat) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Gagal membuka file %s\n", filename);
        exit(1);
    }

    // Baca kalimat dari file
    fgets(kalimat, 100, file); // Membaca sampai 100 karakter
    fclose(file);
}

// Fungsi untuk menulis hasil konversi ke file
void tulisKeFile(const char *filename, const char *morse) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Gagal membuka file %s\n", filename);
        exit(1);
    }

    fprintf(file, "%s\n", morse); // Menulis ke file
    fclose(file);
}
