#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    uint8_t buff[12];
    int count = 0;

    fp = fopen(argv[1], "rb");

    if(argc == 1){
        printf("Usage %s [file name]\n", argv[0]);
        return 0;
    }

    if(fp == NULL){
        printf("Cannot open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("\033[2J");
    printf("\033[H");

    while((count = fread(buff, 1, 12, fp)) > 0){
          printf("%02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X", 
                  buff[0], 
                  buff[1], 
                  buff[2], 
                  buff[3], 
                  buff[4], 
                  buff[5], 
                  buff[6], 
                  buff[7],
                  buff[8],
                  buff[9],
                  buff[10],
                  buff[11]); 
          printf(" || %c %c %c %c %c %c %c %c %c %c %c %c\n", 
                  (buff[0] == 0x0A)?0:buff[0], 
                  (buff[1] == 0x0A)?0:buff[1], 
                  (buff[2] == 0x0A)?0:buff[2], 
                  (buff[3] == 0x0A)?0:buff[3],
                  (buff[4] == 0x0A)?0:buff[4], 
                  (buff[5] == 0x0A)?0:buff[5], 
                  (buff[6] == 0x0A)?0:buff[6], 
                  (buff[7] == 0x0A)?0:buff[7], 
                  (buff[8] == 0x0A)?0:buff[8], 
                  (buff[9] == 0x0A)?0:buff[9], 
                  (buff[10] == 0x0A)?0:buff[10], 
                  (buff[11] == 0x0A)?0:buff[11]); 
          buff[0] = 0, buff[1] = 0, buff[2] = 0, buff[3] = 0, buff[4] = 0, buff[5] = 0, buff[6] = 0, buff[7] = 0, buff[8] = 0, buff[9] = 0, buff[10] = 0, buff[11] = 0;
    }

    //printf("%c ", buff[0]);

    if(feof(fp)){
        printf("Read all data OK\n");
    }else{
        printf("Data reading error\n");
    }

    fclose(fp);

    return 0;
}


