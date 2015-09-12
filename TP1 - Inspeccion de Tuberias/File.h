//
//  File.c
//  TP1 - Inspeccion de Tuberias
//
//  Created by Gastón Montes on 9/9/15.
//  Copyright (c) 2015 Gastón Montes. All rights reserved.
//

#ifndef FILE_H_
#define FILE_H_

#include <stdio.h>

typedef enum {
    FileOperationCodeSuccess,
    FileOperationCodeFail,
} FileOperationCode;

typedef enum {
    FileOpenModeRead,
    FileOpenModeWrite
} FileOpenMode;

typedef struct {
    FILE *file;
    FileOperationCode operation_code;
    int end_of_file;
} File;

void fileCreate(File *file, char *file_name, FileOpenMode open_mode);

void fileDestroy(File *file);

#endif /* FILE_H_ */
