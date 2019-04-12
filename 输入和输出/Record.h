//
// Created by 刘伟 on 2019/4/12.
//

#ifndef C_CORE_TECHNOLOGY_RECORD_H
#define C_CORE_TECHNOLOGY_RECORD_H

typedef struct {
    long key;
    char name[32];
} Record_t;

typedef struct {
    long key, pos;
} IndexEntry_t;
#endif //C_CORE_TECHNOLOGY_RECORD_H
