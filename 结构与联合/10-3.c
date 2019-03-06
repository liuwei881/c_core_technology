#include <stdio.h>
#include "songs.h"

SongList_t cloneSongList(const SongList_t *pList){
    SongList_t newSL = {NULL, NULL};

    Cell_t *pCell = pList->pFirst;
    while(pCell != NULL && appendSong(&newSL, &pCell->song)){
        pCell = pCell->pNext;
    }

    if(pCell != NULL){
        clearSongList(&newSL);
    }
    return newSL;
}

bool appendSong(SongList_t *pList, const Song_t *pSong){
    Cell_t *pCell = calloc(1, sizeof(Cell_t));

    if(pCell == NULL){
        return false;
    }

    pCell->song = *pSong;
    pCell->pNext = NULL;

    if(pList->pFirst == NULL){
        pList->pFirst = pList->pLast = pCell;
    }else{
        pList->pLast->pNext = pCell;
        pList->pLast = pCell;
    }
    return true;
}

void clearSongList(SongList_t *pList){
    Cell_t *pCell, *pNextCell;
    for(pCell = pList->pFirst; pCell != NULL; pCell=pNextCell){
        pNextCell = pCell->pNext;
        free(pCell);
    }
    pList->pFirst = pList->pLast = NULL;
}



