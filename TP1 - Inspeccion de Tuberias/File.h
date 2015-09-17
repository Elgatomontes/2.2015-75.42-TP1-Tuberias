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
	FileOpenCodeSuccess,
    FileOpenCodeFail,
} FileOpenCode;

typedef enum {
    FileOpenModeRead,
    FileOpenModeWrite
} FileOpenMode;

typedef struct {
    FILE *file;
    FileOpenCode open_code;
    int end_of_file;
} File;

void fileCreate(File *file, const char *file_name, FileOpenMode open_mode);

void fileDestroy(File *file);

FileOpenCode fileOpenCode(File *file);

#endif /* FILE_H_ */
