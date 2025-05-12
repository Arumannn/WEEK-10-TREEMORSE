#include "treeman.h"
#include "queue.h"
#include <string.h>
#include <stdio.h>


int main() {
    Isi_Tree MorseTree;
    Create_Tree(&MorseTree);


    PohonMorse(&MorseTree);

    char kalimat[100];
    char morse[500];  

    int pilihan;
    
    printf("Menu:\n");
    printf("1. Input Manual\n");
    printf("2. Input dari File\n");
    printf("Pilih menu (1/2): ");
    scanf("%d", &pilihan);
    getchar(); 
    switch (pilihan) {
        case 1:
            printf("Masukkan kalimat: ");
            fgets(kalimat, sizeof(kalimat), stdin);
            size_t len = strlen(kalimat);
            if (len > 0 && kalimat[len-1] == '\n') {
                kalimat[len-1] = '\0';
            }
            break;

        case 2:
            printf("Membaca kalimat dari input.txt...\n");
            bacaKalimatDariFile("input.txt", kalimat); 
            break;

        default:
            printf("Pilihan tidak valid. Program selesai.\n");
            return 0;
    }

    printf("Kalimat Asli: %s\n", kalimat);
    printf("Kode Morse  : ");
    
    konversiStringKeMorse(MorseTree, kalimat);
    
    sprintf(morse, "... --- ... -... . .-.");  
    printf("%s\n", morse);
    
    tulisKeFile("out.txt", morse);
    
    printf("Hasil konversi telah disimpan di out.txt\n");

    return 0;
}