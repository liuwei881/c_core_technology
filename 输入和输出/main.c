#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE 256
#define ARRAY_LEN 100

//
//_Bool isReadWriteable(const char *filename){
//    FILE* fp = fopen("./filename", "r+");
//    if(fp != NULL){
//        fclose(fp);
//        return true;
//    }else{
//        return false;
//    }
//}

//int searchFile(FILE* fpIn, const char* keyword){
//    char line[MAX_LINE] = "";
//    int count = 0;
//
//    if(fpIn == NULL || keyword == NULL){
//        return -1;
//    }else{
//        rewind(fpIn);
//    }
//
//    while(fgets(line, MAX_LINE, fpIn) != NULL){
//        if(strstr(line, keyword) != NULL){
//            ++count;
//            fputs(line, stdout);
//        }
//
//        if(!feof(fpIn)){
//            return -1;
//        }else{
//            return count;
//        }
//    }
//}

//typedef struct {
//    long key;
//    char name[32];
//} Record_t;
//
//char inFile[] = "records.dat", outFile[] = "packed.dat";
//
//static inline void error_exit(int status, const char *error_msg){
//    fputs(error_msg, stderr);
//    exit(status);
//}
//
//int main(){
//    FILE* fpIn, *fpOut;
//    Record_t record, *pArray;
//    unsigned int i;
//
//    if((fpIn = fopen(inFile, "rb")) == NULL){
//        error_exit(1, "Error on opening input file.");
//    }
//    else if((fpOut = fopen(outFile, "wb")) == NULL){
//        error_exit(2, "Error on opening output file.");
//    }
//    else{
//        if((pArray = malloc(ARRAY_LEN * sizeof(Record_t))) == NULL){
//            error_exit(3, "Insufficient memory.");
//        }
//    }
//}

#include "Record.h"

extern IndexEntry_t indexTab[];
extern int indexLen;

Record_t* setNewName(FILE* fp, long key, const char* newname) {
    static Record_t record;
    int i;
    for (i=0; i < indexLen; ++i) {
        if (key == indexTab[i].key) {
            break;
        }
    }
    if (i==indexLen) {
        return NULL;
    }
    // 将文件位置设定到该记录
    if (fseek(fp, indexTab[i].pos, SEEK_SET) != 0) {
        return NULL;
    }
    if (fread(&record, sizeof(Record_t), 1, fp) != 1) {
        return NULL;
    }
    if (key != record.key) {
        return NULL;
    } else {
        size_t size = sizeof(record.name);
        strncpy(record.name, newname, size-1);
        record.name[size-1] = '\0';

        if (fseek(fp, indexTab[i].pos, SEEK_SET) != 0) {
            return NULL;
        }
        if (fwrite(&record, sizeof(Record_t), 1, fp) != 1) {
            return NULL;
        }
        return &record;
    }
}

