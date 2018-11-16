/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "general.h"

typedef struct tagBITMAPFILEHEADER {
 WORD bfType;
 DWORD bfSize;
 WORD bfReserved1;
 WORD bfReserved2;
 DWORD bfOffBits;
} BITMAPFILEHEADER, *PBITMAPFILEHEADER;

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

int readFile(char* path){
    // Dateizeiger erstellen
    FILE * fp; 
    // Datei oeffnen
    fp = fopen(path, "rb");
    
    if(fp == NULL){
        return -1; //Falscher Dateipfad
    }   
    //read BITMAPFILEHEADER
    BITMAPFILEHEADER fileHeader;
    if (fileHeader.bfType != 0x424D){
        return -1; //Falscher Datentyp
    }
    
    
    
    
}
