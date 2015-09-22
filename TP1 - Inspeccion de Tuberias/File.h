//
//  File.h
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
    FileOpenModeReadText,
    FileOpenModeReadBinary
} FileOpenMode;

typedef struct {
    FILE *file;
    FileOpenCode openCode;
    int endOfFile;
} File;

void fileCreate(File *file, const char *fileName, FileOpenMode openMode);

void fileDestroy(File *file);

FileOpenCode fileOpenCode(File *file);

void fileReadLine(File *file, char *line, int maxLenght);

void fileRead(File *file, char *valueToRead, int bytesToRead);

int fileEndOfFile(File *file);

#endif /* FILE_H_ */
