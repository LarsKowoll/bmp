/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "general.h"

#pragma pack(push,1)
typedef struct tagBITMAPFILEHEADER {
 WORD bfType;
 DWORD bfSize;
 WORD bfReserved1;
 WORD bfReserved2;
 DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct tagBITMAPINFOHEADER{
 DWORD biSize;
 LONG biWidth;
 LONG biHeight;
 WORD biPlanes;
 WORD biBitCount;
 DWORD biCompression;
 DWORD biSizeImage;
 LONG biXPelsPerMeter;
 LONG biYPelsPerMeter;
 DWORD biClrUsed;
 DWORD biClrImportant;
} BITMAPINFOHEADER, *PBITMAPINFOHEADER;
#pragma pack(pop)

//8 Bit
typedef struct tagRGBQUAD {
 unsigned char rgbBlue;
 unsigned char rgbGreen;
 unsigned char rgbRed;
 unsigned char rgbReserved;
} RGBQUAD;

//24 Bit
typedef struct tagRGBTRIPLE {
 unsigned char rgbtBlue;
 unsigned char rgbtGreen;
 unsigned char rgbtRed;
} RGBTRIPLE;



int readFile(){
    // Dateizeiger erstellen
    FILE *file; 
    // Datei oeffnen
    file = fopen("22x14_8_bit_komprimiert_mit_padding_bytes_sehr_kleines_testbild.bmp", "rb");
    if(file == NULL){
        fclose(file);
        return -1; //Falscher Dateipfad
    }

    
    //read BITMAPFILEHEADER
    BITMAPFILEHEADER bitmapFileHeader;
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    if (bitmapFileHeader.bfType != 0x4d42){
        fclose(file);
        return -1; //Falscher Datentyp
    }
    
    // Ausgabe zum Testen
    printf("bfType: %hX\n", bitmapFileHeader.bfType);
    printf("bfSize: %d\n", bitmapFileHeader.bfSize);
    printf("bfReserved1: %hX\n", bitmapFileHeader.bfReserved1);
    printf("bfReserved2: %hX\n", bitmapFileHeader.bfReserved2);
    printf("bfOffBits: %lX\n", bitmapFileHeader.bfOffBits);
        
    return 0;
    
    
}
